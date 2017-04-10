#include <cstdlib>
#include<cstdio>
#include<opencv2\opencv.hpp>
#include "Serial.h"
using namespace std;



class ColorDetector{
private:
	string cadena_ ;
	int maxH;
	int minH;
	int maxS;
	int minS;
	int maxV;
	int minV;
	cv::Mat mask;
	char color_;
	

public:
	//Constructores sobrecargados inicializando los valores de HSV, max y min
	ColorDetector():minH(0), maxH(0), minS(0), maxS(0), minV(0), maxV(0){};
	ColorDetector(int minh, int maxh, int mins, int maxs, int minv, int maxv, char color, string cadena);
	void setcolor(int minh, int maxh, int mins, int maxs, int minv, int maxv, char color, string cadena);
	void getcolor();
	void proceso(cv::Mat imagen);
	cv::Mat proceso_inrange(cv::Mat imagen);
	void serialcom();
	void mandastop();
	void proceso_inrange_2(cv::Mat imagen);


};