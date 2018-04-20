// description: example_09-02
// Toy program for using a mouse to draw boxes on the screen
// edited: ihaoming
// date: 2018/04/20

#include<opencv2/opencv.hpp>

//Define the callback function
void my_mouse_callback(int event, int x, int y, int flags, void* param);
//Draw funcions
void draw_box( cv::Mat& image, cv::Rect box);

bool drawing_box = false;
cv::Rect g_box;


int main(int argc, char** argv)
{
	g_box = cv::Rect(-1, -1, 0, 0);
	cv::Mat image(200, 200, CV_8UC3), temp;
	image.copyTo(temp);

	g_box = cv::Rect(-1, -1, 0, 0);
	image = cv::Scalar::all(0);

	cv::namedWindow("Box Example", cv::WINDOW_NORMAL);

	cv::setMouseCallback(
		"Box Example",
		my_mouse_callback,
		(void*)&image
		);

	for(;;)
	{
		image.copyTo(temp);
		if( drawing_box ) draw_box(temp, g_box);
		cv::imshow("Box Example", temp);

		if(cv::waitKey(15) == 27 ) break;
	}
	return 0;
}

//Draw funcions
void draw_box( cv::Mat& image, cv::Rect box)
{
	cv::rectangle(
		image,
		box.tl(),				//top left
		box.br(),				//bottom right
		cv::Scalar(0, 0, 255)	//red
		);
}


//the callback function
void my_mouse_callback(int event, int x, int y, int flags, void* param)
{
	cv::Mat& image = *(cv::Mat*) param;

	switch(event)
	{
	case cv::EVENT_MOUSEMOVE:	//the mouse moving
		{
			if( drawing_box )
			{
				//while drawing,get the width and height
				g_box.width = x - g_box.x;
				g_box.height = y - g_box.y;
			}
		}
		break;
	case cv::EVENT_LBUTTONDOWN:	//the left buttom down
		{
			drawing_box = true;
			g_box = cv::Rect(x, y, 0, 0);
		}
		break;
	case cv::EVENT_LBUTTONUP:	//the left buttom up
		{
			drawing_box = false;
			if( g_box.width < 0)
			{
				g_box.x += g_box.width;
				g_box.width *= -1;
			}
			if( g_box.height < 0)
			{
				g_box.y += g_box.height;
				g_box.height *= -1;
			}

			draw_box( image, g_box );
		}
		break;
	}
}