#ifndef __LIGHTDESCRIPTOR_
#define __LIGHTDESCRIPTOR_

#include <opencv2/opencv.hpp>

using namespace cv;

class LightDescriptor
    {
    public:
        LightDescriptor(){};
        int LightBar(const cv::RotatedRect &light);
        LightDescriptor(const RotatedRect &light)
        {
            width = light.size.width;
            length = light.size.height;
            center = light.center;
            angle = light.angle;
            area = light.size.area();
        }
        const LightDescriptor &operator=(const LightDescriptor &ld)
        {
            this->width = ld.width;
            this->length = ld.length;
            this->center = ld.center;
            this->angle = ld.angle;
            this->area = ld.area;
            return *this;
        }

        cv::RotatedRect rec() const
        {
            return RotatedRect(center, Size2f(width, length), angle);
        }

    public:
        float width;
        float length;
        cv::Point2f center;
        float angle;
        float area;
        RotatedRect lightRect;
    };

#endif