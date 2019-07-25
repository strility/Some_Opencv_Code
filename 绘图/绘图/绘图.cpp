// 绘图.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>

using namespace std;
using namespace cv;


#define WINDOW_NAME1 "pircture1"
#define WINDOW_NAME2 "pircture2"
#define WINDOW_WIDTH 600

void DrawEllipse(Mat img, double angle) {
	int thickness = 2;
	int lineType = 8;
	ellipse(img, Point(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2), Size(WINDOW_WIDTH / 16, WINDOW_WIDTH / 4), angle, 0, 360, Scalar(150, 150, 250), thickness, lineType);
}
void DrawFilledCricle(Mat img, Point center) {
	int thickness = -1;
	int lineType = 8;
	circle(img, center, WINDOW_WIDTH / 32, Scalar(150, 255, 30), thickness, lineType);
}


void text1() {
	Mat atomImage = Mat::zeros(WINDOW_WIDTH, WINDOW_WIDTH, CV_8UC3);
	DrawEllipse(atomImage, 90);
	DrawEllipse(atomImage, 0);
	DrawEllipse(atomImage, 45);
	DrawEllipse(atomImage, -45);
	DrawFilledCricle(atomImage, Point(WINDOW_WIDTH / 2, WINDOW_WIDTH / 2));
	imshow(WINDOW_NAME1, atomImage);
	waitKey();
}



int main()
{
	text1();
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
