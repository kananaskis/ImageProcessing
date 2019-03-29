#include <iostream>
#include <opencv2/opencv.hpp>

int main()
{
	cv::Mat src = cv::imread("./img/src.jpg");
	cv::imshow("img",src);
	cv::waitKey(0);
	return 0;
}