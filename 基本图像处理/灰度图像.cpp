#include "stdafx.h"

#include <stdio.h>
#include <stdlib.h>
#include <opencv/cv.h>
#include <opencv/highgui.h>

int toGray(IplImage* img)
{
	IplImage* dst = cvCreateImage(cvGetSize(img), IPL_DEPTH_8U, 1);//��ԭͼ��ָ�봴����ͼ��
	if (NULL == dst)
		return -1;
	cvCvtColor(img, dst, CV_BGR2GRAY);//ת����ɫ�ռ� ���Թ������û����һ�� �õ���ͼ����ȫ��


	cvNamedWindow("Gray", CV_WINDOW_AUTOSIZE);
	cvShowImage("Gray", dst);
	cvSaveImage("Gray.jpg", dst, 0);//����


	cvWaitKey(0);
	cvReleaseImage(&dst);
	cvDestroyWindow("Gray");

	return 1;
}


int main()
{
	IplImage* img = cvLoadImage("E:/test1.jpg", CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR);

	//�����Ҫ��������ʵ��ͼ��ѡ��CV_LOAD_IMAGE_ANYDEPTH | CV_LOAD_IMAGE_ANYCOLOR��

	if (NULL == img)
	{
		printf("Image load fail!\n");
		return 2;
	}

	cvNamedWindow("RGB", CV_WINDOW_AUTOSIZE);
	cvShowImage("RGB", img);

	toGray(img);

	cvReleaseImage(&img);
	cvDestroyWindow("RGB");

	return 0;
}
