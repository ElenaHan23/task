#include "./include/LightDescriptor.h"

using namespace std;
using namespace cv;

LightDescriptor::LightDescriptor(){
	lightRect = RotatedRect();
	length = 0;
	center = Point2f();
	angle = 0;
}

LightDescriptor::LightDescriptor(const cv::RotatedRect &light)
{
	this->lightRect = lightRect;
	length = MAX(lightRect.size.height, lightRect.size.width);
	center = lightRect.center;
	if (lightRect.angle > 90)
		angle = lightRect.angle - 180;
	else
		angle = lightRect.angle;
}
LightDescriptor::LightDescriptor(){}