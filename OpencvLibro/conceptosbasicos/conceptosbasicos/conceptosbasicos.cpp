/*
*En este ejemplo se abordan temas como:
*Puntos
*Fixed Vector
*Fixed Matrix
*Scalar
*Rect

Para ejecutar la seccion hay que descomentarla*/

#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <cstdio>
#include <opencv2/opencv.hpp>

using namespace cv;
using namespace std;

int main(){
	//********************************************* POINT CLASS********************************************************
	//Instanciando Puntos tres diferentes formas
	/*Point2i mypoint = Point(10, 10);
	Point2i my2point;
	Point2i my3point(mypoint);
	float x;

	my2point.x = 121;
	my2point.y = 12;
	//Producti punto
	x = mypoint.dot(my2point);


	cout << "Mypoint is: " << mypoint << endl;
	cout << "My2point is: " << my2point << endl;
	cout << "My3point is: " << my3point << endl;
	//Producto punto
	cout << "Dot product: " << x << endl;
	system("PAUSE");*/
	//***************************************************************************************************************

	//********************************************* SCALAR***********************************************************
	//INSTANCIA DE UN OBJETO TIPO SCALAR
	/*Scalar myscalar = Scalar(1, 2, 3, 4);
	cout << "Myscalar: " << myscalar << endl;
	cout << "Myscalar firs element is: " << myscalar[0] << endl;
	system("PAUSE");*/

	//********************************************** SIZE************************************************************
	/*Size mysz = Size(800, 600);
	cout << "My Size is: " << mysz << endl;
	system("PAUSE");*/

	//********************************************** RECT ***********************************************************

	//Nota: Existe otro objeto que se llama RotatedREct que es lo mismo que rect, con la diferencia que el origenesta en el centro y
    //posse un dato miembro extra el cual es un angulo de rotacion.

	//Primero definire un size
	/*Size sz = Size(500, 500);
	Rect rectangulo = Rect(1, 1,500,500);

	cout << "El area es: " << rectangulo.area() << endl;						//Calculando el area
	cout << "La esquina superior izquierda es: " << rectangulo.tl() << endl;	//La esquina izq. sup
	cout << "La esquina inferior derecha es: " << rectangulo.br() << endl;		//La esquina inf.derecha
	Point2i punto = Point2i(14, 2555);

	if (rectangulo.contains(punto))
		cout << "El rectangulo si contiene el punnto" << endl;
	else
		cout << "El rectangulo no contiene el punnto" << endl;
	

	system("PAUSE");*/
	//************************************************ MATX ****************************************************

	/*Matx33f mymat(1, 3, 5, 7, 9, 11, 13, 15, 2);
	
	cout << "My fixed matrix 3x3 is: " << mymat << endl;
	
	system("PAUSE");*/

	//************************************************ VECTOR Y COMPLEX ****************************************************

	/*Vec3b a(2, 2);
	cout << "My vector is: " << a << endl;
	
	Complexd mycomplex(28, 2);
	cout << "My complex (real part) is: " << mycomplex.re<< endl;
	cout << "My complex  (img part) is: " << mycomplex.im << endl;
	system("PAUSE");*/

	//**************************************************	MAT ****************************************************************

	//Ejemplo de inicializacion de Array con MAT, instancia del objeto, y como se asignan valores con las funciones miembro.
	//Create = Crea las dimensiones y el tipo de la matriz
	//SetTo = Establece el valor inicial de la matriz

	//TAmbien se muestra el proceso de copia de una matriz.
	
	/*Size sz = Size(100, 100);
	Scalar pixel=Scalar(210, 25, 100);
	Mat myarray(sz, CV_8UC3, pixel);
	Mat myarraycopy(myarray);
	//myarraycopy = myarray.clone();
	//myarray.copyTo(myarraycopy);
	
	myarray.setTo(Scalar(255.250,103));
	namedWindow("Myarray", CV_WINDOW_AUTOSIZE);
	namedWindow("Myarray2", CV_WINDOW_AUTOSIZE);
	imshow("Myarray", myarray);
	imshow("Myarray2", myarraycopy);

	
	//cout << "My array is; "<<endl<< myarray << endl;*/


	//************************************************ Analizando Matriz (imagen)

	//cols->width and rows->height
	Mat src1 = imread("bach.jpg");
	Mat output;
	Scalar tarjet(0, 0, 0);
	absdiff(src1, tarjet, output);
	vector<Mat> ch;
	split(output, ch);
	output = ch[0] + ch[1] + ch[2];
	threshold(output, output, 25, 255, THRESH_BINARY_INV);

	namedWindow("Imagen", CV_WINDOW_AUTOSIZE);
	imshow("Imagen", output);
	namedWindow("Imagen1", CV_WINDOW_AUTOSIZE);
	imshow("Imagen1", src1);
	namedWindow("Imagen2", CV_WINDOW_AUTOSIZE);
	imshow("Imagen2", ch[1]);
	namedWindow("Imagen3", CV_WINDOW_AUTOSIZE);
	imshow("Imagen3", ch[2]);
	//cout << "El numero de pixeles es: " << src1.total() << endl;
	//cout << "El numero de canales es: " << src1.channels() << endl;
	//cout << "El numero de filas es: " << src1.rows << endl;
	//cout << "El numero de columnas es: " << src1.cols << endl;
	//cout << "El numero de pixeles es: " << src1.step << endl;				//Ancho efectivo en bytes ej. dara colsxcanales
	//cout << "El tamaño de un pixeles es: " << src1.elemSize() << endl;		//El tamaño de un pixel en bytes por lo general en una imagen de 8bits dara 3 pues cada canal es un byte
	//cout << "El tamaño de un pixeles es: " << src1.cols*src1.channels() << endl;
	//cout << "El es continuos: " << src1.isContinuous() << endl;
	//cout << "El es continuos: " << src1	 << endl;


	waitKey(0);
	//system("PAUSE");
	return 0;
	}
	