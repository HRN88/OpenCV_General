#include <cstdlib>
#include<cstdio>
#include<opencv2\opencv.hpp>
#include"saltfilter.h"

using namespace std;
using namespace cv;

int main(){

	Mat imagen = imread("catedral.jpg", CV_LOAD_IMAGE_GRAYSCALE);
	if (imagen.empty()){
		cout << "Error al cargar la imagen" << endl;
	}
	saltfilter filtro;
	filtro.setParamsFilter(imagen, 96789);
	filtro.getParamsFilter();
	imshow("Salida", filtro.salt());

	
	
	waitKey(0); 

	

	
}
