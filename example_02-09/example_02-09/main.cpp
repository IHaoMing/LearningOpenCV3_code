// description:  example_02-09
// Getting and setting pixels in example 2-8
// edited: ihaoming
// date:2018/04/09

#include<opencv2/opencv.hpp>

int main(int argc, char** argv)
{
	cv::Mat img_rgb, img_cny, img_pyr1, img_pyr2, img_gry;

	cv::namedWindow("example_02-09-gray", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("example_02-09-canny", cv::WINDOW_AUTOSIZE);

	img_rgb = cv::imread("./lena.jpg");

	cv::cvtColor(img_rgb, img_gry, cv::COLOR_BGR2GRAY);
	cv::pyrDown(img_gry, img_pyr1);
	cv::pyrDown(img_pyr1, img_pyr2);

	cv::Canny(img_pyr2, img_cny, 10, 100, 3, true);

	//Getting the pixels
	int x = 16, y = 32;
	cv::Vec3b intensity = img_rgb.at<cv::Vec3b>(y, x);
	
	uchar blue  = intensity[0];
	uchar green = intensity[1];
	uchar red   = intensity[2];

	//Display the intensity

	std::cout<< "At (x, y) = ("<<x<<", "<<y<<
		"): (blue, green, red) = (" <<
		(unsigned int)blue<<","<<
		(unsigned int)green<<", "<<
		(unsigned int)red<<")"<<std::endl;

	std::cout<< "Gray pixel there is: "<<
		(unsigned int)img_gry.at<uchar>(y, x)<<std::endl;

	x /= 4; y /= 4;

	std::cout<< "Pyramid2 pixel there is: "<<
		(unsigned int)img_pyr2.at<uchar>(y, x)<<std::endl;

	//Set the Canny pixel there to 128
	img_cny.at<uchar>(x, y) = 128;

	cv::imshow("example_02-09-gray", img_gry);
	cv::imshow("example_02-09-canny", img_cny);

	cv::waitKey(0);

	return 0;
}