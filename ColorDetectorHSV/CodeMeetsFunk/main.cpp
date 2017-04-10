#include <cstdlib>
#include<cstdio>
#include<opencv2\opencv.hpp>

using namespace std;
using namespace cv;


void detectHScolor(const Mat &imagen, double minHue, double maxHue, double minSat, double maxSat, Mat &mask){
	Mat hsv;
	cvtColor(imagen, hsv, CV_BGR2HSV);
	vector<Mat> channels;
	split(hsv, channels);
	

	Mat mask1;
	threshold(channels[0], mask1, maxHue, 255, THRESH_BINARY_INV);
	

	Mat mask2;
	threshold(channels[0], mask2, minHue, 255, THRESH_BINARY);


	Mat hueMask;
	if (minHue < maxHue)
		hueMask = mask1&mask2;
	else
		hueMask = mask1 | mask2;


	threshold(channels[1], mask1, maxSat, 255, THRESH_BINARY_INV);
	
	threshold(channels[1], mask2, minSat, 255, THRESH_BINARY);
	

	Mat satMask;
	satMask = mask1&mask2;
	imshow("satmask", satMask);

	mask = hueMask&satMask;
	imshow("hue", hueMask);
	imshow("mask", mask);


}
int main(){


	cvNamedWindow("salida", WINDOW_AUTOSIZE);
	cvNamedWindow("entrada", WINDOW_AUTOSIZE);

	Mat salida, entrada, mask;

	VideoCapture video;
	video.open(0);

	for (;;){
		video >> entrada;
		entrada.copyTo(salida);
		Mat detected(salida.size(), CV_8UC3, Scalar(0, 0, 0));
		salida.copyTo(detected, mask);
		detectHScolor(salida, 160, 5, 25, 150, mask);
		imshow("masked", mask);
		imshow("color", detected);
		
		if (waitKey(30) >= 0)
			break; 
	}
	

	

	
}
