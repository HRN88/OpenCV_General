/*En este programa se veran las interacciones del mouse en los programas*/
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cstdio>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

unsigned char scrColor = 255;
;
Size sz = Size(500, 500);
Mat screen(sz, CV_8U, scrColor);
Mat draw(sz, CV_8U);


void onMouse(int event, int x, int y, int flags, void *param){
	if (event == CV_EVENT_LBUTTONUP){
		scrColor = ~scrColor;
		screen.setTo(scrColor);
		circle(screen, Point(x, y), 40, 180, 3);
		putText(screen, "Circulo", Point(x, y), FONT_HERSHEY_PLAIN, 1, 180, 1);
		imshow("SCREEN", screen);
		cout << "Mouse Position" << endl << "x = " << x << " Y = " << y << endl;
		
	}
		
}

int main(){
	
	namedWindow("SCREEN", CV_WINDOW_AUTOSIZE);
	setMouseCallback("SCREEN", onMouse);
	waitKey(0);	

	return 0;
	}

	

