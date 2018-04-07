// description: example_02-01 
// A simple OpenCV program that loads an image from disk and displays it

// edited: ihaoming
// date: 2018/04/07

//included files
#include<opencv2/opencv.hpp>

int main(int argc, char** argv)
{
	//step1: imread
	cv::Mat img = cv::imread("./lena.jpg");

	if(img.empty()) return -1;

	//step2: nameWindow and imshow
	cv::namedWindow("Example 2-1", cv::WINDOW_AUTOSIZE);
	cv::imshow("Example 2-1", img);
	cv::waitKey(0);
	cv::destroyWindow("Example 2-1");

	return 0;
}