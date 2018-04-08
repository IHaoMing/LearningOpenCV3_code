// description: example_02-06
// Using cv::pyrDown() to create a new image that is half the width and height of the input image
// edited: ihaoming
// date: 2018/04/08

#include<opencv2/opencv.hpp>

int main(int argc, char** argv)
{
	cv::Mat img1, img2;

	cv::namedWindow("example_02-06-in", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("example_02-06-out", cv::WINDOW_AUTOSIZE);

	img1 = cv::imread("./lena.jpg");

	cv::imshow("example_02-06-in", img1);
	
	cv::pyrDown(img1, img2);

	cv::imshow("example_02-06-out", img2);
	cv::waitKey( 0 );

	return 0;
}