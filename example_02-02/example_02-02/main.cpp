﻿// desripton: example 2-2
// Same as Example 2-1 but employing the âusing namespaceâ directive
// edited: ihaoming
// date: 2018/04/07

#include<opencv2/highgui/highgui.hpp>
#include<iostream>

using namespace cv;

int main(int argc, char** argv)
{
	Mat img = imread("./lena.jpg");

	if(img.empty() ) return -1;

	namedWindow("Example 2-2", cv::WINDOW_AUTOSIZE);
	imshow("Example 2-2", img);
	waitKey(0);

	destroyWindow("Example 2-2");
	return 0;
}