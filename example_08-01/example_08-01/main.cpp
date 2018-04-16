// description: example_08-01
// Unpacking a four-character code to identify a vido codec
// 解压缩四字符代码以识别视频编解码器
// edited: ihaoming
// date: 2018/04/16

#include<opencv2/core/core.hpp>
#include<opencv2/highgui/highgui.hpp>
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	if(argc != 2)
	{
		return 0;
	}

	cv::VideoCapture cap( argv[1] );
	
	unsigned f = (unsigned) cap.get( cv::CAP_PROP_FOURCC);

	char fourcc[] = 
	{
		(char) f,
		(char) (f>>8),
		(char) (f>>16),
		(char) (f>>24),
		'\0'
	};
	
	std::cout<<"FourCC for this video was: "<<fourcc<<endl;
	getchar();
	return 0;
}