#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cstdio>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;



Mat normalizRGB(Mat &imagen) {;
	int ncols = imagen.cols;
	int nrows = imagen.rows;
	for (int i = 0; i < nrows; i++) {
		for (int j = 0; j < ncols; j++) {
			int bval = imagen.at<Vec3b>(i, j)[0];
			int gval = imagen.at<Vec3b>(i, j)[1];
			int rval = imagen.at<Vec3b>(i, j)[2];
			double suma = bval + gval + rval;
			imagen.at<Vec3b>(i, j)[0] = bval / suma*255;
			imagen.at<Vec3b>(i, j)[1] = gval / suma*255;
			imagen.at<Vec3b>(i, j)[2] = rval / suma*255;
		}
	}

	return imagen;
	
}

int main(){
	Mat escena;
	VideoCapture frame;
	frame.open(0);
	for (;;) {
		frame >> escena;
		imshow("RGB normalizado",normalizRGB(escena));
		if (waitKey(30) > 0) break;
	}
	

	system("PAUSE");
	return 0;
}