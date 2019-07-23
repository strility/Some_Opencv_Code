// 边缘检测.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/imgproc/types_c.h>
using namespace cv;
using namespace std;



int main()
{
	Mat Image1, Image2, Image3, Image4, Image5;
	Image1 = imread("2.jpg", 1);
	Image2 = Image1.clone();
	imshow("原图", Image1);
	cvtColor(Image1, Image1, CV_BGR2GRAY);
	Canny(Image1, Image1, 90,30,3);
	imshow("处理后的边缘", Image1);
	Image3.create(Image2.size(), Image2.type());
	cvtColor(Image2, Image5, CV_BGR2GRAY);
	blur(Image5, Image4, Size(3, 3));
	Canny(Image4, Image4, 3, 9, 3);
	Image3 = Scalar::all(0);
	Image2.copyTo(Image3, Image4);
	imshow("颜色掩模边缘图", Image3);
	waitKey(0);



	Mat gray_x, gray_y;
	Mat deviation_x, deviation_y;
	Mat Image = imread("2.jpg"),all;
	resize(Image, Image, Size(Image.cols / 2, Image.rows / 2), INTER_NEAREST);
	imshow("原图", Image);
	cvtColor(Image, Image, CV_BGR2GRAY);
	Sobel(Image, gray_x, CV_16S, 1, 0, 3, 1, 1, BORDER_DEFAULT);
	convertScaleAbs(gray_x, deviation_x);
	imshow("X效果图", deviation_x);

	Sobel(Image, gray_y, CV_16S, 0, 1, 3, 1, 1, BORDER_DEFAULT);
	convertScaleAbs(gray_y, deviation_y);
	imshow("Y效果图", deviation_y);

	addWeighted(deviation_x, 0.5, deviation_y, 0.5, 1, all);
	imshow("叠加图", all);
	waitKey(0);


	Mat Image6, gray_1, Image7, Image8;
	Image6 = imread("1.jpg");
	resize(Image6, Image6, Size(Image6.cols / 2, Image6.rows / 2), INTER_NEAREST);
	imshow("原图",Image6);
	GaussianBlur(Image6, Image6, Size(3, 3), 0, 0, BORDER_DEFAULT);
	cvtColor(Image6, gray_1, CV_RGB2GRAY);
	Laplacian(gray_1, Image7, CV_16S, 3, 1, 0, BORDER_DEFAULT);
	convertScaleAbs(Image7, Image8);
	imshow("效果图", Image8);
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
