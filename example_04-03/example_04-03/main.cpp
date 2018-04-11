// desciption: example_04-03
// Printing all of the nonzero elements of spare array
// edited: ihaoming
// date: 2018/04/11

#include<iostream>
#include<opencv2/opencv.hpp>

using namespace std;

int main(int argc, char** argv)
{
	int size[] = {10, 10};
	cv::SparseMat sm(2, size, CV_32F);

	for(int i=0; i<10; i++)
	{
		int idx[2];
		idx[0] = size[0] * rand();
		idx[1] = size[1] * rand();
		sm.ref<float>( idx ) += 1.0f;
	} 

	cv::SparseMatConstIterator_<float> it = sm.begin<float>();
	cv::SparseMatConstIterator_<float> it_end = sm.end<float>();

	for(; it != it_end; ++it)
	{
		const cv::SparseMat::Node* node = it.node();
		printf(" (%3,%3d) %f\n", node->idx[0], node->idx[1], *it );
	}

	return 0;
}