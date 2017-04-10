#pragma once
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cstdio>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

class HistogramBn {
private:
	//Los atributos son los neecesarios  para la funcion calcHist();
	/*histSize = numero de contenedores en el histograma
	  hrnage   = es el rango de valores maximo y minimo que tomaran los contenedores ne este caso es de 0.0 a 256.0
	  ranges   = es un apuntador a hranges, esto asi lo pide la funcion de opencv
	  channels = es el numero de canales de la imagen, en este caso al ser en B/N el numero de canales es 1*/

	int histSize[1]; //Numbers of bins in histogram
	float hranges[2]; // range of values
	const float *ranges[1]; //Pointer to the value ranges
	int channels[1]; //Channel number to be examinated

public:
	HistogramBn() {
		//Prepare default arguments for 1D histogram
		histSize[0] = 256; //256 bins
		hranges[0] = 0.0; // From 0 (inclusive)
		hranges[1] = 256.0; //to 256 (exclusive)
		ranges[0] = hranges;
		channels[0] = 0; //Channel 0
	}

	//Computes the histogram for one dimension
	Mat getHistogram(const Mat &image) {
		Mat hist;
		//Computes the histogram
		calcHist(&image, 1, channels, Mat(), hist, 1, histSize, ranges);
		return hist;

	}
	// Computes the 1D histogram and returns an image of it.
	Mat getHistogramImage(const Mat &image, int zoom = 1) {
		//Compute histogram first
		Mat hist = getHistogram(image);
		//Creates image
		return getImageOfHistogram(hist, zoom);
	}

	static Mat getImageOfHistogram(const Mat &hist, int zoom) {
		//Get min and max bin values
		double maxVal = 0;
		double minVal = 0;
		minMaxLoc(hist, &minVal, &maxVal, 0, 0);
		cout << "MaxVal:" << maxVal << endl;
		//get histogram size
		int histSize = hist.rows;
		cout << hist.rows << endl;
		//square image on which to display histogram
		Mat histImg(histSize*zoom, histSize*zoom, CV_8U, Scalar(255));
		//set highest pont at 90% of nbins
		int hpt = static_cast<int>(0.9*histSize);
		//Draw vertical line of each bin
		for (int h = 0; h < histSize; h++) {
			float binVal = hist.at<float>(h);
			if (binVal > 0) {
				int intensity = static_cast<int>(binVal*hpt / maxVal);
				cv::line(histImg, Point(h*zoom, histSize*zoom),Point(h*zoom, (histSize - intensity)*zoom),Scalar(0), zoom);
			}
		}
		return histImg;

	}

	static Mat applyLookUp(const Mat &image, const Mat& lookup) {
		Mat result;
		LUT(image, lookup, result);
		return result;
	}
	Mat stretch(const Mat &image, int minValue = 0) {
		//Primero calculamos el histograma
		Mat histograma = getHistogram(image);
		//Encontrando el valor min de la izquierda a la derecha
		int imin = 0;
		for (; imin < histSize[0]; imin++) {
			if (histograma.at<float>(imin) > minValue)
				break;
		}
		int imax = histSize[0] - 1;
		for (; imax >= 0; imax--) {
			if (histograma.at<float>(imax) > minValue)
				break;
		}
		//Creando la lookuptable
		int dim(256);
		Mat lut(1, &dim, CV_8U);
		//consttruyendo la LUT
		for (int i = 0; i < dim; i++) {
			if (i < imin)
				lut.at<uchar>(i) = 0;
			else if (i > imax)
				lut.at<uchar>(i) = 255;
			else
				lut.at<uchar>(i) = cvRound(255.0*(i - imin) / (imax - imin));
		}
		Mat result;
		result = applyLookUp(image, lut);
		return result;



	}
};