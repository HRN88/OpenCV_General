#include <cstdlib>
#include <cstdio>
#include <iostream>
#include <opencv2\opencv.hpp>

using namespace std;
using namespace cv;
int main(){
	//Se carga una imagen desde carpeta de imagenes
	//Mat imagen = imread("C:/Users/Funkadmin/Documents/bacteria.jpg"); //Probando imagen 1 bacteria
	Mat imagen = imread("C:/Users/Funkadmin/Documents/rostro.jpg"); //Probando imagen 2 rostro

	//Matriz de elemento
	Mat element5(3, 3, CV_8U, Scalar(1));

	//Matriz para imagen resultante
	Mat result;

	//Se aplica el efecto erode 
    //erode(imagen, result, element5);

	//Se aplica el efecto dilatation
	//dilate(imagen, result, element5);

	//Se aplica el efecto closing
	//morphologyEx(imagen, result, MORPH_CLOSE, element5);

	//Se aplica el efecto  opening
	morphologyEx(imagen, result, MORPH_OPEN, element5);


	//Visualizacion de imagenes
	imshow("Entrada", imagen);
	imshow("Salida", result);

	waitKey(0);
	return(0);
	
	 

	

	
}
