#include <iostream>
#include <opencv2/opencv.hpp>

//dst(x,y) = 255 * [src(x,y) – min(src(x,y)) ] / [ (max(src(x,y)) – min(src(x,y)) ]

int main()
{
	cv::Mat src = cv::imread("./img/ori.jpg");
	cv::Mat src_hsv;
	cv::cvtColor(src, src_hsv, CV_BGR2HSV);
	cv::imshow("img0",src);

	int width = src_hsv.cols;
	int height = src_hsv.rows;
	unsigned char max_s = 0, max_v = 0;
	unsigned char min_s = 255, min_v = 255;
	for (int i = 0; i < height; ++i)
	{
		
		for (int j = 0; j < width; ++j)
		{
			max_s = src_hsv.data[i*width*3 + j*3 + 1] > max_s ? src_hsv.data[i*width*3 + j*3 + 1] : max_s;
			max_v = src_hsv.data[i*width*3 + j*3 + 2] > max_v ? src_hsv.data[i*width*3 + j*3 + 2] : max_v;
			min_s = src_hsv.data[i*width*3 + j*3 + 1] < min_s ? src_hsv.data[i*width*3 + j*3 + 1] : min_s;
			min_v = src_hsv.data[i*width*3 + j*3 + 2] < min_v ? src_hsv.data[i*width*3 + j*3 + 2] : min_v;	
		}
	}
	if ( max_s == min_s || max_v == min_v)
	{
		/* code */
		std::cout << "error!\n";
	}
	for (int i = 0; i < height; ++i)
	{
		for (int j = 0; j < width; ++j)
		{
			unsigned char s = src_hsv.data[i*width*3 + j*3 + 1];
			unsigned char v = src_hsv.data[i*width*3 + j*3 + 2];
			
     		src_hsv.data[i*width*3 + j*3 + 1] = (s - min_s) * 255 / (max_s - min_s);        //关键语句
     		src_hsv.data[i*width*3 + j*3 + 2] = (v - min_v) * 255 / (max_v - min_v); 	
		}
	}

	cv::cvtColor(src_hsv, src, CV_HSV2BGR);
	cv::imshow("img",src);
	cv::waitKey(0);
	return 0;
}