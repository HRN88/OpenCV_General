//Dibujar rectangulo en una imagen

#include <opencv2/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace std;
using namespace cv;

int main(){
	char NombreImagen[] = "agalloch.jpg";
	Mat imagen;
	int j, i;
	imagen = imread(NombreImagen);
	if (!imagen.data){
		cout << "Error al cargar la imagen" << NombreImagen << endl;
		exit(1);

	}

	for (i = imagen.cols / 4; i < 3 * imagen.cols / 4; i++){
		for (j = imagen.rows / 4; j < 3 * imagen.rows / 4; j++){
			imagen.at<Vec3b>(Point(i, j)) = Vec3b(0, 44, 0);
		}
	}

	namedWindow("Agalloch", CV_WINDOW_AUTOSIZE);
	imshow("Agalloch", imagen);

	imwrite("Agalloch_modificada.jpg", imagen);
	cvWaitKey(0);
	return(0);

}