#include "include/rviz.h"
#include "../AngleSolver/include/AngleSolver.h"
#include </usr/local/include/opencv4/opencv2/opencv.hpp>
#include "math.h"

rviz::rviz(AngleSolver &left_light, AngleSolver &right_light, float center_dis)
{
    Point2f left_light_vertices[4];
    Point2f right_light_vertices[4]; 

    left_light.rect.points(left_light_vertices);
    right_light.rect.points(right_light_vertices);

    this->height = (left_light.get_height() + right_light.get_height()) / 2;
    this->width = abs(left_light.get_center().x - right_light.get_center().x) + left_light.get_width();
    this->lights[0] = left_light;
    this->lights[1] = right_light;
    this->center_dis = center_dis;
    this->p_bl = left_light_vertices[0];
    this->p_tl = left_light_vertices[1];
    this->p_tr = right_light_vertices[2];
    this->p_br = right_light_vertices[3];
    this->Area = this->height * this->width;
}

float rviz::get_height()
{
    return this->height;
}

float rviz::get_width()
{
    return this->width;
}
float rviz::get_center_dis()
{
    return this->center_dis;
}

AngleSolver rviz::get_left_light()
{
    return this->lights[0];
}

AngleSolver rviz::get_right_light()
{
    return this->lights[1];
}

float rviz::get_area()
{
    return this->Area;
}

Point2f rviz::bl()
{
    return this->p_bl;
}
Point2f rviz::tl()
{
    return this->p_tl;
}

Point2f rviz::tr()
{
    return this->p_tr;
}
Point2f rviz::br()
{
    return this->p_br;
}

double distance(Point2f p1, Point2f p2)
{
    return sqrt(pow((p1.x - p2.x), 2) + pow((p1.y - p2.y), 2));
}

RotatedRect tranform_rect(RotatedRect &rect)
{
    float &width = rect.size.width;
    float &height = rect.size.height;
    float &angle = rect.angle;

    if (angle >= 90.0)
        angle -= 180.0;
    if (angle < -90.0)
        angle += 180.0;

    if (angle >= 45.0)
    {
        swap(width, height);
        angle -= 90.0;
    }
    else if (angle < -45.0)
    {
        swap(width, height);
        angle += 90.0;
    }

    return rect;
}

void getQuaternion(Mat R, double Q[])
{
    double trace = R.at<double>(0,0) + R.at<double>(1,1) + R.at<double>(2,2);
 
    if (trace > 0.0) 
    {
        double s = sqrt(trace + 1.0);
        Q[3] = (s * 0.5);
        s = 0.5 / s;
        Q[0] = ((R.at<double>(2,1) - R.at<double>(1,2)) * s);
        Q[1] = ((R.at<double>(0,2) - R.at<double>(2,0)) * s);
        Q[2] = ((R.at<double>(1,0) - R.at<double>(0,1)) * s);
    } 
    
    else 
    {
        int i = R.at<double>(0,0) < R.at<double>(1,1) ? (R.at<double>(1,1) < R.at<double>(2,2) ? 2 : 1) : (R.at<double>(0,0) < R.at<double>(2,2) ? 2 : 0); 
        int j = (i + 1) % 3;  
        int k = (i + 2) % 3;

        double s = sqrt(R.at<double>(i, i) - R.at<double>(j,j) - R.at<double>(k,k) + 1.0);
        Q[i] = s * 0.5;
        s = 0.5 / s;

        Q[3] = (R.at<double>(k,j) - R.at<double>(j,k)) * s;
        Q[j] = (R.at<double>(j,i) + R.at<double>(i,j)) * s;
        Q[k] = (R.at<double>(k,i) + R.at<double>(i,k)) * s;
    }
}