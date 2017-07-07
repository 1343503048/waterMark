//
// Created by zq on 17-4-30.
//
#include "waterMark.h"
#include <iostream>
#include <cctype>
using namespace std;
const int rmin = 2;
const int rmax = 8;
const int N = 10000;

Mat srcImg;
Mat binImg;
Mat srcMark;
Mat binMark;
Mat dstImg;

void encode() {
    int x0 = 0;
    int y0 = 0;
    int x = binMark.rows;
    int y = binMark.cols;
    dstImg = srcImg.clone();
    imshow("mark", binMark);
    for(int i = x0; i < x+x0; ++ i) {
        for(int j = y0; j < y+y0; ++ j) {
            bool lsb = binMark.at<uchar>(i-x0, j-y0);
            int intensity = ((srcImg.at<uchar>(i, j) & 254) | lsb);
            dstImg.at<uchar>(i, j) = (uchar)intensity;
//            cout << (int)dstImg.at<uchar>(i, j) << "-" << intensity << endl;
        }
    }
    const char *result = "../result.bmp";
    cout << imwrite(result, dstImg) << endl;
    imshow("result", dstImg);
}

void decode() {
    int x0 = 0;
    int y0 = 0;
    int x = binMark.rows;
    int y = binMark.cols;
    cout << x << ", " << y << endl;
    binMark = Mat::zeros(x, y, CV_8UC(1));
    dstImg = imread("../result.bmp", IMREAD_UNCHANGED);
    imshow("src", dstImg);
    for(int i = x0; i < x+x0; ++ i) {
        for(int j = y0; j < y+y0; ++ j) {
            bool intensity = (dstImg.at<uchar>(i, j) & 1);
            binMark.at<uchar>(i - x0, j - y0) = intensity * UCHAR_MAX;
        }
    }
    const char *result = "../decode.jpg";
    cout << imwrite(result, binMark) << endl;
    imshow("watermark", binMark);
}

int main(int argc, char *argv[]) {
    const char* src = "1.bmp";
    const char* dst = "../h55.jpg";
    const char* mark = "../h55.jpg";

    srcImg = imread(src, IMREAD_GRAYSCALE);
    srcMark = imread(mark, IMREAD_GRAYSCALE);
    cout << srcImg.cols << " " << srcImg.rows << endl;
    imshow("hi", srcImg);
//    threshold(srcMark, binMark, 175, UCHAR_MAX, THRESH_BINARY);
//    double k = 0.5;
//    resize(binMark, binMark, Size(binMark.cols * k, binMark.rows * k));
//    encode();
//    decode();
    waitKey(0);
    return 0;
}