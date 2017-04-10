#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <iostream>

#include "colordetector.h"

using namespace cv;
using namespace std;
int main()
{
	// 1. Create image processor object
	//ColorDetector cdetect;

	// 2. Read input image
	//cv::Mat image = cv::imread("manzana.jpg");
	//if (image.empty())
	//	return 0;

	// 3. Set input parameters
	//cdetect.setTargetColor(255, 255, 255); // here blue sky

										   // 4. Process the image and display the result
	//cv::namedWindow("result");
	//cv::imshow("result", cdetect.process(image));
	VideoCapture video(0);
	if (!video.isOpened()) {
		cout << "Error al usar la camara";
		return -1;
	}
	ColorDetector cdec;
	cdec.setColorDistanceThreshold(100);
	cdec.setTargetColor(255, 255, 255);
	namedWindow("video", WINDOW_AUTOSIZE);
	namedWindow("original",WINDOW_AUTOSIZE);
	//VideoWriter captura("video", CV_FOURCC('M','J','P','G'), 10, frame
	Mat im;
	Mat org;

	while (1) {
		video >> org;
		video >> im;
		

		imshow("video", cdec.process(im));
		imshow("original", org);
		if (waitKey(1) == 'c') {
			break;
		}
	}


	//cv::waitKey();

	return 0;
}

