#include "waterMark.h"

int main() {
    const char* src = "../lena.jpg";
    const char* dst = "../dst.jpg";
    const char* mark = "../h55.jpg";
    Mat srcImg;
    Mat binImg;
    Mat srcMark;
    Mat binMark;
    srcImg = imread(src, IMREAD_GRAYSCALE);
    srcMark = imread(mark, IMREAD_GRAYSCALE);
//    imshow("gray", srcImg);
//    cout << format(srcImg, Formatter::FMT_NUMPY) << endl;
    threshold(srcImg, binImg, 115, UCHAR_MAX, THRESH_BINARY);
    threshold(srcMark, binMark, 175, UCHAR_MAX, THRESH_BINARY);
    namedWindow("bin");
    imshow("bin", binImg);
    double k = 0.5;
    resize(binMark, binMark, Size(binMark.cols*k, binMark.rows*k));
    namedWindow("mark");
    imshow("mark", binMark);

    Mat imgRoi = binImg(Rect_(300, 300, binMark.cols, binMark.rows));

    cout << "img size = " << binImg.rows << " x " << binImg.cols << " x " << binImg.channels() << endl;
    cout << "mark size = " << binMark.rows << " x " << binMark.cols << " x " << binMark.channels() << endl;
    waitKey(0);
    return 0;
}