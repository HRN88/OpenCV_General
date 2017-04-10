#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cstdio>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;


int main(){
	char NombreImagen[] = "ojo.jpg";
	Mat imagen = imread(NombreImagen);
	if (imagen.empty()){
		-1;
	}
	namedWindow("Ojo", WINDOW_AUTOSIZE);
	imshow("Ojo", imagen);
	cout << "Esta imagen tiene: " << imagen.channels() << " canales" << endl;
	waitKey(0);
	destroyWindow("Ojo");
	


	return 0;
}