#include <opencv2/opencv.hpp>
#include <iostream>
#include <string.h>
#define _CRT_SECURE_NO_WARNINGS

using namespace cv;
using namespace std;

string s, s2;

FILE *stream;


int main(int argc, char** argv)
{
	freopen_s(&stream, "input.txt", "r", stdin);

	for (int i = 1; i <= 1500; i++)
	{
		


		cin >> s;

		// Read the image file


		Mat src = imread(s); //load  image

		Mat bgr[3];   //destination array
		split(src, bgr);//split source  

		cin >> s2;

		//Note: OpenCV uses BGR color order
		//imwrite(s2, bgr[0]); //blue channel
		//mwrite("D:/green.png", bgr[1]); //green channel
		imwrite(s2, bgr[2]); //red channel

	}

	return 0;
}