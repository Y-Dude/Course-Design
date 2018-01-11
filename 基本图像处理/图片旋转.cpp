/*
�����÷���任����warpAffine��ʵ�ֵģ�
�˺���Ŀǰ֧��4�ֲ�ֵ�㷨������ڡ�˫���ԡ�˫���Ρ�����˹��ֵ�� ����ԭ�ͣ�
void warpAffine(InputArray src, OutputArray dst,
InputArray M, Size dsize, int flags=INTER_LINEAR,
int borderMode=BORDER_CONSTANT, const Scalar& borderValue=Scalar())
warpAffine(img, img_rotate, map_matrix, Size(width_rotate, height_rotate), 1, 0, 0);
*/

#include"stdafx.h"
#include "cv.h"                             //  OpenCV �ļ�ͷ
#include "highgui.h"
#include "cvaux.h"
#include "cxcore.h"
#include "opencv2/opencv.hpp"
#include "opencv2/imgproc.hpp"
#include <iostream>
#include <string>
using namespace cv;
using namespace std;
Mat rotateImage1(Mat img, int degree)
{
	degree = -degree;
	double angle = degree  * CV_PI / 180.; // ����
	double a = sin(angle), b = cos(angle);
	int width = img.cols;
	int height = img.rows;
	int width_rotate = int(height * fabs(a) + width * fabs(b));
	int height_rotate = int(width * fabs(a) + height * fabs(b));
	//��ת����map
	// [ m0  m1  m2 ] ===>  [ A11  A12   b1 ]
	// [ m3  m4  m5 ] ===>  [ A21  A22   b2 ]
	float map[6];
	Mat map_matrix = Mat(2, 3, CV_32F, map);
	// ��ת����
	CvPoint2D32f center = cvPoint2D32f(width / 2, height / 2);
	CvMat map_matrix2 = map_matrix;
	cv2DRotationMatrix(center, degree, 1.0, &map_matrix2);
	map[2] += (width_rotate - width) / 2;
	map[5] += (height_rotate - height) / 2;
	Mat img_rotate;
	//��ͼ��������任
	//CV_WARP_FILL_OUTLIERS - ����������ͼ������ء�
	//�������������������ͼ��ı߽��⣬��ô���ǵ�ֵ�趨Ϊ fillval.
	//CV_WARP_INVERSE_MAP - ָ�� map_matrix �����ͼ������ͼ��ķ��任��
	warpAffine(img, img_rotate, map_matrix, Size(width_rotate, height_rotate), 1, 0, 0);
	return img_rotate;
}
int main(int argc, char *argv[])
{
	int degree;
	Mat m_SrcImg;
	m_SrcImg = imread("E:/test1.jpg");
	namedWindow("ԭͼ��", 1);
	imshow("ԭͼ��", m_SrcImg);
	waitKey(0);
	cout << "��������ת�Ķ�����";
	cin >> degree;
	Mat m_ResImg = rotateImage1(m_SrcImg, degree);
	namedWindow("��ת��ͼ��", 1);
	imshow("��ת��ͼ��", m_ResImg);
	waitKey(0);
}

