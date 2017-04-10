#include<cstdlib>
#include<iostream>
#include<opencv2\opencv.hpp>

using namespace std;
using namespace cv;

class saltfilter{
private: 
	int n; //Cantidad de puntitos en la imagen
	Mat img;

public:
	saltfilter();
	void setParamsFilter(Mat imagen, int n);
	void getParamsFilter();
	Mat salt();


};