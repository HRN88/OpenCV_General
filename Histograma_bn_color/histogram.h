#include <cstdlib>
#include<cstdio>
#include<opencv2\opencv.hpp>

using namespace std;
using namespace cv;

class Histogram1D{
private:
	int histSize[1]; // Parametro que pide la funcion por defecto
	float hranges[2]; 
	const float *ranges[1]; //Parameetro que pide la funcion por defecto
	int channels[1]; //Parametro que pide la funcion por defecto

public:
	Histogram1D();
	Mat getHistogram(const Mat &imagen);
	Mat getHistogramImage(const Mat &imagen, int zoom = 1);
   static Mat getImageOfHistogram(const Mat &hist, int zoom);
   static Mat applyLookUp(const Mat &imagen, const Mat & lookup);
   Mat Stretch(const Mat &imagen, int minValue);

};