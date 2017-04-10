//En este ejercicio se muestra el uso de las lookup tables

#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>
#include <stdio.h>

using namespace std;
using namespace cv;

int main(){

	char NombreImagen[] = "lunasumada.jpg";
	Mat imagen;

	imagen = cv::imread(NombreImagen);
	if (!imagen.data){
		cout << "Error al cargar la imagen" << endl;
		exit(1);
	}

	//Se crea tabla para almacenar los calculos
	Mat lut(1, 256, CV_8U);

	//A continuacion se llenara la tabla con valores que permitan realizar una transformacion a la imagen original

	for (int i = 0; i < 256; i++){
		lut.at<uchar>(i) = 255 - i;
		//lut.at<uchar>(i) = pow((float)i * 255, (float)(1 / 2.0));
	}
	LUT(imagen, lut, imagen);
	//Mostrando la imagen

	namedWindow("LUT", CV_WINDOW_AUTOSIZE);
	imshow("LUT", imagen);
	waitKey(0);
	return 0;

}