/*En este ejemplo se muestran los resultados de los diferentes espacios de color.*/
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cstdio>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;


int main(){
	char Imagen[] = "buenosaires.jpg";
	Mat src;
	Mat xyz;
	vector<Mat> channels;
	src = imread(Imagen);
	if (src.empty()) {
		cout << "Error al cargar la imagen";
		return 0;
	}
	cvtColor(src, xyz, CV_BGR2HSV);
	split(xyz, channels);
	namedWindow("Input BGR", WINDOW_AUTOSIZE);
	namedWindow("Output XYZ", WINDOW_AUTOSIZE);
	imshow("Input BGR", src);
	imshow("Output XYZ", xyz);

	namedWindow("X", WINDOW_AUTOSIZE);
	imshow("X", channels[0]);
	namedWindow("Y", WINDOW_AUTOSIZE);
	imshow("Y", channels[1]);
	namedWindow("Z", WINDOW_AUTOSIZE);
	imshow("Z", channels[2]);
	waitKey(0);
	


	return 0;
}