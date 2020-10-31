#ifndef __ARMOR_
#define __ARMOR_

// #include "../AngleSolver/include/AngleSolver.h"
#include </usr/local/include/opencv4/opencv2/opencv.hpp>
#include "math.h"

class rviz
{
public:
    rviz(rviz &male_light, rviz &female_light, float center_dis);

    float get_height();
    float get_width();
    float get_center_dis();
    float get_area();

    rviz get_left_light();
    rviz get_right_light();

    Point2f bl();
    Point2f tl();
    Point2f tr();
    Point2f br();

private:
    float height, width;
    AngleSolver lights[2];
    float center_dis;
    float Area;s
    Point2f p_tl, p_tr, p_bl, p_br;
};

RotatedRect tranform_rect(RotatedRect &rect);

double distance(Point2f p1, Point2f p2);

void getQuaternion(Mat R, double Q[]);

#endif