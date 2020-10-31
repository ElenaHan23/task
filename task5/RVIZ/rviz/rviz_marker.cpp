
#include </usr/local/include/opencv4/opencv2/opencv.hpp>
#include "../rviz/include/rviz.h"
#include "../AngleSolver/include/AngleSolver.h"
#include "../rviz/include/rviz.h"
#include "../AngleSolver/include/General.h"
#include <iostream>
#include "math.h"

using namespace std;
using namespace cv;

int main(int argc, char **argv)
{
    ros::init(argc, argv, "Armor_Shapes");
    ros::NodeHandle n;
    ros::Rate r(1);
    ros::Publisher marker_pub = n.advertise<visualization_msgs::Marker>("visualization_marker", 1);
    vector<Point3d> World_Coor = {Point3f(0, 0, 0), Point3f(0, 26.5, 0), Point3f(67.5, 26.5, 0), Point3f(67.5, 0, 0)};
    FileStorage fs2("/home/elena/桌面/task_five/src/camera.yml", FileStorage::READ);
    Mat cameraMatrix2, distCoeffs2;
    fs2["camera_matrix"] >> cameraMatrix2;
    fs2["distortion_coefficients"] >> distCoeffs2;

    Mat frame, src, dst;
    Mat c_frame[3];
    Point2f center;
    VideoCapture capture(0);
    capture.open("/home/elena/桌面/task_five/video/water.avi");

    if (!capture.isOpened())
    {
        printf("could not find video data file...\n");
        return -1;
    }

    while (ros::ok() && capture.read(frame))
    {

        split(frame, c_frame);

        src = c_frame[2] - c_frame[0];
            threshold(src, src, 80, 255, THRESH_BINARY);

        Mat element = getStructuringElement(MORPH_ELLIPSE, Size(3, 3));
        dilate(src, src, element);

        vector<vector<Point>> contours;
        findContours(src, contours, RETR_EXTERNAL, CHAIN_APPROX_SIMPLE, Point());

        RotatedRect rect;
        Point2f vertices[4];

        vector<AngleSolver> lights;

        Match_Condition MATCH_COND;

        bool flag = false;

        for (size_t i = 0; i < contours.size(); i++)
        {
            if (contourArea(contours[i]) < 80)
            {
                continue;
            }

            if (contours[i].size() > 5)
            {
                rect = fitEllipse(contours[i]);
                tranform_rect(rect);

                rect.points(vertices);

                float contour_area = contourArea(contours[i]);

                if (rect.size.width / rect.size.height > MATCH_COND.MAX_WH_RATIO || contour_area / rect.size.area() < MATCH_COND.MIN_AREA_FULL)
                    continue;
                for (int i = 0; i < 4; i++)
                {
                    line(frame, vertices[i], vertices[(i + 1) % 4], Scalar(0, 255, 0), 1);
                }
                AngleSolver = AngleSolver(rect, contourArea(contours[i]), arcLength(contours[i], true));
                AngleSolver.rect = rect;
                AngleSolver.push_back(AngleSolver);
            }
        }

        vector<rviz> Matching_Armor;

        Point2f left_light_vertices[4];
        Point2f right_light_vertices[4];

        for (auto left_light : lights)
        {
            for (auto right_light : lights)
            {
                if (left_light.get_center().x < right_light.get_center().x)
                {
            
                    float area_ratio_diff = abs(left_light.get_area() - right_light.get_area());
                    if (area_ratio_diff > left_light.get_area() * MATCH_COND.MAX_AREA_DIFF && area_ratio_diff > right_light.get_area() * MATCH_COND.MAX_AREA_DIFF)
                        continue;

                    float height_diff = abs(left_light.get_height() - right_light.get_height());
                    if (height_diff > left_light.get_height() * MATCH_COND.MAX_HEIGHT_DIFF && height_diff > right_light.get_height() * MATCH_COND.MAX_HEIGHT_DIFF)
                        continue;

                    float angle_diff = abs(left_light.get_angle() - right_light.get_angle());
                    if (angle_diff > MATCH_COND.MAX_ANGLE_DIFF)
                        continue;

                    float center_dis_diff = distance(left_light.get_center(), right_light.get_center());
                    float center_y_diff = abs(left_light.get_center().y - right_light.get_center().y);
                    float center_x_diff = abs(left_light.get_center().x - right_light.get_center().x);

                    Matching_Armor.push_back(Armor(left_light, right_light, center_dis_diff));
                }
            }
        }

        int min_index = 0;
        float min_dis, max_area;

        Mat rvec, tvec, R;
        double q[4];

        if (Matching_Armor.size() >= 1)
        {
            for (int i = 0; i < Matching_Armor.size(); i++)
            {
                flag = true;
                vector<Point2d> Img_Coor;
                Img_Coor.push_back(Matching_Armor[i].bl());
                Img_Coor.push_back(Matching_Armor[i].tl());
                Img_Coor.push_back(Matching_Armor[i].tr());
                Img_Coor.push_back(Matching_Armor[i].br());

                solvePnP(World_Coor, Img_Coor, cameraMatrix2, distCoeffs2, rvec, tvec);
                Rodrigues(rvec, R);
                double Z = tvec.at<double>(2);
                if (i == 0)
                {
                    min_dis = Z;
                    min_index = i;
                }
                if (Z < min_dis)
                {
                    min_dis = Z;
                    min_index = i;
                }

                float mean_area = (Matching_Armor[i].get_left_light().get_area() + Matching_Armor[i].get_right_light().get_area()) / 2;
                if (i == 0)
                {
                    max_area = mean_area;
                }
                else
                {
                    if (mean_area > max_area)
                    {
                        max_area = mean_area;
                    }
                }
            }
            if (flag)
            {
                for (int i = 0; i < Matching_Armor.size(); i++)
                {
                    if (i == 0)
                    {
                        min_dis = Matching_Armor[i].get_center_dis();
                    }
                    float mean_area = (Matching_Armor[i].get_left_light().get_area() + Matching_Armor[i].get_right_light().get_area()) / 2;

                    if (abs(mean_area - max_area) / max_area < 0.1)
                    {
               
                        if (Matching_Armor[i].get_center_dis() < min_dis)
                        {
                            min_dis = Matching_Armor[i].get_center_dis();
                            min_index = i;
                        }
                    }
                }
            }
        }

        if (flag)
        {
            AngleSolver aim_left_light, aim_right_light;
            aim_left_light = Matching_Armor[min_index].get_left_light();
            aim_right_light = Matching_Armor[min_index].get_right_light();

            aim_left_light.rect.points(left_light_vertices);
            aim_right_light.rect.points(right_light_vertices);

            for (int i = 0; i < 4; i++)
                line(frame, left_light_vertices[i], left_light_vertices[(i + 1) % 4], Scalar(0, 0, 255), 2, 8, 0);
            for (int i = 0; i < 4; i++)
                line(frame, right_light_vertices[i], right_light_vertices[(i + 1) % 4], Scalar(0, 0, 255), 2, 8, 0);

            line(frame, aim_left_light.rect.center, aim_right_light.rect.center, Scalar(255, 255, 255), 2, 8, 0);
            center = Point2f((aim_left_light.rect.center.x + aim_right_light.rect.center.x) / 2, (aim_left_light.rect.center.y + aim_right_light.rect.center.y) / 2);
            circle(frame, center, 3, Scalar(0, 0, 255), -1, 8, 0);
        }

        visualization_msgs::Marker marker;
        marker.ns = "Armor_Shapes";
        marker.id = 0;

        marker.type = visualization_msgs::Marker::CUBE;

        marker.action = visualization_msgs::Marker::ADD;

        marker.pose.position.x = (tvec.at<_Float64>(0) - 10) / 100.0;
        marker.pose.position.y = (tvec.at<_Float64>(1) - 10) / 100.0;
        marker.pose.position.z = tvec.at<_Float64>(2) / 1000.0;

        marker.pose.orientation.x = q[0];
        marker.pose.orientation.y = q[1];
        marker.pose.orientation.z = q[2];
        marker.pose.orientation.w = q[3];

        marker.color.r = 1.0;
        marker.color.g = 0.0;
        marker.color.b = 0.0;
        marker.color.a = 1.0;

        marker.scale.x = 0.675;
        marker.scale.y = 0.05;
        marker.scale.z = 0.265;

        marker.lifetime = ros::Duration();

        while (marker_pub.getNumSubscribers() < 1)
        {
            if (!ros::ok())
            {
                return 0;
            }
            sleep(1);
        }
        marker_pub.publish(marker);
        imshow("window", frame);

        if (waitKey(30) == 27)
        {
            if (waitKey(0) == 27)
            {
                break;
            }
        }
    }
}