// description: example_02-10
// The same object can load videos from a camera or a file
// edited: ihaoming
// date: 2018/04/09

#include<iostream>
#include<opencv2/opencv.hpp>

int main(int argc, char** argv)
{
	cv::VideoCapture cap;
	cv::namedWindow("example_02-10", cv::WINDOW_AUTOSIZE);

	if(argc == 2)
	{
		cap.open(0);
	}
	else
	{
		cap.open("./test_video.avi");
	}

	if( !cap.isOpened())
	{
		std::cerr<<" Couldn't open capture."<<std::endl;
		return -1;
	}


	cv::Mat frame;

	for(;;)
	{
		cap>>frame;
		if( frame.empty() )break;

		cv::imshow("example_02-10", frame);
		if( cv::waitKey(33) >= 0) break;
	}
	return 0;
}