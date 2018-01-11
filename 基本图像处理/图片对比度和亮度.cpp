
/*
g(i,j) = a*f(i,j) + b
两个参数a 和B 一般称作 增益 和 偏置 参数。我们往往用这两个参数来分别控制 对比度 和 亮度 。
其中， i 和 j 表示像素位于 第i行 和 第j列

*/

/*
我们可以不用 for 循环来访问每个像素，而是直接采用下面这个命令：
image.convertTo(new_image, -1, alpha, beta);
这里的 convertTo 将执行我们想做的 new_image = a*image + beta 。
然而，我们想展现访问每一个像素的过程，所以选用了for循环的方式。
实际上，这两种方式都能返回同样的结果。
*/

#include"stdafx.h"
#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

using namespace std;
using namespace cv;

double alpha;  /// 控制对比度
int beta;      /// 控制亮度

int main()
{
	/// 读入用户提供的图像
	Mat image = imread("E:/test1.jpg");
	Mat new_image = Mat::zeros(image.size(), image.type());
	///像素值初始化为0
	///与原图像有相同的大小和类型
	///	用 image.size() 和 image.type() 来对Mat对象进行0初始化。
	/// 初始化
	cout << " Basic Linear Transforms " << endl;
	cout << "-------------------------" << endl;
	cout << "* Enter the 对比度 值 [1.0-3.0]: ";
	cin >> alpha;
	cout << "* Enter the 亮度   值 [-100-100]: ";
	cin >> beta;

	/// 执行运算 new_image(i,j) = alpha*image(i,j) + beta

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

	/// 创建窗口
	namedWindow("Original Image", 1);
	namedWindow("New Image", 1);

	/// 显示图像
	imshow("Original Image", image);
	imshow("New Image", new_image);

	/// 等待用户按键
	waitKey();
	return 0;
}

