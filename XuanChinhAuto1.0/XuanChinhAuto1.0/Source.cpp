#include <iostream>
#include <windows.h>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;
#include <string>

int main(int argc, char* argv[])
{
	WIN32_FIND_DATA search_data;

	memset(&search_data, 0, sizeof(WIN32_FIND_DATA));

	cout << "Enter your Image Folder 's path: ";
	cout << "(E.g: D:" << (char)92 << "Images):" << endl;
	char rootdir[256];
	cin.getline(rootdir, 256);
	
	int l;

	for (l = 0; rootdir[l] != '\0'; l++);

	for (int i = l; i >= 4; i--)
	{
		rootdir[i] = rootdir[i - 1];
		if (rootdir[i] == 92) rootdir[i] = 47;
	}

	rootdir[3] = 92;
	rootdir[l + 1] = 47;
	rootdir[l + 2] = '\0';

	char im[] = "*.jpg";

	for (int i = 0; i < 5; i++) rootdir[l + 2 + i] = im[i];
	rootdir[l + 2 + 5] = '\0';
	

	// << rootdir;

	HANDLE handle = FindFirstFile(rootdir, &search_data);
	/*
	Replace *.* with: *.jpg to find all .jpg file in folder
					  *.png to find all .png file in forlder
					  *.* to find all file
	 */

	char xc[256];

	cout << "Enter XuanChinh.png 's url (Eg: D:" << (char)92 << "XuanChinh.png): " << endl;
	cin.getline(xc, 256);
	for (int i = 0; i < 256; i++) if (xc[i] == 92) xc[i] = 47;

	Mat XuanChinh = imread(xc, - 1); //-1: load 4 channels
	if (XuanChinh.at<Vec4b>(1000, 1000).val[0] + XuanChinh.at<Vec4b>(1000, 1000).val[1] + XuanChinh.at<Vec4b>(1000, 1000).val[2] != 117)
	{
		cout << "Not an image of Xuan Chinh idol!";
		return -1;
	}
	//cout << XuanChinh.channels();
	cout << endl << "Good job. Scanning your folder for background image..." << endl << endl;

	while (handle != INVALID_HANDLE_VALUE)
	{
		cout << "Finding your next file..." << endl;
		cout << "Found " << search_data.cFileName << ". Processing..." << endl;
		Mat image2 = XuanChinh;
		//cout << image2.channels();

		char link[260];
		for (int i = 0; i <= l; i++) link[i] = rootdir[i];
		for (int i = 3; i <= l - 1; i++)
			link[i] = link[i + 1];
		link[2] = 47;
		link[l] = 47;
		link[l + 1] = '\0';
		//cout << link;
		for (int i = 0; search_data.cFileName[i] != '\0'; i++) 
		{
			link[l + 1 + i] = search_data.cFileName[i]; 
			link[l + 2 + i] = '\0';
		}
		//cout << link;


		Mat image = imread(link);

		//cout << image;

		int r = image.rows;
		int c = image.cols;

		int s = r < c ? r : c;


		resize(image2, image2, Size(s, s));

		int r2 = image2.rows;
		int c2 = image2.cols;

		for (int i = r - r2; i < r; i++)
			for (int j = c - c2; j < c; j++)
				//if (!(image2.at<Vec3b>(i - (r - r2), j - (c - c2)).val[0]  == 0 && image2.at<Vec3b>(i - (r - r2), j - (c - c2)).val[1] == 0 && image2.at<Vec3b>(i - (r - r2), j - (c - c2)).val[2] == 255))
			{
				int t = image2.at<Vec4b>(i - (r - r2), j - (c - c2)).val[3];
				image.at<Vec3b>(i, j).val[0] = (t * image2.at<Vec4b>(i - (r - r2), j - (c - c2)).val[0] + (255 - t) * image.at<Vec3b>(i, j).val[0]) / 255;
				image.at<Vec3b>(i, j).val[1] = (t * image2.at<Vec4b>(i - (r - r2), j - (c - c2)).val[1] + (255 - t) * image.at<Vec3b>(i, j).val[1]) / 255;
				image.at<Vec3b>(i, j).val[2] = (t * image2.at<Vec4b>(i - (r - r2), j - (c - c2)).val[2] + (255 - t) * image.at<Vec3b>(i, j).val[2]) / 255;
			}


		cout << "Saving " << link << "..." << endl;
		imwrite(link, image);

		//cout << search_data.cFileName << endl;
		if (FindNextFile(handle, &search_data) == FALSE)
			break;
	}











	char im2[] = "*.png";

	for (int i = 0; i < 5; i++) rootdir[l + 2 + i] = im2[i];
	rootdir[l + 2 + 5] = '\0';


	// << rootdir;

	HANDLE handle2 = FindFirstFile(rootdir, &search_data);
	/*
	Replace *.* with: *.jpg to find all .jpg file in folder
					  *.png to find all .png file in forlder
					  *.* to find all file
	 */


	while (handle2 != INVALID_HANDLE_VALUE)
	{
		cout << "Finding your next file..." << endl;
		Mat image2 = XuanChinh;
		//cout << image2.channels();

		char link[260];
		for (int i = 0; i <= l; i++) link[i] = rootdir[i];
		for (int i = 3; i <= l - 1; i++)
			link[i] = link[i + 1];
		link[2] = 47;
		link[l] = 47;
		link[l + 1] = '\0';
		//cout << link;
		for (int i = 0; search_data.cFileName[i] != '\0'; i++)
		{
			link[l + 1 + i] = search_data.cFileName[i];
			link[l + 2 + i] = '\0';
		}
		//cout << link;


		Mat image = imread(link);

		//cout << image;

		int r = image.rows;
		int c = image.cols;

		int s = r < c ? r : c;


		resize(image2, image2, Size(s, s));

		int r2 = image2.rows;
		int c2 = image2.cols;

		for (int i = r - r2; i < r; i++)
			for (int j = c - c2; j < c; j++)
				//if (!(image2.at<Vec3b>(i - (r - r2), j - (c - c2)).val[0]  == 0 && image2.at<Vec3b>(i - (r - r2), j - (c - c2)).val[1] == 0 && image2.at<Vec3b>(i - (r - r2), j - (c - c2)).val[2] == 255))
			{
				int t = image2.at<Vec4b>(i - (r - r2), j - (c - c2)).val[3];
				image.at<Vec3b>(i, j).val[0] = (t * image2.at<Vec4b>(i - (r - r2), j - (c - c2)).val[0] + (255 - t) * image.at<Vec3b>(i, j).val[0]) / 255;
				image.at<Vec3b>(i, j).val[1] = (t * image2.at<Vec4b>(i - (r - r2), j - (c - c2)).val[1] + (255 - t) * image.at<Vec3b>(i, j).val[1]) / 255;
				image.at<Vec3b>(i, j).val[2] = (t * image2.at<Vec4b>(i - (r - r2), j - (c - c2)).val[2] + (255 - t) * image.at<Vec3b>(i, j).val[2]) / 255;
			}


		cout << "Saving " << link << "..." << endl;
		imwrite(link, image);

		//cout << search_data.cFileName << endl;
		if (FindNextFile(handle2, &search_data) == FALSE)
			break;
	}

		//waitKey(0); // Wait for any keystroke in the window

	cout << endl << "Done! Check your files on your folder!";
	cin.get();
	return 0;
}