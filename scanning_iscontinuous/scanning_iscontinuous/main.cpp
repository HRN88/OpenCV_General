#include <cstdlib>
#include<cstdio>
#include<opencv2\opencv.hpp>

using namespace std;
using namespace cv;


//Test 1
//Escaneo eficioente, aprovechando la continuidad de la imaen

void colorReduce1(Mat imagen, int n){
	int nl = imagen.rows;
	int nc = imagen.cols*imagen.channels();
	cout << "La imagen tiene " << nl << "lineas y "<<nc/3<<"columnas" << endl;

	if (imagen.isContinuous()){
		cout << imagen.isContinuous() << endl;
		nc = nl*nc;
		nl = 1;
	}
	
	for (int j = 0; j < nl; j++){
		uchar *valor = imagen.ptr<uchar>(j);
		for (int i = 0; i < nc; i++)
		{
			valor[i] = (valor[i] / n)*n + n / 2;

		}
	}

}
//Test 2
//Usando la reconstruccion de la imagen con el metodo reshape()
void colorReduce2(Mat imagen, int n){
	
	

	if (imagen.isContinuous()){
		imagen.reshape(1,1);
	}
	int nl = imagen.rows;
	int nc = imagen.cols*imagen.channels();
	cout << "La imagen tiene " << nl << "lineas y " << nc / 3 << "columnas" << endl;

	for (int j = 0; j < nl; j++){
		uchar *valor = imagen.ptr<uchar>(j);
		for (int i = 0; i < nc; i++)
		{
			valor[i] = (valor[i] / n)*n + n / 2;

		}
	}

}

void colorReduce3(cv::Mat image, uchar div) {

	int nl = image.rows; // number of lines
	int nc = image.cols * image.channels(); // total number of elements per line
	int n = static_cast<int>(log(static_cast<double>(div)) / log(2.0) + 0.5);
	// mask used to round the pixel value
	uchar mask = 0xFF << n; // e.g. for div=16, mask= 0xF0
	uchar div2 = div >> 1;

	for (int j = 0; j<nl; j++) {

		uchar* data = image.ptr<uchar>(j);

		for (int i = 0; i<nc; i++) {

			// process each pixel ---------------------

			*data &= mask;     // masking
			*data++ += div2;   // add div/2

			// end of pixel processing ----------------

		} // end of line
	}
}

int main(){
	Mat img = imread("cat.jpg");
	colorReduce3(img, 64);
	imshow("Salida", img);

	
	waitKey(0); 

	

	
}
