#if !define COLORDETECT
#define COLORDETECT

#include <opencv2/core/core.hpp>
#include <opencv2/imgproc/imgproc.hpp>
using namespace cv;

//Definicion de la clase ColorDetector
class ColorDetector {
private:
	int maxDist;
	Vec3b target;
	Mat result;

public:
	ColorDetector():maxDist(100), target(0, 0, 0) {}
		
	int getDistanceToTargetColor(const Vec3b &color) const {
		return getColorDistance(color, target);
	}
	int getColorDistance(const Vec3b &color1, const Vec3b &color2) const {
		return abs(color1[0] - color2[0]) + abs(color1[1] - color2[1]) + abs(color1[2] - color2[2]);
	}
	Mat process(const Mat &image);

	//Funciones Getters and Setters para que el usuario defina sus
	//parametros

	void setTargetColor(uchar blue, uchar green, uchar red) {
		target = Vec3b(blue, green, red);
	}
	void setColorDistanceThreshold(int distance) {
		if (distance < 0) {
			distance = 0;
			maxDist = distance;
		}
	}
	int getColorDistanceThreshold() const {
		return maxDist;
	}


};
Mat ColorDetector::process(const cv::Mat &image) {

	// re-allocate binary map if necessary
	// same size as input image, but 1-channel
	result.create(image.size(), CV_8U);

	// Converting to Lab color space 


	// get the iterators
	cv::Mat_<cv::Vec3b>::const_iterator it = image.begin<cv::Vec3b>();
	cv::Mat_<cv::Vec3b>::const_iterator itend = image.end<cv::Vec3b>();
	cv::Mat_<uchar>::iterator itout = result.begin<uchar>();

	// get the iterators of the converted image 
	

	// for each pixel
	for (; it != itend; ++it, ++itout) {

		// process each pixel ---------------------

		// compute distance from target color
		if (getDistanceToTargetColor(*it)<maxDist) {

			*itout = 255;

		}
		else {

			*itout = 0;
		}

		// end of pixel processing ----------------
	}

	return result;
}
#endif