// 金字塔、缩放比例.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
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
	Mat Image = imread("1.jpg", 1);
	Mat temImage, DImage1, DImage2,DImage3;
	temImage = Image;
	imshow("原始图", Image);
	pyrDown(temImage, DImage1, Size(temImage.cols / 2, temImage.rows / 2));
	imshow("缩小", DImage1);


	pyrUp(temImage, DImage2, Size(temImage.cols * 2, temImage.rows * 2));
	imshow("扩大", DImage2);

	resize(temImage, DImage3, Size(temImage.cols / 4, temImage.rows / 4), (0, 0)(0, 0), 3);
	imshow("比例", DImage3);
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
