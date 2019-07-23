// my_code.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
using namespace std;
using namespace cv;


int main()
{
	Mat image = imread("2.jpg", 1);
	Mat image2,image3,image4,image5,image6;
	imshow("原图", image);
	namedWindow("方框滤波");
	boxFilter(image, image2, -1, Size(5, 5));
	imshow("方框滤波", image2);
	namedWindow("均值滤波");
	blur(image, image3,Size(1,1));
	imshow("均值滤波", image3);
	namedWindow("高斯滤波");
	GaussianBlur(image, image4, Size(1, 1), 0, 0);
	imshow("高斯滤波", image4);
	namedWindow("中值滤波");
	medianBlur(image, image5, 7);
	imshow("中值滤波", image5);
	namedWindow("双边滤波");
	bilateralFilter(image, image6, 25,25*2,25/2);
	imshow("双边滤波", image6);
	waitKey(0);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门提示: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
