#include"stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
	Mat image = imread("E:/Ƥ����.jpg");
	namedWindow("����ͼƬ");
	imshow("����", image);
	waitKey(6000);
	return 0;
}
/*
#include"stdafx.h"
#include <opencv2\opencv.hpp>
int main() {
	cv::Mat img = cv::imread("E:/test1.jpg");//�滻�����ͼƬ·��
	cv::imshow("test", img);
	cv::waitKey(0);
	return 0;
	//ʹ�ô��ַ�������ʾwarning��fopen usafe ��Ҫ��Ϊ fopen_s
	//���ڹ������������_CRT_SECURE_NO_WARNINGS������⵫���ǲ���ȫ��
}
*/
