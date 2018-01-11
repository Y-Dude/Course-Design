#include "stdafx.h"
#include "cv.h"
#include <cxcore.h>
#include <highgui.h>


int main(int argc, _TCHAR* argv[])
{
	//将图像文件加载至内存 分配图像数据结构所需要的内控 返回一个指向数据结构IplImage的内存块：
	IplImage *img = cvLoadImage("E:/test1.jpg");
	//需要把这个图片放在这个project下面，比如我的：&user name\Documents\Visual Studio 2010\Projects\opencvhello\opencvhello文件夹里面
	//定义两个窗口，自由大小。本函数由HighGUI库提供。第二个参数如果为0，则窗口大小不会因图像的大小而改变。
	cvNamedWindow("Image-in", CV_WINDOW_AUTOSIZE);
	cvNamedWindow("Image-out", CV_WINDOW_AUTOSIZE);
	//先显示原jpg图
	cvShowImage("Image-in", img);
	//分配空间存储处理后的图像
	IplImage *out = cvCreateImage(
		cvGetSize(img),//当前图像大小
		IPL_DEPTH_8U,//各通道每个像素点的类型
		3//通道总数
	);
	//进行高斯处理，处理的是指针img指向的内存，将处理后的数据交给out指针指向的内存，
	//对每个像素周围3x3的区域进行高斯平滑处理（其实输入输出图像可以是相同的）
	cvSmooth(img, out, CV_GAUSSIAN, 3, 3);
	//显示处理后的图像
	cvShowImage("Image-out", out);

	//清除垃圾
	cvReleaseImage(&out);
	cvReleaseImage(&img);

	//cvWaitKey的参数如果是正值，则程序会等待数值个毫秒，然后继续运行；如果是负值或者0，就会等待用户触发按键操作，然后继续程序。
	cvWaitKey();
	//销毁窗口，养成好习惯
	cvDestroyWindow("Image-in");
	cvDestroyWindow("Image-out");

	return 0;

}
