//
// Created by zq on 17-4-30.
//

#include "waterMark.h"

// 以灰度图像模式读入图像
void loadImg(Mat &img, const char *filename) {
    img = imread(filename, IMREAD_GRAYSCALE);
    if(!img.data) {
        perror("load image error!\n");
    }
}

// 转化为二值图像
void toBinImg(Mat &srcImg, Mat &binImg, double thresholdValue){
    threshold(srcImg, binImg, thresholdValue, UCHAR_MAX, THRESH_BINARY);
}

void show(Mat &img, const char* title) {
    namedWindow(title);
    imshow(title, img);
    waitKey(0);
}

int getR(const Mat &a, int x, int y) {
    int ans = 0;
    int r1 = 0, r2 = 0, r3 = 0, r4 = 0;
    for(int i = x; i < x + 3; ++ i) {
        uchar* data = (uchar *) a.ptr<uchar>(i);
        for(int j = y; j < y + 3; ++ j) {
            if(data[j] == 0) {     //黑色像素
                r1 ++;
            }
        }
        for(int j = y+1; j < y + 4; ++ j) {
            if(data[j] == 0) {     //黑色像素
                r2 ++;
            }
        }
    }
    for(int i = x+1; i < x + 4; ++ i) {
        uchar* data = (uchar *) a.ptr<uchar>(i);
        for(int j = y; j < y + 3; ++ j) {
            if(data[j] == 0) {     //黑色像素
                r3 ++;
            }
        }
        for(int j = y+1; j < y + 4; ++ j) {
            if(data[j] == 0) {     //黑色像素
                r4 ++;
            }
        }
    }
    ans += r1 ^ 1;
    ans += r2 ^ 1;
    ans += r3 ^ 1;
    ans += r4 ^ 1;
    return ans;
}

double dist(int x0, int y0, int x, int y) {
    double ans =0.0;
}
