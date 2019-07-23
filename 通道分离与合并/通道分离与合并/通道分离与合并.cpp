// 通道分离与合并.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;

int main()
{

	vector<Mat> channels;
	Mat imageB, imageR, imageG;
	Mat srcimage = imread("1.jpg", 1);
	split(srcimage, channels);
	imageB = channels.at(0);
	imageR = channels.at(1);
	imageG = channels.at(2);
	imshow("原图", srcimage);
	imshow("蓝", imageB);
	imshow("绿", imageG);
	imshow("宏", imageR);
	waitKey(10000);
	imwrite("蓝分离色道.jpg", imageB);
	imwrite("绿分离色道.jpg", imageG);
	imwrite("宏分离色道.jpg", imageR);

	//合并
	Mat mergeall;
	merge(channels, mergeall);
	imshow("合并", mergeall);
	imwrite("合并图.jpg",mergeall);
	waitKey(6000);
	return 0;
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
