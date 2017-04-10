#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cstdio>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(){
	//Cargando la imagen

	char NombreImagen[] = "IVVI.jpg";

	Mat src = cv::imread(NombreImagen);
	if (!src.data){
		cout << "Error al cargar la imagen" << endl;
		exit(1);
	}

	//Mostramos la imagen cargada
	namedWindow("SRC", CV_WINDOW_AUTOSIZE);
	imshow("SRC", src);
	//Matriz de destino
	Mat dst;

	//SCALE

	resize(src, dst, )

	waitKey(0);



	return 0;
}