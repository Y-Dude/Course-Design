#include "stdafx.h"
#include "cv.h"
#include <cxcore.h>
#include <highgui.h>


int main(int argc, _TCHAR* argv[])
{
	//��ͼ���ļ��������ڴ� ����ͼ�����ݽṹ����Ҫ���ڿ� ����һ��ָ�����ݽṹIplImage���ڴ�飺
	IplImage *img = cvLoadImage("E:/test1.jpg");
	//��Ҫ�����ͼƬ�������project���棬�����ҵģ�&user name\Documents\Visual Studio 2010\Projects\opencvhello\opencvhello�ļ�������
	//�����������ڣ����ɴ�С����������HighGUI���ṩ���ڶ����������Ϊ0���򴰿ڴ�С������ͼ��Ĵ�С���ı䡣
	cvNamedWindow("Image-in", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("Image-out", CV_WINDOW_AUTOSIZE);
	//����ʾԭjpgͼ
	cvShowImage("Image-in", img);
	//����ռ�洢������ͼ��
	IplImage *out = cvCreateImage(
		cvGetSize(img),//��ǰͼ���С
		IPL_DEPTH_8U,//��ͨ��ÿ�����ص������
		3//ͨ������
	);
	//���и�˹�����������ָ��imgָ����ڴ棬�����������ݽ���outָ��ָ����ڴ棬
	//��ÿ��������Χ3x3��������и�˹ƽ��������ʵ�������ͼ���������ͬ�ģ�
	cvSmooth(img, out, CV_GAUSSIAN, 3, 3);
	//��ʾ������ͼ��
	cvShowImage("Image-out", out);

	//�������
	cvReleaseImage(&out);
	cvReleaseImage(&img);

	//cvWaitKey�Ĳ����������ֵ��������ȴ���ֵ�����룬Ȼ��������У�����Ǹ�ֵ����0���ͻ�ȴ��û���������������Ȼ���������
	cvWaitKey();
	//���ٴ��ڣ����ɺ�ϰ��
	cvDestroyWindow("Image-in");
	cvDestroyWindow("Image-out");

	return 0;

}
