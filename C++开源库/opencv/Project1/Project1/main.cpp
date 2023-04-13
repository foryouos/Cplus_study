#include<opencv2/opencv.hpp>
#include<iostream>
using namespace cv;

int main(int argc, char** argv)
{
	Mat src = imread("D:/01.png");
	if (src.empty())
	{
		printf("could not load image...\n");
		return -1;
	}
	namedWindow("test opencv setup", WINDOW_AUTOSIZE);
	imshow("test opencv setup", src);

	waitKey(0);
	return 0;
}
