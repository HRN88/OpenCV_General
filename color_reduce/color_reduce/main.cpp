#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cstdio>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

//Version 1
//En esta version el procesamiento es in-place modificandose la imagen de entrada
void colorReduce(Mat imagen, int reduccion) {
	int nl = imagen.rows;
	int nc = imagen.cols * imagen.channels();
	for (int i = 0; i < nl; i++) {
		uchar* data = imagen.ptr<uchar>(i);
		for (int j = 0; j < nc; j++) {
			data[j] = ((data[j] / reduccion) * reduccion) + (reduccion / 2);
		}
	}
}

//Version 2
//En esta version se piden no se modififica la imagen de entrada, se hace una copia con clone.

//Version 3
//En esta version no se hace clone, se realiza el procesamiento con apuntadores
void colorReduce3(const Mat &imagen, Mat &salida, int reduccion) {
	int nl = imagen.rows; //Numero de columnas
	int nc = imagen.cols*imagen.channels(); //Numero de pixeles totales
	salida.create(imagen.rows, imagen.cols, imagen.type()); //Se crea la matriz de salida con las mismas dimensiones y tipo que la matriz de entrada
	for (int i = 0; i < nl; i++) { //Ciclo for para las lineas
		const uchar *ptr_imagen = imagen.ptr<uchar>(i); //Obtenemos la direccion de cada linea en la imagen de entrada
		uchar *ptr_salida = salida.ptr<uchar>(i); //Obtenemos la direccionde cada linea en la imagen de salida
		for (int j = 0; j < nc; j++) { //Ciclo para columnas (pixeles)
			ptr_salida[j] = ((ptr_imagen[j] / reduccion) * reduccion) + (reduccion / 2); //Reduccion de cada pixel en la salida, en funcion de los pixeles de la entrada
		}

	}
	

	
}

//Version 4
//En esta version se usa el metodo isContinuos
void colorReduce4(Mat imagen, int reduccion = 64) {
	int nl = imagen.rows;
	int nc = imagen.cols;

	if (imagen.isContinuous()) {
		
		nc = nc*nl;
		nl = 1;
	}

	for (int j = 0; j < nl; j++) {
		uchar *data = imagen.ptr<uchar>(j);
		for (int k = 0; k < nc; k++) {
			data[k] = ((data[k] / reduccion) * reduccion) + (reduccion / 2);

		}

	}
}

//Version 
//En esta version se usa el metodo isContinuos y el metodo reshape
void colorReduce5(Mat imagen, int reduccion = 64) {
	int nl = imagen.rows;
	int nc = imagen.cols;

	if (imagen.isContinuous()) {
		imagen.reshape(1, 1);
		int nl = imagen.rows;
		int nc = imagen.cols;
		cout << "LA IMAGEN ES CONTINUA"<<nl<<" "<<nc;
	}
	uchar *data = imagen.ptr<uchar>(1);
		for (int k = 0; k < nc; k++) {
			data[k] = ((data[k] / reduccion) * reduccion) + (reduccion / 2);

		}

	
}


int main(){
	/*
	Mat src = imread("asdf.jpg",CV_LOAD_IMAGE_GRAYSCALE);
	Mat out = src.clone();
		if (src.empty()) {
		cout << "Error no se a podido cargar la imagen" << endl;
	}
	colorReduce(out, 22);
	imshow("Salida", out);
	imshow("Entrada", src);*/

	Mat src = imread("asdf.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	Mat out;
	if (src.empty()) {
		cout << "Error no se a podido cargar la imagen" << endl;
	}
	colorReduce5(src ,22);
	
	imshow("Entrada", src);

	/*VideoCapture video;
	video.open(0);
	Mat frame;
	for (;;) {
		video >> frame;
		colorReduce(frame, 64);
		imshow("salida", frame);
		if (waitKey(33) >= 0)break;
	}*/
	waitKey(0);
	return 0;
}