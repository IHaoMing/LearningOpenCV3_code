// description:  example_02-08
// Combining the pyramind down operator(twice) and the Canny subroutine in a simple image pipline
// edited: ihaoming
// date:2018/04/09

#include<opencv2/opencv.hpp>

int main(int argc, char** argv)
{
	cv::Mat img_rgb, img_cny, img_pyr1, img_pyr2, img_gry;

	cv::namedWindow("example_02-08-gray", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("example_02-08-canny", cv::WINDOW_AUTOSIZE);

	img_rgb = cv::imread("./lena.jpg");

	cv::cvtColor(img_rgb, img_gry, cv::COLOR_BGR2GRAY);
	cv::pyrDown(img_gry, img_pyr1);
	cv::pyrDown(img_pyr1, img_pyr2);

	cv::Canny(img_pyr2, img_cny, 10, 100, 3, true);

	cv::imshow("example_02-08-gray", img_gry);
	cv::imshow("example_02-08-canny", img_cny);

	cv::waitKey(0);

	return 0;
}