#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cstdio>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(){
	//Para leer video primero creamos la ventana
	char NombreVideo[] = "vine.avi";

	namedWindow("Video de vine", CV_WINDOW_AUTOSIZE);

	//Instanciamos el objeto VideoCapture que nos permite trabajar con video
	VideoCapture video;
	//iniciamos la captura del video...Open video file or a capturing device for video capturing

	video.open(NombreVideo);

	//Instancia del objeto tipo mat llamado frame para almacenar las lecturas del video.
	Mat frame;
	for (;;){
		video >> frame;
		if (frame.empty())
			break;
		imshow("Video de vine", frame);
		if (waitKey(33) > 0) break;
	}




	return 0;
}