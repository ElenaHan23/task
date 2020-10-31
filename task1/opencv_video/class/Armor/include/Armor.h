
#ifndef ARMOR
#define ARMOR

#include <opencv2/opencv.hpp>
#include <array>
#include <opencv2/ml.hpp>
// #include "../../LightDescriptor/include/LightDescriptor.h"
#define SHOW_RESULT

namespace rm
{

    struct ArmorParam
    {

        int brightness_threshold;//亮度图二值化阈值
        int color_threshold;//通道相减的colorImg使用的二值化阈值
        float light_color_detect_extend_ratio;

        float light_min_area;//灯条允许的最小面积
        float light_max_angle;
        float light_min_size;
        float light_contour_min_solidity;
        float light_max_ratio;

        float light_max_angle_diff_;
        float light_max_height_diff_ratio_; // 两个灯条之间允许的最大长度差比值
        float light_max_y_diff_ratio_; 
        float light_min_x_diff_ratio_;

        float armor_big_armor_ratio;
        float armor_small_armor_ratio;
        float armor_min_aspect_ratio_;
        float armor_max_aspect_ratio_;

   
        float sight_offset_normalized_base;
        float area_normalized_base;
        int enemy_color;
        int max_track_num = 3000;

        ArmorParam()
        {
            //pre-treatment
            brightness_threshold = 210;
            color_threshold = 40;
            light_color_detect_extend_ratio = 1.1;

            // Filter lights
            light_min_area = 10;
            light_max_angle = 45.0;
            light_min_size = 5.0;
            light_contour_min_solidity = 0.5;
            light_max_ratio = 1.0;

            // Filter pairs
            light_max_angle_diff_ = 7.0;        //20
            light_max_height_diff_ratio_ = 0.2; //0.5
            light_max_y_diff_ratio_ = 2.0;      //100
            light_min_x_diff_ratio_ = 0.5;      //100

            // Filter armor
            armor_big_armor_ratio = 3.2;
            armor_small_armor_ratio = 2;
            //armor_max_height_ = 100.0;
            //armor_max_angle_ = 30.0;
            armor_min_aspect_ratio_ = 1.0;
            armor_max_aspect_ratio_ = 5.0;

            //other params
            sight_offset_normalized_base = 200;
            area_normalized_base = 1000;
            // enemy_color = BLUE;
        }
    };

   
    class ArmorDescriptor
    {
    public:
        ArmorDescriptor();

        ArmorDescriptor(const LightDescriptor &lLight, const LightDescriptor &rLight, const int armorType, const cv::Mat &srcImg, const float rotationScore, ArmorParam param);

        void clear()
        {
            rotationScore = 0;
            sizeScore = 0;
            distScore = 0;
            finalScore = 0;
            for (int i = 0; i < 4; i++)
            {
                vertex[i] = cv::Point2f(0, 0);
            }
            // type = UNKNOWN_ARMOR;
        }

        void getFrontImg(const cv::Mat &grayImg);

        bool isArmorPattern() const;

    public:
        std::array<cv::RotatedRect, 2> lightPairs;
        float sizeScore;
        float distScore;
        float rotationScore;
        float finalScore;

        std::vector<cv::Point2f> vertex;
        cv::Mat frontImg;

        int type;
    };

    class ArmorDetector
    {
    public:
        enum ArmorFlag
        {
            ARMOR_NO = 0,
            ARMOR_LOST = 1,
            ARMOR_GLOBAL = 2,
            ARMOR_LOCAL = 3
        };

    public:
        ArmorDetector();
        ArmorDetector(const ArmorParam &armorParam);
        ~ArmorDetector() {}

        void init(const ArmorParam &armorParam);

        void setEnemyColor(int enemy_color)
        {
            _enemy_color = enemy_color;
            // _self_color = enemy_color == BLUE ? RED : BLUE;
        }

        void loadImg(const cv::Mat &srcImg);

        int detect();

        const std::vector<cv::Point2f> getArmorVertex() const;
        int getArmorType() const;

#if defined(DEBUG_DETECTION) || defined(SHOW_RESULT)
        void showDebugImg() const;
#endif

    private:
        ArmorParam _param;
        int _enemy_color;
        int _self_color;

        cv::Rect _roi; //relative coordinates

        cv::Mat _srcImg;  //source img
        cv::Mat _roiImg;  //roi from the result of last frame
        cv::Mat _grayImg; //gray img of roi

        int _trackCnt = 0;

        std::vector<ArmorDescriptor> _armors;

        ArmorDescriptor _targetArmor; //relative coordinates

        int _flag;
        bool _isTracking;

#if defined(DEBUG_DETECTION) || defined(SHOW_RESULT)
        std::string _debugWindowName;
        cv::Mat _debugImg;
#endif 

#ifdef GET_ARMOR_PIC
        int _allCnt = 0;
#endif // GET_ARMOR_PIC
    };

} // namespace rm

#endif 
