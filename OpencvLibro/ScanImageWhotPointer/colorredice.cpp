/*En este ejemplo se reduce el color de un imagen accediendo de manera individual a cada pixel y modificando su color. 
/*Existen diversas formas de escanear una imagen y acceder a sus pixeles de manera individial. Tambien existen:
/*Usando un puntero para acceder a la direccion de cada fila (con bucle por casa fila)
/*Usando un puntero para acceder a la direccion de 1 fila (si la imagen es continua)
/*Usando iteradores

/*Hay diversas formulas para reducir el color:
/*Dividir cada pixel por un factor entero
/*Usando la operacion modulo en cada pixel
/*Por corrimiento de bits 
/
/*****De los metodos anterores el mas lento es el de iteradores, qudando en primer lugar el de dividion entera.
*/

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cstdio>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

//Declaracion de las funciones

void ColorReduce(Mat imagen, int div);
void ColorReduceContinuos(Mat imagen, int div);
void ColorReduceIterator(Mat imagen, int div);

int main(){
	//Carga y verificacion de la imagen
	char NombreImagen[] = "4k.jpg";
	Mat img = imread(NombreImagen);
	if (img.empty()) {
		cout << "Error al leer la imagen" << endl;
		return -1;
	}
	//Creando copia de la imagen
	Mat clon = img.clone();
	//Se verifica si es continua, esto para usar la funcion ColorReduceContinous
	cout << "La imagen es continua?: " << clon.isContinuous() << endl; 
	//Inicia un contador para saber el tiempo en ms en que se ejecutan los calculos
	const int64 start = getTickCount();
	//LLamada a la funcion para reducir el color
	ColorReduceIterator(clon,128);
	double duration = ((getTickCount() - start )/ getTickFrequency());
	cout << "Time elapsed: " << duration;
	//Imprime la duracion de los calculos y muestra la imagen original y la editada
	namedWindow("Reduccion", WINDOW_AUTOSIZE);
	imshow("Reduccion", clon);
	namedWindow("Original", WINDOW_AUTOSIZE);
	imshow("Original", img);
	waitKey(0);	

	return 0;
}

//Funcion para reducior el color, no se verifica si la imagen es continua, se exponen las tres 
//formulas de reduccion de color

void ColorReduce(Mat imagen, int div) {
	int nl = imagen.rows; //Numero de filas
	int nc = imagen.cols * imagen.channels(); //Niumero de pixeles por fila
	for (int j = 0; j < nl; j++) {
		//Obtenemos la direccion de la fila
		uchar* data = imagen.ptr<uchar>(j);
		uchar mask = 0xFF << div;
		for (int i = 0; i < nc; i++) {
			//Se muestran diferentes formulas para la reduccion del color
			data[i] = data[i] / div*div + div / 2;  //97.0
			//data[i] = data[i] - data[i] % div + div / 2; //107
			//*data &= mask;
			//*data++ += div >> 1;
		}
	}
}

//Funcion para reducir el color, se verifica si la imagen es continua
void ColorReduceContinuos(Mat imagen, int div) {
	
	if (imagen.isContinuous()) {
		imagen.reshape(3, 1);
	}
	int nl = imagen.rows;
	int nc = imagen.cols*imagen.channels();
	for (int j = 0; j < nl; j++) {
		uchar *data = imagen.ptr<uchar>(j);
		for (int i = 0; i < nc; i++) {
			data[i] = data[i] / div*div + div / 2;

		}
	}

}

//Esta funcion usa iteradores para modificar los pixeles
void ColorReduceIterator(Mat imagen, int div) {
	//Iterador en pocicion inicial de la imagen
	Mat_<Vec3b>::iterator it = imagen.begin<Vec3b>();
	//Iterador en pocicion final de l a imagen
	Mat_<Vec3b>::iterator itend = imagen.end<Vec3b>();
	//Loop a todos los pixeles
	while (it != itend) {
		//Procesando cada pixel
		(*it)[0] = ((*it)[0] / div*div + div / 2);
		(*it)[1] = ((*it)[1] / div*div + div / 2);
		(*it)[2] = ((*it)[2] / div*div + div / 2);
		it++;
	}

}

