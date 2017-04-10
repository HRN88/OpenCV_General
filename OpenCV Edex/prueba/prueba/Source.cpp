#include "opencv2/objdetect/objdetect.hpp"
#include "opencv2/highgui/highgui.hpp"
#include "opencv2/imgproc/imgproc.hpp"
#include <iostream>

using namespace cv;
using namespace std;

int main()
{
	Mat image;
	CvCapture* capture;

	// Read the video stream
	capture = cvCaptureFromCAM(-1);

	// Load Face cascade (.xml file)
	CascadeClassifier face_cascade;
	face_cascade.load("C:/OpenCV243/data/Haarcascades/haarcascade_frontalface_alt2.xml");

	while (1)
	{
		image = cvQueryFrame(capture);
		// Detect faces
		std::vector<Rect> faces;
		face_cascade.detectMultiScale(image, faces, 1.1, 2, 0 | CV_HAAR_SCALE_IMAGE, Size(30, 30));


		// Draw circles on the detected faces
		for (int i = 0; i < faces.size(); i++)
		{
			Point center(faces[i].x + faces[i].width*0.5, faces[i].y + faces[i].height*0.5);
			ellipse(image, center, Size(faces[i].width*0.5, faces[i].height*0.5), 0, 0, 360, Scalar(255, 0, 255), 4, 8, 0);
		}

		imshow("Detected Face", image);
		waitKey(10);
	}

	waitKey(0);
}