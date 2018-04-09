// description: example_02-11
// Acomplete program to read in a  color video and write out the  log-polar transformed video
// edited: ihaoming
// date: 2018/04/09

#include<opencv2/opencv.hpp>
#include<iostream>

int main(int argc, char** argv)
{
	cv::namedWindow("example_02-11", cv::WINDOW_AUTOSIZE);
	cv::namedWindow("example_02-11-polar", cv::WINDOW_AUTOSIZE);

	cv::VideoCapture cap("./test_video.avi");
	double fps = cap.get(CV_CAP_PROP_FPS);

	cv::Size size(
		(int)cap.get(CV_CAP_PROP_FRAME_WIDTH),
		(int)cap.get(CV_CAP_PROP_FRAME_HEIGHT) );

	cv::VideoWriter writer;

	writer.open("writer_video.avi", CV_FOURCC('M','J','P','G'), fps, size);
	
	cv::Mat logpolar_frame, bgr_frame;
	for(;;)
	{
		cap>>bgr_frame;
		if( bgr_frame.empty()) break;

		cv::imshow("example_02-11", bgr_frame);

		cv::logPolar(
			bgr_frame,
			logpolar_frame,
			cv::Point2f(bgr_frame.cols/2, bgr_frame.rows/2),
			40,
			CV_WARP_FILL_OUTLIERS );

		cv::imshow("example_02-11-polar", logpolar_frame);

		writer<<logpolar_frame;

		int c = cv::waitKey(10);

		if(c == 27)break;

	}

	writer.release();
	cap.release();
	return 0;
}