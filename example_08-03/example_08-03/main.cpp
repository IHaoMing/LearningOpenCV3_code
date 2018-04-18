// description: example_08-03
// Using cv::FileStorage to read a .yml file
// edited: ihaoming
// date: 2018/04/18

#include<opencv2/opencv.hpp>

using namespace std;

int main(int argc, char** argv)
{
	//step1: open a file
	cv::FileStorage fs2("test.yml", cv::FileStorage::READ);

	//fist method: use(type) operator on FileNode
	int frame_count = (int)fs2["frameCount"];

	//second method: use cv::FileNode::operator >>

	std::string date;

	fs2["calibrationDate"]>>date;

	cv::Mat camera_matrix2, dist_coeffs2;
	fs2["cameraMatrix"] >> camera_matrix2;
	fs2["distCoeffs"] >> dist_coeffs2;

	cout<<" frame_count: "<<frame_count<<endl
		<<" calibration date: "<<date<<endl
		<<" camera matrix: "<<camera_matrix2<<endl
		<<" distortion coffs: "<<dist_coeffs2<<endl;

	cv::FileNode features =  fs2["features"];
	cv::FileNodeIterator it = features.begin(), it_end = features.end();

	int idx = 0;
	std::vector<uchar> lbpval;

	//iterate through  a sequence using FileNodeIterator
	for(; it != it_end; ++it, idx++)
	{
		 for( ; it != it_end; ++it, idx++ )
		 {
			cout << "feature #" << idx << ": ";
			cout << "x="   << (int)(*it)["x"]
				 << ", y=" << (int)(*it)["y"]
				 << ", lbp: (";

			// ( Note: easily read numerical arrays using FileNode >> std::vector. )
			//
			(*it)["lbp"] >> lbpval;
			for( int i = 0; i < (int)lbpval.size(); i++ )
			cout << " " << (int)lbpval[i];
			cout << ")" << endl;
		}
	}
	fs2.release();
	getchar();
	return 0;
}