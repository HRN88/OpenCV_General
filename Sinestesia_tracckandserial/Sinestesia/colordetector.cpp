#include <cstdlib>
#include<cstdio>
#include<opencv2\opencv.hpp>
#include "colordetector.h"
#include "Serial.h"

using namespace std;
using namespace cv;
CSerial serial;
ColorDetector::ColorDetector(int minh, int maxh, int mins, int maxs, int minv, int maxv, char color,string cadena){
	setcolor(minh, maxh, mins, maxs, minv, maxv, color,cadena);
}

void ColorDetector::setcolor(int minh, int maxh, int mins, int maxs, int minv, int maxv, char color, string cadena){
	maxH = maxh;
	maxS = maxs;
	minH = minh;
	minS = mins;
	minV = minv;
	maxV = maxv;
	color_ = color;
	cadena_ = cadena;

		
}

void ColorDetector::proceso(Mat imagen){
	Mat hsv;
	cvtColor(imagen, hsv, COLOR_BGR2HSV);
	vector<Mat> canales;
	split(hsv, canales);
	
	//Segmentacion para el canal H
	Mat mask1;
	threshold(canales[0], mask1, maxH, 255, THRESH_BINARY_INV);
	Mat mask2;
	threshold(canales[0], mask2, minH, 255, THRESH_BINARY );
	Mat hueMask;
	if (minH < maxH)
		hueMask = mask1&mask2;
	else
		hueMask = mask1 | mask2;

	//Segmentacion para el canal S

	threshold(canales[1], mask1, maxS, 255, THRESH_BINARY_INV);
	threshold(canales[1], mask2, minS, 255, THRESH_BINARY);
	/*..................................................*/
	Mat satMask;
	satMask = mask1 & mask2;
	mask = hueMask & satMask;
	cout << color_ << endl;
	imshow("mask", mask);
	imshow("hsv", hsv);

}

void ColorDetector::getcolor(){
	cout << "Hmax = " << maxH << endl;
	cout << "Hmin = " << minH << endl;
	cout << "Smax = " << maxS << endl;
	cout << "Smin = " << minS << endl;
}

Mat ColorDetector::proceso_inrange(Mat imagen){
	//Parametros para la comunicacion serie
	static char *flag = NULL;
	//Matrices para almacenar la conversion HSV y el resultado
	Mat hsv = imagen;
	//blur(imagen, imagen, Size(5, 5));
	Mat estructura(5, 5, CV_8U, Scalar(1));
	//Cambiando de espacio de color
	//cvtColor(imagen, hsv, CV_BGR2HSV);
	inRange(hsv, Scalar(minH, minS, minV), Scalar(maxH, maxS, maxV), hsv);
	//Se aplica operador morfologico abierto para reducir los pixeles ruido
	morphologyEx(hsv, hsv, MORPH_OPEN, estructura);
	//erode(hsv, hsv, getStructuringElement(MORPH_CROSS, Size(5, 5)));
	//imagen.copyTo(res, hsv);
	//imshow("mask",hsv);
	Moments mom = moments(hsv);

	if (mom.m00 > 5000){
		int cx = mom.m10 / mom.m00;
		int cy = mom.m01 / mom.m00;
		//circle(imagen, Point(cx, cy), 2, Scalar(0, 0, 255), 2);
		//circle(imagen, Point(cx, cy), 80, Scalar(255, 255, 255), 2);
		putText(imagen, cadena_, Point(cx, cy), FONT_HERSHEY_SCRIPT_COMPLEX, 3, Scalar(0, 0, 0), 2);

		flag = &color_;
		if (serial.Open(5, 9600)){
			
			int nBytesSent = serial.SendData(flag, strlen(flag));
		}
		

		
		cout << color_ << endl;
	}
	return imagen;

}
void ColorDetector::serialcom(){
	if (serial.Open(5, 9600)){
		cout << "comunicacion correcta" << endl;

	}
}

void ColorDetector::mandastop(){
	if (serial.Open(5, 9600)){
		
	}
}


void ColorDetector::proceso_inrange_2(Mat imagen){
	//Parametros para la comunicacion serie
	static char *flag = NULL;
	//Matrices para almacenar la conversion HSV y el resultado
	Mat hsv, res;
	//blur(imagen, imagen, Size(5, 5));
	Mat estructura(5, 5, CV_8U, Scalar(1));
	//Cambiando de espacio de color
	cvtColor(imagen, hsv, CV_BGR2HSV);
	inRange(hsv, Scalar(minH, minS, minV), Scalar(maxH, maxS, maxV), hsv);
	//Se aplica operador morfologico abierto para reducir los pixeles ruido
	morphologyEx(hsv, hsv, MORPH_OPEN, estructura);
	//erode(hsv, hsv, getStructuringElement(MORPH_CROSS, Size(5, 5)));
	//imagen.copyTo(res, hsv);
	//imshow("mask",hsv);
	Moments mom = moments(hsv);

	if (mom.m00 > 5000){
		int cx = mom.m10 / mom.m00;
		int cy = mom.m01 / mom.m00;
		flag = &color_;
		if (serial.Open(5, 9600)){

			int nBytesSent = serial.SendData(flag, strlen(flag));
		}



		cout << color_ << endl;
	}
	//resize(imagen, imagen, Size(800, 600));

}