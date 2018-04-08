// description: example_02-04
// edited: ihaoming
// date: 2018/04/08

#include<opencv2/highgui/highgui.hpp>
#include<opencv2/imgproc/imgproc.hpp>
#include<iostream>
#include<fstream>

using namespace std;

//declare global variables
int g_slider_position = 0;
int g_run = 1;
int g_donset = 0;
cv::VideoCapture g_cap;

void onTrackbarSlider(int pos, void*);

int main(int argc, char** argv)
{
	cv::namedWindow("Example 2-4", cv::WINDOW_AUTOSIZE);

	g_cap.open("./test_video.avi");

	int frames = (int)g_cap.get( CV_CAP_PROP_FRAME_COUNT  );
	int tmpw   = (int)g_cap.get( CV_CAP_PROP_FRAME_WIDTH  );
	int tmph   = (int)g_cap.get( CV_CAP_PROP_FRAME_HEIGHT );

	//output the information of the video
	cout<<"Video has "<<frames<<" frames of demensions£¨"
		<< tmpw << ","<<tmph<<")"<<endl;
	//ctreate the trackbar
	cv::createTrackbar("Position", "Example 2-4", &g_slider_position, frames, onTrackbarSlider);

	cv::Mat frame;
	for(;;)
	{
		//running
		if( g_run != 0)
		{
			g_cap >> frame;
			if( frame.empty()) return -1;
			int current_pos = (int)g_cap.get(CV_CAP_PROP_POS_FRAMES);
			g_donset = 1;

			cv::setTrackbarPos("Position", "Example 2-4", current_pos);
			cv::imshow("Example 2-4", frame);

			g_run -= 1;
		}

		char c = (char) cv::waitKey(10);
		//set single step
		if( c == 's' )
		{
			g_run = 1;
			cout<<"Single step, run = "<<g_run<<endl;
		}

		//set the run mode
		if( c == 'r')
		{
			g_run = -1;
			cout<<"Run mode, run = "<<g_run<<endl;
		}

		if( c == 27)break;
	}

	return 0;
}

void onTrackbarSlider(int pos, void*)
{
	g_cap.set(CV_CAP_PROP_POS_FRAMES, pos);
	if( !g_donset ) g_run = 1;

	g_donset = 0;
}