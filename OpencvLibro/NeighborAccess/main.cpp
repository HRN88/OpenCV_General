/*En este ejemplo se muestra la tecnica "Neighbor Access la cual consiste en
acceder a un pixel y a los pixeles vecinos proximos. Esto con el fin de realizar operaciones.
Un ejemplo es la realizacion de filtros (mediante convolucion)
En este caso se realiza un filtro que resalta los bordes de uuna imagen*/

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cstdio>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void sharpen(const Mat &imagen, Mat &result);
int main(){
	char NombreImagen[] ="4k.jpg";
	Mat img = imread(NombreImagen);
	Mat salida;
	if (img.empty()) {
		cout << "Error al abrir la imagen" << endl;
		return -1;
	}

	sharpen(img, salida);
	namedWindow("Source", WINDOW_AUTOSIZE);
	imshow("Source", salida);
	
	waitKey(0);

	

	return 0;
}

void sharpen(const Mat &imagen,  Mat &result) {
	result.create(imagen.size(), imagen.type());
	int nchannels = imagen.channels();
	for (int j = 1; j < (imagen.rows) - 1; j++) {
		const uchar *previous = imagen.ptr<uchar>(j - 1);
		const uchar *current = imagen.ptr<uchar>(j);
		const uchar *next = imagen.ptr < uchar>(j + 1);
		uchar *output = result.ptr<uchar>(j);
		for (int i = nchannels; i < (imagen.cols - 1)*nchannels; i++) {
			*output++ = saturate_cast<uchar>(5 * current[i] - current[i - nchannels] - current[i + nchannels] - previous[i] - next[i]);

		}

	}
	result.row(0).setTo(Scalar(255,0,0));
	result.row(result.rows-1).setTo(Scalar(255, 0, 0));
	result.col(0).setTo(Scalar(255, 0, 0));
	result.col(result.cols-1).setTo(Scalar(255, 0, 0));

}