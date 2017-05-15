
/*Ejemplo de deteccion de bordes y esquinas*/

#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;
int main(){
	//Se carga una imagen desde carpeta de imagenes
	Mat imagen = imread("C:/Users/Funkadmin/Documents/ojo.jpg"); //Probando imagen 2 rostro
	cvtColor(imagen, imagen, CV_BGR2GRAY);
	Mat result;
	imshow("d", imagen);

	//Se detectan los bordes
	morphologyEx(imagen, result, MORPH_GRADIENT, Mat());
	imshow("asdf", result);

	threshold(result, result, 40, 255, THRESH_BINARY);
	imshow("asdfd", result);
	waitKey(0);
	return(0);
	
	 

	

	
}
