// week5.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <opencv2\highgui\highgui.hpp>
#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv\highgui.h>
#include <opencv\cv.h>
#include <iostream>
#include <atlstr.h>
#include <fstream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2\core\core.hpp>
#include <opencv2/imgproc/imgproc.hpp>


using namespace cv;
using namespace std;


//Templates and Polymorphism

//Draw one circle and one box using class structure as follows :

class Box // NO PARENT (2pts)
{
public:
	// some variables
	void draw(IplImage* in)
	{
		CvPoint RP1, RP2;
		RP1.x = 250;
		RP1.y = 250;
		cvDrawCircle(in, RP1, 250, CV_RGB(255, 0, 0), 1, 8, 0);
		cvShowImage("Main window", in);
	}
};
class Circle // NO PARENT (2pts)
{
public:
	// some variables
	void draw(IplImage* in)
	{
		CvPoint RP1, RP2;
		RP1.x = 150;
		RP1.y = 100;
		RP2.x = 170;
		RP2.y = 120;
		cvRectangle(in, RP1, RP2, CV_RGB(255, 0, 0), 1, 8, 0);
		cvShowImage("Main window", in);
	}
};


class GeometricObjectInterface//(3pts)
{
public:
	// implement here
	virtual void draw(IplImage* in) = 0;

};
template <class gana>
class GeometricObject : public GeometricObjectInterface
{
public:
	// implement here
	void draw(IplImage* in)
	{
		gana gg;
		gg.draw(in);
	}

};
// And implement an templatized GeometricObject class. (3pts)
int main()
{

	IplImage* BG_img = cvCreateImage(cvSize(500, 500), 8, 3);
	cvSet(BG_img, cvScalar(255, 255, 255), 0);//white background

	vector<GeometricObjectInterface*> obj_list;
	obj_list.push_back(new GeometricObject<Circle>);
	obj_list.push_back(new GeometricObject<Box>);
	for (auto itr : obj_list)
		itr->draw(BG_img);
	waitKey(0);
	return 0;
}










