// description: example_09-03
// Using a trackbar to create a "switch" that the user can turn on and off;
//
// An example program in which the user can draw boxes on the screen
// edited: ihaoming
// date: 2018/04/23

#include<opencv2/opencv.hpp>
#include<iostream>

using namespace std;

int g_switch_value = 1;
void switch_off_function() { cout<< "Pause"<<endl;}
void switch_on_function() { cout<< "Run"<<endl;}

void switch_callback( int position, void*)
{
	if( position == 0)
	{
		switch_off_function();
	}
	else
	{
		switch_on_function();
	}
}


int  main(int argc, char** argv)
{
	cv::Mat frame;		//To hold movie images
	cv::VideoCapture g_capture;

	cv::namedWindow("example_09-03", cv::WINDOW_AUTOSIZE);
	
	g_capture.open("./test_video.avi");

	cv::createTrackbar(
		"switch",
		"example_09-03",
		&g_switch_value,
		1,
		switch_callback
		);

	for(;;)
	{
		if(g_switch_value )
		{
			g_capture >> frame;
			if( frame.empty()) break;
			cv::imshow("example_09-03", frame);
		}
		if( cv::waitKey(10) == 27 ); break;//esc
	}
	return 0;
}