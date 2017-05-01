//
// Created by zq on 17-4-30.
//

#ifndef WATERMARK_WATERMARK_H
#define WATERMARK_WATERMARK_H

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

class waterMark {
public:
    waterMark();
    waterMark(const waterMark&);
    void loadImg(const char* filename);
    void loadBinImg(const char* wmFilename);
    void toBinImg();
    ~waterMark();
private:
    Mat srcImg;
    Mat binImg;     // 二值图像
    Mat wmImg;
    Mat wmBinImg;
};


#endif //WATERMARK_WATERMARK_H
