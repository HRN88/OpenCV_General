/*Operaciones aritmeticas con imagenes*/
//Debido a que las imagenes son matrices es posible hacer operaciones aritmeticas logicas entre estas.
//Existen algunas funciones que nos permiten hacerlo, pero tambien es posible la sobrecarga de operadores
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cstdio>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;


int main(){
	char NombreTextura[] = "textura.jpg";
	char NombreImagen[] = "city.jpg";
	Mat src1 = imread(NombreImagen);
	Mat src2 = imread(NombreTextura);
	Mat dst;
	if (src1.empty() || src2.empty()) {
		cout << "Error al leer las imagenes" << endl;
	}

	namedWindow("Imagen", WINDOW_AUTOSIZE);
	namedWindow("Textura", WINDOW_AUTOSIZE);
	imshow("Imagen", src1);
	imshow("Textura", src2);
	//addWeighted(src1, 0.5, src2, 0.9,0,dst); //Operacion suma con funcion
	dst = 0.7*src1 + 0.9*src2; // Operacion suma con sobrecarga de opreadores
	namedWindow("Destino", WINDOW_AUTOSIZE);
	imshow("Destino", dst);
	waitKey(0);
	
	return 0;
}