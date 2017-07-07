//
// Created by zq on 17-5-24.
//

#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>

using namespace std;
using namespace cv;

// 二值化图片
void threshold(const Mat &src, Mat &dst, double thresh, double maxval, int type)
{
    dst = src.clone();
    for(int i = 0; i < dst.cols; ++ i)
    {
        for(int j = 0; j < src.rows; ++ j)
        {
            int ans = src.at<uchar>(i, j);
            if(ans < thresh && type == THRESH_BINARY)
            {
                ans = 0;
            }
            else {
                ans = maxval;
            }
            dst.at<uchar>(i, j) = ans;
        }
    }
}

// 加水印
void encode(const Mat &binMark, Mat &dstImg, const Mat &srcImg)
{
    int x0 = 0;
    int y0 = 0;
    int x = binMark.rows;
    int y = binMark.cols;
    dstImg = srcImg.clone();
    for(int i = x0; i < x+x0; ++ i)
    {
        for(int j = y0; j < y+y0; ++ j)
        {
            bool lsb = binMark.at<uchar>(i-x0, j-y0);
            int intensity = ((srcImg.at<uchar>(i, j) & 254) | lsb);
            dstImg.at<uchar>(i, j) = (uchar)intensity;
        }
    }
}

int main(int argc, char *argv[])
{
    if(argc < 4) {
        cout << "Usage: encode <picture-file> <digits to hide> <output-file>..." << endl;
        return -1;
    }
    Mat binMark, srcMark;                // 要加的水印
    Mat srcImg;                          // 原始图片
Mat dstImg;                              // 加入水印后要保存的图片；
    srcMark = imread(argv[2], IMREAD_GRAYSCALE);
    srcImg = imread(argv[1], IMREAD_GRAYSCALE);
//    imshow("srcImg", srcImg);
    resize(srcMark, srcMark, Size(srcImg.cols*0.5, srcImg.rows*0.5));
    threshold(srcMark, binMark, 175, UCHAR_MAX, THRESH_BINARY);
//    imshow("binMark", binMark);
    waitKey(0);
    encode(binMark, dstImg, srcImg);
    imshow("result", dstImg);
    waitKey(0);
    imwrite(argv[3], dstImg);
    return 0;
}