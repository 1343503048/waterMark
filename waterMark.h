//
// Created by zq on 17-4-30.
//

#ifndef WATERMARK_WATERMARK_H
#define WATERMARK_WATERMARK_H

#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;
void loadImg(Mat &img, const char* filename);
void toBinImg(Mat &srcImg, Mat &binImg, double thresholdValue);
void show(Mat &img);
void show(Mat &img, const char *title);
void insert();
double dist(int x0, int y0, int x, int y);
int getR(const Mat &a, int i, int j);

#endif //WATERMARK_WATERMARK_H
