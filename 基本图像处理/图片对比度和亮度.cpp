
/*
g(i,j) = a*f(i,j) + b
��������a ��B һ����� ���� �� ƫ�� �����������������������������ֱ���� �Աȶ� �� ���� ��
���У� i �� j ��ʾ����λ�� ��i�� �� ��j��

*/

/*
���ǿ��Բ��� for ѭ��������ÿ�����أ�����ֱ�Ӳ�������������
image.convertTo(new_image, -1, alpha, beta);
����� convertTo ��ִ������������ new_image = a*image + beta ��
Ȼ����������չ�ַ���ÿһ�����صĹ��̣�����ѡ����forѭ���ķ�ʽ��
ʵ���ϣ������ַ�ʽ���ܷ���ͬ���Ľ����
*/

#include"stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

double alpha;  /// ���ƶԱȶ�
int beta;      /// ��������

int main()
{
	/// �����û��ṩ��ͼ��
	Mat image = imread("E:/test1.jpg");
	Mat new_image = Mat::zeros(image.size(), image.type());
	///����ֵ��ʼ��Ϊ0
	///��ԭͼ������ͬ�Ĵ�С������
	///	�� image.size() �� image.type() ����Mat�������0��ʼ����
	/// ��ʼ��
	cout << " Basic Linear Transforms " << endl;
	cout << "-------------------------" << endl;
	cout << "* Enter the �Աȶ� ֵ [1.0-3.0]: ";
	cin >> alpha;
	cout << "* Enter the ����   ֵ [-100-100]: ";
	cin >> beta;

	/// ִ������ new_image(i,j) = alpha*image(i,j) + beta

	for (int y = 0; y < image.rows; y++)
	{
		for (int x = 0; x < image.cols; x++)
		{
			for (int c = 0; c < 3; c++)
			{
				new_image.at<Vec3b>(y, x)[c] = saturate_cast<uchar>(alpha*(image.at<Vec3b>(y, x)[c]) + beta);
			}
		}
	}

	/// ��������
	namedWindow("Original Image", 1);
	namedWindow("New Image", 1);

	/// ��ʾͼ��
	imshow("Original Image", image);
	imshow("New Image", new_image);

	/// �ȴ��û�����
	waitKey();
	return 0;
}

