#include <cstdlib>
#include<cstdio>
#include<opencv2\opencv.hpp>
#include"ColorHistogram.h"
using namespace std;
using namespace cv;

ColorHistogram::ColorHistogram(){
	
}

void ColorHistogram::getHistogramColor(const Mat &imagen){
	//Calcula el histograma de cada canal
	vector<Mat> canal;
	split(imagen, canal);
	range[0] = 0;
	range[1] = 256;
	calcHist(&canal[0], 1, 0, Mat(), bhist, 1, &histSize, &histRange);
	calcHist(&canal[1], 1, 0, Mat(), ghist, 1, &histSize, &histRange);
	calcHist(&canal[2], 1, 0, Mat(), rhist, 1, &histSize, &histRange);
}

void ColorHistogram::getImageOfHistogramColor(const Mat &imagen){
	//Muestra en pantalla la grafica del histograma de cada canal
	getHistogramColor(imagen);
	imshow("Bhist", getPlotOfHistogramImage(bhist, 1, Scalar(255, 0, 0)));
	imshow("Ghist", getPlotOfHistogramImage(ghist, 1, Scalar(0, 255, 0)));
	imshow("Rhist", getPlotOfHistogramImage(rhist, 1, Scalar(0, 0, 255)));

}

Mat ColorHistogram::getPlotOfHistogramImage(Mat &histograma, int zoom, Scalar color){
	//Grafica el histograma en la pantalla
	double minVal;
	double maxVal;
	minMaxLoc(histograma, &minVal, &maxVal, 0, 0);
	cout <<"minimo " <<minVal << " maximo " << maxVal << endl;
	int histSize = histograma.rows;
	Mat histImage(histSize*zoom, histSize*zoom, CV_8UC3, Scalar(255,255,255));

	//Poner el punt mas alto sera a 90%

	int hpt = static_cast<int>(histSize*0.9);

	for (int i = 0; i < histSize; i++){
		float binval = histograma.at<float>(i);
		if (binval > 0){
			int intensity = static_cast<int>(binval*hpt / maxVal); // Que pedo con esto
			line(histImage, Point(i*zoom, histSize*zoom), Point(i*zoom, (histSize - intensity)*zoom), color, 1);
		}
	}
	return histImage;

}
