// 阈值法otsu.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<opencv2/imgproc/types_c.h>
using namespace std;
using namespace cv;

int otus(Mat Image)
{
	if (CV_8UC1 != Image.type())
		return -1;
	int c = Image.cols;
	int r = Image.rows;
	int the_rect = c * r;
	int Pnum[256] = { 0 };
	double probability[256] = { 0.0 };
	for (int i = 0; i < r; i++)
	{
		for (int j = 0; j < c; j++)
		{
			Pnum[Image.at<uchar>(i, j)]++;
		}
	}
	for (int i = 0; i < 256; i++) {
		probability[i] = (double)0.1*Pnum[i] / the_rect;
	}
	int Threshold = 0;//最终阈值
	double mean_right = 0.0, mean_left = 0.0;//左右平均值
	double Data = 0.0,maxData = 0.0;//类间方差 //最大方差 类间
	double temp_right = 0.0, temp_left = 0.0;//左右平均中间值
	double right_probability = 0.0, left_probability = 0.0;//左右频率值
	for (int j = 0; j < 256; j++)
	{
		for (int i = 0; i < 256; i++) {
			if (i < j) {
				right_probability += probability[i];
				temp_right += i * probability[i];
			}
			else {
				left_probability += probability[i];
				temp_left += i * probability[i];
			}
		}
		mean_right = temp_right / right_probability;
		mean_left = temp_left / left_probability;
		Data = (double)(right_probability*left_probability*pow((mean_right - mean_left), 2));
		if (Data > maxData) {
			maxData = Data;
			Threshold = j;
		}
		maxData = 0.0;
		mean_right = 0.0, mean_left = 0.0;
		Data = 0.0;
		temp_right = 0.0, temp_left = 0.0;
		right_probability = 0.0, left_probability = 0.0;
	}
	return Threshold;
}
int main()
{
	Mat Image0 = imread("2.jpg", 1);
	int C = Image0.cols;
	int R = Image0.rows;
	Mat matGray;
	cvtColor(Image0, matGray, CV_BGR2GRAY);
	imshow("gray", matGray);
	int OTUS_Threshold = otus(matGray);
	Mat	matOtus = Mat::zeros(matGray.rows, matGray.cols, CV_8UC1);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			if (matGray.at<uchar>(i, j) < OTUS_Threshold)
				matOtus.at<uchar>(i, j) = matGray.at<uchar>(i, j);
			else
				matOtus.at<uchar>(i, j) = 0;
		}
	}
	imshow("OTUS", matOtus);
	waitKey(0);
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
