#include"stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat image = imread("E:/皮卡丘.jpg");
	namedWindow("测试图片");
	imshow("测试", image);
	waitKey(6000);
	return 0;
}
/*
#include"stdafx.h"
#include <opencv2\opencv.hpp>
int main() {
	cv::Mat img = cv::imread("E:/test1.jpg");//替换成你的图片路径
	cv::imshow("test", img);
	cv::waitKey(0);
	return 0;
	//使用此种方法会显示warning：fopen usafe 需要改为 fopen_s
	//已在工程属性中添加_CRT_SECURE_NO_WARNINGS解决问题但这是不安全的
}
*/
