

#include <opencv2/opencv.hpp>
#include <stdio.h>
#include <iostream>
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"

using namespace cv;
using namespace std;


int main(){
	//Cargamos la imagen
	char NombreImagen[] = "chess.jpg";
	Mat src, dst;
	src = cv::imread(NombreImagen);
	//Comprobando la carga de la imagen
	if (!src.data){
		cout << "Error al cargar la imagen" << NombreImagen << endl;
		exit(1);
	}

	//Se crea un vector de matrices llamado bgr_planos, aqui se guardaran los canales RGB de la imagen
	vector<Mat> bgr_planes;

	// Usamos la funcion split para separar los canales de una imagen multicanal en canales RGB independientes
	split(src, bgr_planes);


	//Matrices de salida despues de calcular el histograma
	int histSize = 256;
	float Range[] = { 0, 256 };
	const float *histRange = { Range };
	bool uniform = true;
	bool accumulate = false;
	Mat b_hist, r_hist, g_hist;

	//Calculando el histograma
	calcHist(&bgr_planes[0], 1, 0, Mat(), b_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[1], 1, 0, Mat(), g_hist, 1, &histSize, &histRange, uniform, accumulate);
	calcHist(&bgr_planes[2], 1, 0, Mat(), r_hist, 1, &histSize, &histRange, uniform, accumulate);

	//Dibujando el histograma
	int hist_w = 800;
	int hist_h = 600;
	//Para la relacion de Pixeles vs muestras de intensidad.
	int bin_w = cvRound((double)hist_w / histSize);

	Mat histImage(hist_h, hist_w, CV_8UC3, Scalar(0, 0, 0));

	normalize(b_hist, b_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(r_hist, r_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());
	normalize(g_hist, g_hist, 0, histImage.rows, NORM_MINMAX, -1, Mat());

	for (int i = 1; i < histSize; i++){
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(b_hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(b_hist.at<float>(i))),
			Scalar(255, 0, 0), 2, 8, 0);
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(g_hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(g_hist.at<float>(i))),
			Scalar(0, 255, 0), 2, 8, 0);
		line(histImage, Point(bin_w*(i - 1), hist_h - cvRound(r_hist.at<float>(i - 1))),
			Point(bin_w*(i), hist_h - cvRound(r_hist.at<float>(i))),
			Scalar(0, 0, 255), 2, 8, 0);
	}
		


	/// Display
	namedWindow("Histograma", CV_WINDOW_AUTOSIZE);
	imshow("Histograma", histImage);
	waitKey(0);

	return 0;


}