#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cstdio>
#include <opencv2/opencv.hpp>
#include "HistogramBN.h" 
using namespace cv;
using namespace std;


int main(){
	//Cargando la imagen
	char Imagen[] = "guitarra.jpg";
	Mat imag;
	imag = imread(Imagen, CV_LOAD_IMAGE_GRAYSCALE);
	if (imag.empty()) {
		cout << "Error al cargar la imagen" << endl;
		
	}

	Mat hs;			//creando matriz para almacenar el histograma 
	HistogramBn histo; //Creando instancia del objeto
	hs = histo.getHistogram(imag); //Calculo del histograma

	//Podemos ver el valor del histograma si recorremos la matriz hs
	float sum = 0;
	for (int i = 0; i < 256; i++) {
		cout << "Valor" << i << "=" << hs.at<float>(i) << endl;
		sum = sum + hs.at<float>(i);
	}
	
	cout << sum << endl;
	// los valores que se imprime son los pixeles que tiene cada contenedor.
	//Pero a nosotros no nos sirve en forma de lista, es mejor la visualizacion
	//de manera grafica.

	

	namedWindow("Imagen", WINDOW_AUTOSIZE);
	imshow("Imagen", imag);
	namedWindow("asdf");
	//Se llama el metodo para visualizar el histograma de manera grafica
	imshow("asdf", histo.getHistogramImage(imag));
	//De acuerdo al histograma la imagen tiene una grancantidad de pixeles que tienden al color negro
	//Ahora usaremos la funcion threshold para separar los pixeles mas oscuros

	Mat tresholdimg;
	threshold(imag, tresholdimg, 60, 255, THRESH_BINARY);
	namedWindow("Imgthreshold", WINDOW_AUTOSIZE);
	imshow("Imgthreshold", tresholdimg);
	cout << "Rows: " << hs.rows << " " << "Cols:" << hs.cols << endl;

	/********************************************************
	*		LOOK UP TABLES
	*
	********************************************************/
	/*Creando una tabla de inversion*/
	int dim(256);
	Mat lut(1, &dim, CV_8U);
	/*Inicializando la tabla*/
	for (int i = 0; i < dim; i++) {
		lut.at<uchar>(i) = 255 - i;
	}
	/*Cargando una imagen*/
	char Nombre[] = "chica.jpg";
	Mat imagen = imread(Nombre);
	Mat salidalut;
	HistogramBn lookup;
	salidalut = lookup.applyLookUp(imagen, lut);
	namedWindow("lut", CV_WINDOW_AUTOSIZE);
	imshow("lut", salidalut);

	/********************************************************
	*			STRETCH IMAGE CON LUT
	*
	********************************************************/
	char Nimg[] = "guitarra.jpg";
	Mat img,histos;
	img = imread(Nimg, CV_LOAD_IMAGE_GRAYSCALE);
	namedWindow("orig", CV_WINDOW_AUTOSIZE);
	namedWindow("orighist", CV_WINDOW_AUTOSIZE);
	imshow("orig", img);
	
	HistogramBn myhist,a;
	histos = myhist.getHistogramImage(img);
	imshow("orighist", histos);
	Mat stretched = myhist.stretch(img, 0.01f);
	namedWindow("stretch", CV_WINDOW_AUTOSIZE);
	imshow("stretch", stretched);
	namedWindow("a", CV_WINDOW_AUTOSIZE);
	imshow("a", a.getHistogramImage(stretched));


	waitKey(0);
	return 0;
}