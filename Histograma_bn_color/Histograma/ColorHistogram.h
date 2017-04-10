#include <cstdlib>
#include <cstdio>
#include <iostream>
#include<opencv2\opencv.hpp>


using namespace std;
using namespace cv;

class ColorHistogram{
private:
	int histSize = 256;
	float range[2];
	const float *histRange = { range };
	Mat bhist, ghist, rhist;

public:
	ColorHistogram();
	void getHistogramColor(const Mat &imagen);
	void getImageOfHistogramColor(const Mat &imagen);
	Mat getPlotOfHistogramImage(Mat &histograma, int zoom, Scalar color);
	static Mat applyLookUp(const Mat &imagen, const Mat &lookup);
	
};