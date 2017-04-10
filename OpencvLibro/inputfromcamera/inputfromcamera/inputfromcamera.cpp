/*En este ejemplo se aprendera a capturar video de la camara y mostrarlo en la pantalla*/

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cstdio>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

void colorReduce(Mat imagen, int factor){
	int nfilas = imagen.rows;
	int ncols = imagen.cols *imagen.channels();
	for (int j = 0; j < nfilas; j++){
		uchar *data = imagen.ptr<uchar>(j);				//Nos devuelve la direccion de la fila (j) en la imagen
		for (int i = 0; i < ncols; i++){
			data[i] = data[i] / factor*factor + factor / 2;
			//data[i] = data[i] - data[i] % factor + factor / 2;
		}
	}
}
int main(){

	namedWindow("Camara", CV_WINDOW_AUTOSIZE);
	VideoCapture cam(0);
	/*if (argc == 1){
		cam.open(0);
	}
	else{
		cam.open(argv[1]);
	}*/
	if (!cam.isOpened()){
		cout << "No se puede capturar el video" << endl;
		return -1;
	}

	Mat gray, canny;
	for (;;){
		Mat frame;
		cam >> frame;
		cvtColor(frame, gray, COLOR_BGR2GRAY);
		colorReduce(gray, 128);
		GaussianBlur(gray, gray, Size(3, 3), 1.5, 1.5);
		Canny(gray, canny, 50, 60, 3);
		
		imshow("Camara", canny);
		if (waitKey(30) >= 0) break;
	}


	return 0;
}