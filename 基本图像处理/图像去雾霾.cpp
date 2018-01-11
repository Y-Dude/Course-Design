// ͼ��ȥ����.cpp : �������̨Ӧ�ó������ڵ㡣
//ȥ��

//���¾���������̣�

//1.��ͼ��ͨ��

//2.���ð�ͨ�������������

//3.���ð�ͨ�����ƴ�����

//4.������ͼ��ʽȥ��

#include "stdafx.h"
#include<opencv2\core\core.hpp>
#include<opencv2\highgui\highgui.hpp>
#include<opencv2\imgproc\imgproc.hpp>
#include<iostream>
#include<vector>
#include <algorithm>

using namespace cv;
using namespace std;

//��ͨ��
Mat darkChannel(Mat src)
{
	Mat rgbmin = Mat::zeros(src.rows, src.cols, CV_8UC1);
	Mat dark = Mat::zeros(src.rows, src.cols, CV_8UC1);
	Vec3b intensity;

	for (int m = 0; m<src.rows; m++)
	{
		for (int n = 0; n<src.cols; n++)
		{
			intensity = src.at<Vec3b>(m, n);
			rgbmin.at<uchar>(m, n) = min(min(intensity.val[0], intensity.val[1]), intensity.val[2]);
		}
	}

	//ģ��ߴ�
	int scale = 7;
	//cout << "Please enter the mask scale: " << endl;
	//cin >> scale;

	//�߽�����
	int radius = (scale - 1) / 2;
	Mat border;
	//����Ҫ����Сֵ����������ı߽�����ø��Ʊ߽����
	copyMakeBorder(rgbmin, border, radius, radius, radius, radius, BORDER_REPLICATE);

	//��Сֵ�˲�
	for (int i = 0; i < src.cols; i++)
	{
		for (int j = 0; j < src.rows; j++)
		{
			//ѡȡ��Ȥ����
			Mat roi;
			roi = border(Rect(i, j, scale, scale));

			//����Ȥ�������Сֵ
			double minVal = 0; double maxVal = 0;
			Point minLoc = 0; Point maxLoc = 0;
			minMaxLoc(roi, &minVal, &maxVal, &minLoc, &maxLoc, noArray());

			dark.at<uchar>(Point(i, j)) = (uchar)minVal;
		}
	}
	return dark;
}

uchar light(vector<uchar> inputIamgeMax)
{
	uchar maxA = 0;
	for (int i = 0; i < inputIamgeMax.size() - 1; i++)
	{

		if (maxA < inputIamgeMax[i + 1])
		{
			maxA = inputIamgeMax[i + 1];
		}
	}
	return maxA;
}

//Mat dark(Mat image)
//{
//	Mat minColor(image.rows, image.cols, CV_8UC1, Scalar(180, 120, 50));
//	Mat darkChannel(image.rows, image.cols, CV_8UC1, Scalar(180, 120, 50));
//
//	//��ÿ������BGR��ͨ����Сֵ
//	for (int i = 0; i < image.cols; i++)
//	{
//		for (int j = 0; j < image.rows; j++)
//		{
//			uchar blue, green, red;
//			blue = image.at<Vec3b>(Point(i, j))[0];
//			green = image.at<Vec3b>(Point(i, j))[1];
//			red = image.at<Vec3b>(Point(i, j))[2];
//			minColor.at<uchar>(Point(i, j)) = minBGR(blue, green, red);
//		}
//	}
//
//	//ģ��ߴ�
//	int scale;
//	cout << "Please enter the mask scale: " << endl;
//	cin >> scale;
//
//	//�߽�����
//	int radius = (scale - 1) / 2;
//	Mat border;
//	//����Ҫ����Сֵ����������ı߽�����ø��Ʊ߽����
//	copyMakeBorder(minColor, border, radius, radius, radius, radius, BORDER_REPLICATE);
//
//	//��Сֵ�˲�
//	for (int i = 0; i < image.cols; i++)
//	{
//		for (int j = 0; j < image.rows; j++)
//		{
//			//ѡȡ��Ȥ����
//			Mat roi;
//			roi = border(Rect(i, j, scale, scale));
//
//			//����Ȥ�������Сֵ
//			double minVal = 0; double maxVal = 0;
//			Point minLoc = 0; Point maxLoc = 0;
//			minMaxLoc(roi, &minVal, &maxVal, &minLoc, &maxLoc, noArray());
//
//			darkChannel.at<uchar>(Point(i, j)) = (uchar)minVal;
//		}
//	}
//	return darkChannel;
//}

int main(int argc, char* argv[])

{
	Mat image = imread("E:/����.jpg");
	imshow("ԭͼ", image);
	Mat darkChannel1 = darkChannel(image);

	imshow("��ͨ��ͼ", darkChannel1);

	//namedWindow("dehazed");

	//���ƴ�����
	Mat temp; 
	darkChannel1.copyTo(temp);
	vector<Point> darkMaxPoint;
	vector<uchar> inputMax;
	for (long i = 0; i < ((darkChannel1.rows*darkChannel1.cols) / 1000); i++)
	{
		double minVal = 0; double maxVal = 0;
		Point minLoc = 0; Point maxLoc = 0;
		minMaxLoc(temp, &minVal, &maxVal, &minLoc, &maxLoc, noArray());

		darkMaxPoint.push_back(maxLoc);
		inputMax.push_back(image.at<uchar>(maxLoc));
		circle(temp, maxLoc, 5, Scalar(0), 1, 8, 0);
		temp.at<uchar>(maxLoc) = temp.at<uchar>(minLoc);
	}

	uchar A = light(inputMax);

	double w = 0.65;

	//createTrackbar("w1", "dehazed", &w1, 100, NULL);

	//��������
	Mat T = Mat::zeros(image.rows, image.cols, CV_8UC3);
	Scalar intensity;

	for (int m = 0; m<image.rows; m++)
	{
		for (int n = 0; n<image.cols; n++)
		{
			intensity = darkChannel1.at<uchar>(m, n);
			T.at<Vec3b>(m, n)[0] = (1 - w * intensity.val[0] / A) * 255;
			T.at<Vec3b>(m, n)[1] = (1 - w * intensity.val[0] / A) * 255;
			T.at<Vec3b>(m, n)[2] = (1 - w * intensity.val[0] / A) * 255;
		}
	}

	imshow("͸��ͼ",T);


	//ȥ��
	Mat J(image.rows, image.cols, CV_8UC3, Scalar(180, 120, 50));
	Mat temp1(image.rows, image.cols, CV_8UC3, Scalar(180, 120, 50));

	//subtract(image, Scalar(A, A, A), temp1);
	temp1 = abs(image - Scalar(A, A, A));
	double t0 = 0.1;

	Scalar T1;
	Vec3b intsrc;
	for (int i = 0; i < image.cols; i++)
	{
		for (int j = 0; j < image.rows; j++)
		{
			T1 = T.at<uchar>(Point(i, j));
			intsrc = image.at<Vec3b>(Point(i, j));
			double tmax = (T1.val[0] / 255) < t0 ? t0 : (T1.val[0] / 255);

			for (int k = 0; k < 3; k++)
			{
				J.at<Vec3b>(Point(i, j))[k] = abs((intsrc.val[k] - A) / tmax + A) > 255 ? 255 : abs((intsrc.val[k] - A) / tmax + A);
			}
		}
	}

	imshow("ȥ������", J);
	while (char(waitKey(1)) != 'q') {}
	return 0;
}

