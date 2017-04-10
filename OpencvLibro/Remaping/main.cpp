//En este ejemplo se muestra como modificar la pocicion de los pixeles de una imagen, esto se conoce como
//transformaciones geometricas.
//Se utiliza la funcion remap para situar los nuevos pixeles en una nueva matriz, estos pixeles aparecen en un lugar diferente,
//la funcion remap permite cualquier transformacion geometrica diseñada por el programador, pero son necesarios los argumentos que pide.
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cstdio>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void wave(Mat &imagen, Mat &resultado);
int main(){
	char NI[] = "cat.jpg";
	Mat img = imread(NI);
	Mat dst;
	namedWindow("IMG", WINDOW_AUTOSIZE);
	wave(img, dst);
	imshow("IMG", dst);
	waitKey(0);	

	return 0;
}

void wave(Mat &imagen, Mat &resultado) {
	Mat srcX(imagen.rows, imagen.cols, CV_32F);
	Mat srcY(imagen.rows, imagen.cols, CV_32F);
	for (int i = 0; i < imagen.rows; i++) {
		for (int j = 0; j < imagen.cols; j++) {
			srcX.at<float>(i, j) = j; //Matriz con las nuevas pociciones de los pixeles en el eje x
			srcY.at<float>(i, j) = i + 10 * sin(j / 10.0); //Matriz con las nuevas pociciones de los pixeles en el eje y
		}
	}
	remap(imagen, resultado, srcX, srcY, INTER_NEAREST); //Funcion remap
}