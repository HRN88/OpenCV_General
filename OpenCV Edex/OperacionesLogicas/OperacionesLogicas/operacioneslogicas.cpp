#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cstdio>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(){

	/*Mat img1 = Mat::zeros(Size(400, 200), CV_8UC1);
	Mat img2 = Mat::zeros(Size(400, 200), CV_8UC1);*/

	/*img1(Range(0, img1.rows), Range(0, img1.cols / 2)) = 225;
	imshow("img1", img1);
	img2(Range(100, 150), Range(150, 350)) = 255;
	imshow("img2", img2);*/

	char img_1[] = "luna.jpg";
	char img_2[] = "espacio.jpg";
	Mat img1, img2, res;

	img1 = cv::imread(img_1);
	img2 = cv::imread(img_2);

	if (!img1.data || !img2.data){
		cout << "Error al cargar alguna imagen" << endl;
		waitKey(0);
		
	}

	//bitwise_and(img1, img2, res);
	//bitwise_or(img1, img2, res);
	//bitwise_xor(img1, img2, res);
	bitwise_not(img2, res);
	namedWindow("resultado", CV_WINDOW_AUTOSIZE);
	imshow("resultado", res);
	waitKey(0);





	return 0;
}