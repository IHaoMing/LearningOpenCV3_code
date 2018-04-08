// description: example_02-05
// Loading and then smoothing an image before it displayed on screen
// edited: ihaoming
// date: 2018/04/08

#include<opencv2/opencv.hpp>


int main()
{
	//step1: Load an image
	cv::Mat image = cv::imread("./lena.jpg");
	
	//step2: Create some windows to show the input and output images
	cv::namedWindow("Example 02-05-in", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("Example 02-05-out", cv::WINDOW_AUTOSIZE);

	cv::imshow("Example 02-05-in", image);

	//Create an image to hold smoothed output
	cv::Mat out;

	cv::GaussianBlur(image, out, cv::Size(5, 5), 3, 3);
	cv::GaussianBlur(out, out, cv::Size(5, 5), 3, 3);

	//show the smooted image in the output window
	cv::imshow("Example 02-05-out", out);

	cv::waitKey( 0 );
	return 0;
}
