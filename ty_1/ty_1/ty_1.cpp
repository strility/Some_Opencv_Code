// ty_1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;



int main()
{
	Mat pricture1 = imread("1.jpg");
	namedWindow("离开");
	imshow("ok", pricture1);
	Mat pricture2 = imread("淡雅.jgp");
	Mat logo = imread("1.jpg");
	namedWindow("原图");
	imshow("logo", logo);

	Mat imageROI;
	imageROI = pricture1(Rect(800, 350, logo.cols, logo.rows));
	//pricture1(Range(350, 350 + logo.rows), Range(800, 800 + logo.cols));
	addWeighted(imageROI, 0.5, logo, 0.3, 0., imageROI);
	namedWindow("tu");
	imshow("tu4", pricture1);
	imwrite("由imwrite生成的图片", pricture1);
	waitKey(6000);
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
