#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cstdio>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(){
	char NombreImagen[] = "componentes.jpg";
	char NombreModelo[] = "pata.jpg";

	Mat src = imread(NombreImagen);
	Mat templ = imread(NombreModelo);

	if (!src.data || !templ.data){
		cout << "Error al cargar la imagen" << endl;
		exit(1);
	}

	//Matriz destino
	Mat dst;

		//Se reseva memoria para las matrices resultado (metodos), aqui investigar por que es la operacion del ancho y alto de la imagen original - el 
		//anncho y alto del modelo

	int iwidth = src.cols - templ.cols + 1;
	int iheight = src.rows - templ.rows + 1;
	
	dst.create(iheight, iwidth, CV_32FC1);
	int match_method = CV_TM_SQDIFF;

	//Realizando la operacion de correlacion

	matchTemplate(src, templ, dst, match_method);
	normalize(dst, dst, 0, 1, NORM_MINMAX, -1, Mat());
	double minVal, maxMal;
	
	Point minLoc, maxLoc;
	Point matchLoc;

	minMaxLoc(dst, &minVal, &maxMal, &minLoc, &maxLoc, Mat());

	if (match_method == CV_TM_SQDIFF || match_method == CV_TM_SQDIFF_NORMED){
		matchLoc = minLoc;
	}
	else{
		matchLoc = maxLoc;
	}

	rectangle(src, matchLoc, Point(matchLoc.x + templ.cols, matchLoc.y + templ.rows), Scalar(255, 0, 0), 4, 8, 0);
	rectangle(dst, Point(matchLoc.x - (templ.cols / 2), matchLoc.y - (templ.rows / 2)), Point(matchLoc.x + (templ.cols / 2), matchLoc.y + (templ.rows / 2)), Scalar::all(0), 4, 8, 0);

	imshow("src", src);
	imshow("Result", dst);
	imshow("templ", templ);

	cout << "iwidth " << iwidth << endl;
	cout << "iheightc" << iheight << endl;
	cout << "minval " << minVal << endl;
	cout << "maxval " << maxMal << endl;
	cout << "minloc " << minLoc << endl;
	cout << "maxloc " << maxLoc << endl;
	//cout << "dst" << dst << endl;
	//Esperar a pulsar una tecla
	cvWaitKey(0);

	return 0;
}