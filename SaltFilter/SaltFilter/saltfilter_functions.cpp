#include<cstdlib>
#include<iostream>
#include<opencv2\opencv.hpp>
#include"saltfilter.h"
#include<time.h>
using namespace std;
using namespace cv;

saltfilter::saltfilter(){

}
void saltfilter::setParamsFilter(Mat imagen, int numero){
	n = numero;
	img = imagen;
}

void saltfilter::getParamsFilter(){
	cout << "El valor de n es: " << n << endl;
	imshow("Iimagen", img);
}

Mat saltfilter::salt(){

	int x = 0;
	int y = 0;
	srand(time(NULL));
	for (int j = 0; j <= n; j++){
		
		x = rand() % (img.cols);
		y = rand() % (img.rows);
		if (img.type() == CV_8UC3){
			
			if (j % 2 == 0){
				
				img.at<Vec3b>(y, x)[0] = 255;
				img.at<Vec3b>(y, x)[1] = 0;
				img.at<Vec3b>(y, x)[2] = 255;
			}
			else{
			
				img.at<Vec3b>(y, x)[0] = 0;
				img.at<Vec3b>(y, x)[1] = 255;
				img.at<Vec3b>(y, x)[2] = 0;

			}


		}
		else {
			if (j % 2 == 0)
				img.at<uchar>(y, x) = 255;
			else
				img.at<uchar>(y, x) = 0;

		}
	}
	cout << img.type() << endl;

	return img;
}
