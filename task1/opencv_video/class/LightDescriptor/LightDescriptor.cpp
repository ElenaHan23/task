#include "./include/LightDescriptor.h"

using namespace std;
using namespace cv;



LightDescriptor::LightDescriptor(){
	lightRect = RotatedRect();
	length = 0;
	center = Point2f();
	angle = 0;
}

int LightBar(const cv::RotatedRect &light)
{
	LightDescriptor lightdescriptor;
	this->lightRect = lightRect;
	lightdescriptor.length= MAX(lightRect.size.height, lightRect.size.width);
	lightdescriptor.center = lightRect.center;
	if (lightRect.angle > 90)
		lightdescriptor.angle = lightRect.angle - 180;
	else
		lightdescriptor.angle = lightRect.angle;
}
LightDescriptor::LightDescriptor(){}