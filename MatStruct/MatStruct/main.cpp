#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cstdio>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;


Mat function() {
	Mat ima(500, 500, CV_8U, 50);
	return ima;
}

int main(){
	namedWindow("Imagen 1");
	namedWindow("Imagen 2");
	namedWindow("Imagen 3");
	namedWindow("Imagen 4");
	namedWindow("Imagen 5");
	namedWindow("Imagen");

	// create a new image made of 240 rows and 320 columns
	Mat imagen1(240, 320, CV_8U, 100); //Define la matriz al momento de la instancia
	imshow("Imagen 1", imagen1);
	waitKey(0);
	// re-allocate a new image
	imagen1.create(200, 200, CV_8U);	//Define la matriz, despues de la instancia
	imagen1 = 0;					//Al hacer esto asignamos el color de los pixeles, es decir de toda la matriz
	imshow("Imagen", imagen1);
	waitKey(0);

	// create a red color image
	/*Mat imagen2(240, 320, CV_8UC3, Scalar(0, 0, 255));
	imshow("Imagen 2", imagen2);
	waitKey(0);*/

	// OR

	Mat imagen2(Size(320,240), CV_8UC3);
	imagen2 = Scalar(0, 0, 255);
	imshow("Imagen", imagen2);
	waitKey(0);

	//Read an image

	Mat imagen3 = imread("puppy.jpg");
	Mat imagen4(imagen3);
	imagen1 = imagen3;
	imagen3.copyTo(imagen2);
	Mat imagen5 = imagen3.clone();
	flip(imagen3, imagen3, 1);

	imshow("Imagen 3", imagen3);
	imshow("Imagen 1", imagen1);
	imshow("Imagen 2", imagen2);
	imshow("Imagen 4", imagen4);
	imshow("Imagen 5", imagen5);
	waitKey(0);

	Mat gray = function();
	imshow("Imagen", gray);
	waitKey(0);

	imagen1 = imread("puppy.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	imagen1.convertTo(imagen2, CV_32F, 1 / 255.0, 0.0);
	imshow("Imagen", imagen2);
	waitKey(0);

	return 0;
}