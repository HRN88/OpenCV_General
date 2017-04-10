//VERSION 1.1 
#include "Serial.h"
#include <cstdlib>
#include <cstdio>
#include <opencv2\opencv.hpp>
#include "colordetector.h"
using namespace std;


//Variables para almacenar los valores de HSV maximos y minimos
int maxH = 20;
int minH = 0;
int maxS = 255;
int minS = 0;
int minV = 0;
int maxV = 255;
//Matriz para visualizar el color
cv::Mat color(cv::Size(400, 300), CV_8UC3, cv::Scalar(0, 0, 0));

//Evento disparado al detectar cambios en la barra
void on_trackbar(int, void*){
	//Muestra el recudro de color en la ventana del controlador
	color = cv::Scalar(maxH, maxS, maxV);
	cvtColor(color, color, CV_HSV2BGR);
	imshow("Calibracion", color);

}

//Crea la ventana de calibracion
void calibracion(){
	//Ventana de calibracion
	namedWindow("Calibracion", cv::WINDOW_AUTOSIZE);
	//Barras de calibracion para H, S, V
	cv::createTrackbar("maxH", "Calibracion", &maxH, 180, on_trackbar);
	cv::createTrackbar("minH", "Calibracion", &minH, 180, on_trackbar);
	cv::createTrackbar("maxS", "Calibracion", &maxS, 255, on_trackbar);
	cv::createTrackbar("minS", "Calibracion", &minS, 255, on_trackbar);
	cv::createTrackbar("maxV", "Calibracion", &maxV, 255, on_trackbar);
	cv::createTrackbar("minV", "Calibracion", &minV, 255, on_trackbar);


}


int main(){
	CSerial serial;
	int detecta = 0;
	cv::Mat orig;
	//Para la calibracion poner la funcion setcolor en el bucle, para la deteccion va fuera del bucle, antes del for
	//calibracion();
	cv::Mat escena;
	ColorDetector rojo, rosa, amarillo, lila, celeste, guinda, cobalto, naranja, purpura, verde, limon, stop, color;
	cv::VideoCapture captura;
	captura.open(0);

	//C y C#
	rojo.setcolor(0, 180, 221, 255, 114, 156, 'C', "Rojo");
	rosa.setcolor(164, 180, 201, 226, 165, 215, 'c', "Rosa");
	//D y D#
	amarillo.setcolor(22, 24, 206, 235, 126, 200, 'D', "Amarillo");
	lila.setcolor(121, 133, 55, 109, 83, 126, 'd', "Lila");
	//E
	celeste.setcolor(101, 116, 118, 155, 101, 134, 'E', "Celeste");
	//F y F#
	guinda.setcolor(0, 4, 188, 242, 70, 100, 'F', "Guinda");
	cobalto.setcolor(106, 121, 151, 211, 0, 78, 'f', "Cobalto");
	//G y G#
	naranja.setcolor(4, 9, 214, 255, 139, 254, 'G', "Naranja");
	purpura.setcolor(153, 165, 143, 201, 68, 95, 'g', "Purpura");
	//A y A#
	verde.setcolor(67, 79, 170, 255, 46, 76, 'A', "Verde");
	limon.setcolor(29, 37, 143, 206, 105, 143, 'a', "V.Limon");
	//Stop
	stop.setcolor(0, 180, 0, 255, 0, 19, 's', ".");
	 char dato = 'x';
	 static char *apuntador = NULL;
	for (;;){
		//Captura frames
		captura >> escena;
		escena.copyTo(orig);
		cvtColor(escena, escena, CV_BGR2HSV);
		//color.setcolor(minH, maxH, minS, maxS, minV, maxV, 'x', "prueba");
		imshow("Salida", stop.proceso_inrange(escena));
		imshow("Salida", rojo.proceso_inrange(escena));
		imshow("Salida", rosa.proceso_inrange(escena));
		imshow("Salida", amarillo.proceso_inrange(escena)); 
		imshow("Salida", lila.proceso_inrange(escena));
		imshow("Salida", celeste.proceso_inrange(escena));
		imshow("Salida", guinda.proceso_inrange(escena));
		imshow("Salida", cobalto.proceso_inrange(escena));
		imshow("Salida", naranja.proceso_inrange(escena));
		imshow("Salida", purpura.proceso_inrange(escena));
		imshow("Salida", verde.proceso_inrange(escena));
		imshow("Salida", limon.proceso_inrange(escena));
		imshow("Salida", color.proceso_inrange(escena));
		imshow("Entrada", orig);
		/*rojo.proceso_inrange_2(escena);
		rosa.proceso_inrange_2(escena);
		amarillo.proceso_inrange_2(escena);
		lila.proceso_inrange_2(escena);
		celeste.proceso_inrange_2(escena);
		guinda.proceso_inrange_2(escena);
		cobalto.proceso_inrange_2(escena);
		naranja.proceso_inrange_2(escena);
	    purpura.proceso_inrange_2(escena);
		verde.proceso_inrange_2(escena);
		limon.proceso_inrange_2(escena);
		color.proceso_inrange_2(escena); 
		stop.proceso_inrange_2(escena);*/
		if (cv::waitKey(30) >= 0) break;
	}
	
}
