#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cstdio>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

void detectHScolor(const Mat &image, double miniHue, double maxHue, double minSat, double maxSat, Mat & mask) {
	//Convierte de BGR a HSV
	Mat hsv;
	cvtColor(image, hsv, CV_BGR2HSV);
	//Dividiendo en los canales, Matiz, Saturacion, Valor
	vector<Mat> channels;
	split(hsv, channels);
	//Mascara de Matiz
	Mat mask1;
	threshold(channels[0], mask1, maxHue, 255, CV_THRESH_BINARY_INV);
	Mat mask2;
	threshold(channels[0], mask2, miniHue, 255, CV_THRESH_BINARY);
	Mat hueMask;
	if (miniHue < maxHue)
		hueMask = mask1 & mask2;
	else
		hueMask = mask1 | mask2;
	//Mascara de saturacion
	threshold(channels[1], mask1, maxSat, 255, THRESH_BINARY_INV);
	threshold(channels[1], mask2, minSat, 255, THRESH_BINARY);
	Mat satMask;
	satMask = mask1 & mask2;
	mask = hueMask&satMask;
}
int main(){
	char Nombre[] = "circulos.jpg";
	Mat imagen = imread(Nombre);
	if (imagen.empty()) {
		cout << "Error al cargar la imagen"<<endl;
		return -1;
	}
	namedWindow("Sophie", WINDOW_AUTOSIZE);
	imshow("Sophie", imagen);
	Mat mask;
	detectHScolor(imagen, 0, 75, 25, 255, mask);
	Mat detected(imagen.size(), CV_8UC3, Scalar(0,0,0));
	imagen.copyTo(detected, mask);
	namedWindow("Sophied", WINDOW_AUTOSIZE);
	imshow("Sophied", detected);


	waitKey(0);
	

	return 0;
}