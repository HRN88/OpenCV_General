//#include <stdafx.h>
//#include <opencv2/highgui/highgui.hpp>
//#include <opencv2/imgproc/imgproc.hpp>
//#include <cstdio>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int main()
{
	//Nombre de la imagen que se va a cargar
	char NombreImagen[] = "agalloch.jpg";
	Mat imagen;

	imagen = imread(NombreImagen);
	if (!imagen.data){
		cout << "Error al cargar la imagen: " << NombreImagen << endl;
		exit(1);
	}

	namedWindow("original", CV_WINDOW_AUTOSIZE);
	imshow("original", imagen);
	waitKey(0);
	return 0;





}