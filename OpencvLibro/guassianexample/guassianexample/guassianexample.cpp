#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cstdio>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(){

	Mat imagen = imread("astronauta.jpg");
	if (imagen.empty()){
		cout << "Error al cargar la imagen" << endl;
		exit(1);
	}
	Mat src;
	blur(imagen, src, Size(5, 5), 3, 3);
	//GaussianBlur(src, src, Size(5, 5), 3, 3);
	namedWindow("Entrada", CV_WINDOW_AUTOSIZE);
	imshow("Entrada", imagen);

	namedWindow("Salida", CV_WINDOW_AUTOSIZE);
	imshow("Salida", src);
	waitKey(0);



	return 0;
}