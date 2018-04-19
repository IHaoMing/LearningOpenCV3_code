// description: example_09-01
// Create a window and dispalying an image in that window
// edited: ihaoming
// date: 2018/04/19

#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;

int main(int argc,char** argv)
{
	if(argc != 2){cout<< "You need to supply an image path/name." <<endl;}

	//Create a named window with the name of the file
	cv::namedWindow(argv[1], 1);

	//Load the image from the given filename
	cv::Mat image = cv::imread( argv[1] );

	//Show the image in the named window
	if( !image.empty() ){cv::imshow( argv[1], image );}

	//Idle until the user hits the Esc key
	cv::waitKey(0);

	//Clean up and don't be piggies

	cv::destroyWindow( argv[1] );
	return 0;
}