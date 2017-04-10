#include <cstdlib>
#include<cstdio>
#include<opencv2\opencv.hpp>
#include"histogram.h"

using namespace std;
using namespace cv;

Histogram1D::Histogram1D(){
	histSize[0] = 256; //Son 256 valores o bins
	hranges[0] = 0.0;  //Rango de 0 a 256
	hranges[1] = 256.0;
	ranges[0] = hranges;
	channels[0] = 0;
	
}

Mat Histogram1D::getHistogram(const Mat &imagen){
	Mat hist;
	calcHist(&imagen, 1, channels, Mat(), hist, 1, histSize, ranges);
	return hist;

}

 Mat Histogram1D::getImageOfHistogram(const Mat &hist, int zoom){
	 double minVal;
	 double maxval;
	 minMaxLoc(hist, &minVal, &maxval, 0, 0);

	 int histSize = hist.rows;
	 Mat histImage(histSize*zoom, histSize*zoom, CV_8U, Scalar(255));

	 //Poner el punt mas alto sera a 90%

	 int hpt = static_cast<int>(histSize*0.9);

	 for (int i = 0; i < histSize; i++){
		 float binval = hist.at<float>(i);
		 if (binval > 0){
			 int intensity = static_cast<int>(binval*hpt/ maxval); // Que pedo con esto
			 line(histImage, Point(i*zoom, histSize*zoom), Point(i*zoom, (histSize - intensity)*zoom),Scalar(0),2);
		 }
	 }
	 return histImage;
}

Mat Histogram1D::getHistogramImage(const Mat &imagen, int zoom){
	Mat hist = getHistogram(imagen);
	return getImageOfHistogram(hist, zoom);
}

Mat Histogram1D::applyLookUp(const Mat &imagen, const Mat &lookup){
	Mat result;
	LUT(imagen, lookup, result);
	return result;
}

Mat Histogram1D::Stretch(const Mat &imagen, int minValue){
	//1) Se calcula el histograma
	Mat hist = getHistogram(imagen);
	//2) Encontrando el extremo hizquierdo de la imagen
	int imin = 0;
	//Se hace un bucle 
	for (; imin < histSize[0]; imin++){
		if (hist.at<float>(imin) > minValue) break;
	}
	int imax = histSize[0] - 1;
	for (; imax <= 0; imax--){
		if (hist.at<float>(imax) > minValue) break;
	}

	//3) Creando la LUT
	int dim(256);
	Mat lookup(1, &dim, CV_8U);
	//4) Construyendo la LUT

	for (int i = 0; i < 256; i++){
		if (i < imin) lookup.at<uchar>(i) = 0;
		else if (i>imax) lookup.at<uchar>(i) = 255;
		else lookup.at<uchar>(i) = cvRound(255.0*(i - imin) / (imax - imin));
	}

	//5) Aplicando la LUT
	Mat result;
	result = applyLookUp(imagen, lookup);
	return result;

}