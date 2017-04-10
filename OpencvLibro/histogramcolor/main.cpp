#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cstdio>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;


int main(){
	char Imagen[] = "camaleon.jpg";
	Mat img, b_hist,g_hist,r_hist;
	img = imread(Imagen);
	if (img.empty()) {
		cout << "Error al cargar la imagen" << endl;
	}

	vector<Mat> channels;
	split(img, channels);
	int tamaño = 255 ;
	float rango[] = { 0.0 , 256.0 };
	const float *histRange = { rango };

	calcHist(&channels[0], 1, 0, Mat(), b_hist,1, &tamaño, &histRange, true,false);
	namedWindow("Camaleon", WINDOW_AUTOSIZE);
	imshow("Camaleon", img);
	
	waitKey(0);
	

	return 0;
}