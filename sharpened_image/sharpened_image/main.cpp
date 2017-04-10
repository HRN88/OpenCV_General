#include <cstdlib>
#include<cstdio>
#include<opencv2\opencv.hpp>
using namespace std;
using namespace cv;	

//funcion para resaltar bordes de una imagen, utiliza el metodo del escaneo por vecinos (pixeles vecinos)
void sharpened(const Mat &imagen, Mat &salida){
	salida.create(imagen.size(), imagen.type());
	int nchannels = imagen.channels();
	for (int j = 1; j < imagen.rows-1; j++){
		//Apuntadores a las filas previa, actual y siguiente
		const uchar *previous = imagen.ptr<const uchar>(j - 1);
		const uchar *current = imagen.ptr<const uchar>(j);
		const uchar *next = imagen.ptr<const uchar>(j + 1);
		uchar *output = salida.ptr<uchar>(j);
		for (int i = nchannels; i < (imagen.cols - 1)*nchannels; i++){
			*output++ = saturate_cast<uchar>(4 * current[i] - current[i - nchannels] - current[i + nchannels] - previous[i] - next[i]);
		}

	}
	salida.row(0).setTo(Scalar(0));
	salida.row(salida.rows - 1).setTo(Scalar(0));
	salida.col(0).setTo(Scalar(0));
	salida.col(salida.cols - 1).setTo(Scalar(0));


}

//Funcion para realzar los bordes de una imagen usando la funcion filter2D de openCV

void sharpened2(const Mat imagen, Mat salida, int Kernelsize){
	Mat kernel(Kernelsize, Kernelsize, CV_8UC1);

}
int main(){
	Mat imagen = imread("manzanas.jpg");
	Mat salida;

	sharpened(imagen, salida);
	imshow("salida", salida);
	imshow("Entrada", imagen);

	
	waitKey(0); 

	

	
}
