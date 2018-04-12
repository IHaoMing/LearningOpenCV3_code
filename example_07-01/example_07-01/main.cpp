// description: example_07-01
// Using the default random number generator to generate a pair of integers
// and a pair of floating-poit numbers
// edited: ihaoming
// date: 2018/04/12

#include<opencv2/core/core.hpp>
#include<iostream>

using namespace std;

int main(int argc, char** argv)
{
	cv::RNG rng = cv::theRNG();
	cout<<" An integer: "<<(int)rng<<endl;
	cout<<" Another integer: "<<int(rng)<<endl;

	cout<<" A float: "<<(float)rng<<endl;
	cout<<" Another float: "<<float(rng)<<endl;

	return 0;
}