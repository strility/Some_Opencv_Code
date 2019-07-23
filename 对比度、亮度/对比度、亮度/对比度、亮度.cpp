// 对比度、亮度.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;
int C_V;
int B_V;
Mat g_Image, b_Image;
static void on_contrastAndBright(int, void *) {
	namedWindow("效果2222", 1);
	for (int y = 0; y < b_Image.rows; y++)
		for (int x = 0; x < b_Image.cols; x++)
			for (int k = 0; k < 3; k++)
				b_Image.at<Vec3b>(y, x)[k] = saturate_cast<uchar>((C_V*0.01)*(g_Image.at<Vec3b>(y, x)[k]) + B_V);
	imshow("原始窗口22222", g_Image);
	imshow("效果2222", b_Image);
}
int main()
{
	system("color5F");

	//读入用户提供的图像
	g_Image = imread("1.jpg");
	b_Image= Mat::zeros(g_Image.size(), g_Image.type());

	//设定对比度和亮度的初值
	C_V = 80;
	B_V = 80;

	//创建窗口
	namedWindow("效果2222", 1);
	createTrackbar("对比度：", "效果2222", &C_V, 300, on_contrastAndBright);
	createTrackbar("亮   度：", "效果2222", &B_V, 200, on_contrastAndBright);

	//调用回调函数
	on_contrastAndBright(C_V, 0);
	on_contrastAndBright(B_V, 0);
	while (char(waitKey(1) != 'q')) {
	}
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

