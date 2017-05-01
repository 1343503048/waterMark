//
// Created by zq on 17-4-30.
//

#include "waterMark.h"

void waterMark::loadImg(const char *filename) {
    srcImg = imread(filename, IMREAD_GRAYSCALE);
    if(!srcImg.data) {
        sprintf(stderr, "load image error!\n");
    }
}

void waterMark::toBinImg() {
    threshold(srcImg, binImg, 125, UCHAR_MAX, THRESH_BINARY);
}