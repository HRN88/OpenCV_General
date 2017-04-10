#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cstdio>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(){
	//Cargando las imagenes
	char NomImg1[] = "luna.jpg";
	char NomImg2[] = "espacio.jpg";

	Mat img1, img2;
	img1 = cv::imread(NomImg1);
	img2 = cv::imread(NomImg2);

	if (!img1.data || !img2.data){
		cout << "Error al cargar alguna imagen" << endl;
		exit(1);
	}

	Mat src;

	add(img1, img2, src, noArray(), -1);

	namedWindow("img1", CV_WINDOW_AUTOSIZE);
	imshow("img1", img1);
	namedWindow("img2", CV_WINDOW_AUTOSIZE);
	imshow("img2", img2);

	//add(img1, img2, src, noArray(), -1);
	//subtract(img1, img2, src, noArray(), -1);
	//multiply(img1, img2, src, 100);
	divide(img1, img2, src, (100), - 1);
	
	namedWindow("salida", CV_WINDOW_AUTOSIZE);
	imshow("salida", src);
	imwrite("lunasumada.jpg", src);
	waitKey(0);



	return 0;
}