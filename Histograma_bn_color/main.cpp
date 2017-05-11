#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <opencv2\opencv.hpp>
#include "histogram.h"
#include "ColorHistogram.h"
using namespace std;
using namespace cv;
int main(){
	/*
	//Seccion para calcular el histograma a color en video
	Mat escena;
	VideoCapture frame;
	frame.open(0);
	ColorHistogram histograma;
	for (;;){
	frame >> escena;
	imshow("escena", escena);
	histograma.getImageOfHistogramColor(escena);
	if (waitKey(30) > 0) break;
	}
	*/



	//Seccion para aplicar una LUT de inversa
	/*
	Mat escena;
	VideoCapture frame;
	frame.open(0);
	Mat lut(1, 256, CV_8U);
	for (int i = 0; i <256; i++){
	lut.at<uchar>(i) = 255-i;
	}
	Mat resultado;
	for (;;) {
		frame >> escena;
		LUT(escena, lut, resultado);
		imshow("result", resultado);
		if (waitKey(30) > 0)break;
	}*/
	


	//Strtching image
	Mat src = imread("imagen.jpg");
	cvtColor(src, src, CV_BGR2GRAY);
	imshow("SRC", src);
	Histogram1D hist;
	imshow("Histograma", hist.getHistogramImage(src, 2));
	imshow("Stretched", hist.Stretch(src, 21));

	waitKey(0);
	return(0);
	
	 

	

	
}
