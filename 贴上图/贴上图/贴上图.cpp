// 贴上图.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include "pch.h"
#include <iostream>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
using namespace std;
using namespace cv;


int main()
{//有问题的   线性混合
	Mat srcImage = imread("1.jpg", 0);
	Mat Image = imread("2.jpg", 0);
	if (!srcImage.data||!Image.data)
		cout << "error" << endl;
	Mat imageROI = srcImage(Rect(60, 50,50,50));
	Mat mark = imread("2.jpg", 0);	
	Image.copyTo(imageROI, mark);
	addWeighted(imageROI, 0.4, Image, 0.4, 0,imageROI);
	//namedWindow("显示窗口");
	imshow("显示窗口", imageROI);
	imshow("ok",mark);
	imwrite("生成图.jpg", imageROI);
	waitKey(10000);


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
