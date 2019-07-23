// ok_.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;


void colorReaduce1(Mat & inputImage, Mat & outputImage, int div) {
	outputImage = inputImage.clone();
	int row = outputImage.rows;
	int col = outputImage.cols*outputImage.channels();
	for (int i = 0; i < row; i++) {
		uchar*data = outputImage.ptr<uchar>(i);
		for (int j = 0; j < col; j++) {
			data[j] = data[j] * div / div + div / 2;
		}
	}
}


void colorReaduce2(Mat & inputImage, Mat & outputImage, int div) {
	outputImage = inputImage.clone();
	Mat_<Vec3b>::iterator it = outputImage.begin<Vec3b>();
	Mat_<Vec3b>::iterator itend = outputImage.end<Vec3b>();
	for (; it != itend; it++) {
		(*it)[0] = (*it)[0]/div * div + div / 2;
		(*it)[1] = (*it)[0] / div * div + div / 2;
		(*it)[2] = (*it)[0] / div * div + div / 2;
	}
}

void colorReaduce3(Mat & inputImage, Mat & outputImage, int div) {
	outputImage = inputImage.clone();
	int row = outputImage.rows;
	int col = outputImage.cols;
	for (int i = 0; i < row; i++) {
		for (int j = 0; j < col; j++) {
			outputImage.at<Vec3b>(i, j)[0] = outputImage.at<Vec3b>(i, j)[0] / div * div + div / 2;
			outputImage.at<Vec3b>(i, j)[1] = outputImage.at<Vec3b>(i, j)[0] / div * div + div / 2;
			outputImage.at<Vec3b>(i, j)[2] = outputImage.at<Vec3b>(i, j)[0] / div * div + div / 2;
		}
	}
}

void test1() {
	Mat scrImage = imread("1.jpg");
	imshow("图像", scrImage);
	Mat  dstImage;
	dstImage.create(scrImage.rows, scrImage.cols, scrImage.type());
	double time = static_cast<double>(getTickCount());
	colorReaduce1(scrImage, dstImage, 32);
	time = ((double)getTickCount() - time) / getTickCount();
	cout << "指针法:" << time << endl;
	imshow("成品", dstImage);
	waitKey(6000);
}
void test2() {
	Mat scrImage = imread("1.jpg");
	imshow("图像", scrImage);
	Mat  dstImage;
	dstImage.create(scrImage.rows, scrImage.cols, scrImage.type());
	double time = static_cast<double>(getTickCount());
	colorReaduce2(scrImage, dstImage, 32);
	time = ((double)getTickCount() - time) / getTickCount();
	cout << "迭代器法:" << time << endl;
	imshow("成品", dstImage);
	waitKey(6000);
}
void test3() {
	Mat scrImage = imread("1.jpg");
	imshow("图像", scrImage);
	Mat  dstImage;
	dstImage.create(scrImage.rows, scrImage.cols, scrImage.type());
	double time = static_cast<double>(getTickCount());
	colorReaduce3(scrImage, dstImage, 32);
	time = ((double)getTickCount() - time) / getTickCount();
	cout << "动态地址法:" << time << endl;
	imshow("成品", dstImage);
	waitKey(6000);
}
int main()
{
	test1();
	test2();
	test3();
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
