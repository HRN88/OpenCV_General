#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <stdio.h>
#include <iostream>
#include <opencv2/core/core.hpp>

using namespace cv;
using namespace std;

int main(){

	//Cargando la imagen
	char NombreImagen[] = "foto.jpg";
	Mat imagen, destino, kernel;

	imagen = cv::imread(NombreImagen);
	if (!imagen.data){
		cout << "Error al cargar la imagen" << endl;
		exit(1);
	}

	kernel = Mat::ones(5, 5, CV_32F)/(float)25;
	cout << "kernell" << kernel << endl;
	filter2D(imagen, destino, -1, kernel, Point(-1, -1), 0, BORDER_DEFAULT);

	//Mostrando las imagenes
	namedWindow("Original", CV_WINDOW_AUTOSIZE);
	imshow("Original", imagen);
	namedWindow("Filtrado", CV_WINDOW_AUTOSIZE);
	imshow("Filtrado", destino);
	cvWaitKey(0);


	return 0;
}