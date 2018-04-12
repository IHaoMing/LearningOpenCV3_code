// description: example_05-01
// Complete program to alpha-blend the ROI starting at (0, 0) in src2 with the ROI starting at (x, y) in src1
// alphablend <imageA> <imageB> <x> <y> <alpha> <beta>

#include<opencv2/opencv.hpp>
#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<iostream>

using namespace cv;
using namespace std;

int main(int argc, char**)
{
	cv::Mat src1 = cv::imread("./src1.jpg");
	cv::Mat src2 = cv::imread("./src2.jpg");

	int from_w = src1.size().width;
	int from_h = src1.size().height;
	int to_w = src2.size().width;
	int to_h = src2.size().height;

	if( src1.empty() || src2.empty() ) return -1;
	
	int x = 200;
	int y = 100;

	cv::Mat roi1(src1, cv::Rect(0, 0, from_w - 1, from_h -1));
	cv::Mat roi2(src1, cv::Rect(x, y, from_w - 1, from_h -1));

	cv::addWeighted(roi1, 0.5, roi2, 0.5, 0.0, roi2);

	cv::namedWindow("Alpha Blend", cv::WINDOW_AUTOSIZE);
	cv::imshow("Alpha Blend", src2);

	cv::waitKey(0);

	cv::destroyWindow("Alpha Blend");

	return 0;
}