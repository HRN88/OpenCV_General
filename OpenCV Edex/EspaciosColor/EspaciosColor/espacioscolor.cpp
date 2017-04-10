#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cstdio>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(){

	//Cargando y comprobando la imagen
	char NombreImagen[] = "flor.jpg"; 
	Mat imRGB, imHSV;

	imRGB = cv::imread(NombreImagen);
	if (!imRGB.data){
		cout << "Error al cargar la imagen" << endl;
		exit(1);
	}

	vector<Mat> bgr_planes;
	split(imRGB, bgr_planes);
	cvtColor(imRGB, imHSV, CV_BGR2HSV);
	
	vector<Mat> hsv_planes;
	split(imHSV, hsv_planes);

	//Mostrando la imagen original

	//namedWindow("ImagenOriginal", CV_WINDOW_AUTOSIZE);
	//imshow("ImagenOriginal", imRGB);

	namedWindow("ImagenOriginal", CV_WINDOW_AUTOSIZE);
	imshow("ImagenOriginal", imHSV);
	//Mostrando los planos independientes BGR
	//namedWindow("B", CV_WINDOW_AUTOSIZE);
	//imshow("B", bgr_planes[0]);
	//namedWindow("G", CV_WINDOW_AUTOSIZE);
	//imshow("G", bgr_planes[1]);
	//namedWindow("R", CV_WINDOW_AUTOSIZE);
	//imshow("R", bgr_planes[2]);

	//Mostrando los planos independientes HSV
	namedWindow("H", CV_WINDOW_AUTOSIZE);
	imshow("H", hsv_planes[0]);
	namedWindow("S", CV_WINDOW_AUTOSIZE);
	imshow("S", hsv_planes[1]);
	namedWindow("V", CV_WINDOW_AUTOSIZE);
	imshow("V", hsv_planes[2]);
	waitKey(0);







	return 0;
}