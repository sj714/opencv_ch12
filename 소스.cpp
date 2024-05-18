/*
#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main() {
	Mat src = imread("labelex.png", IMREAD_GRAYSCALE);
	if (src.empty()) { cerr << "Image load failed!" << endl; return-1; }
	Mat bin;
	double x, y, x1, y1, x_max = 0, y_max = 0;
	int a = 1, b = 1;
	threshold(src, bin, 0, 255, THRESH_BINARY_INV | THRESH_OTSU);
	Mat labels, stats, centroids;
	int cnt = connectedComponentsWithStats(bin, labels, stats, centroids);
	x = centroids.at<double>(1, 0);
	y = centroids.at<double>(1, 1);
	for (int i = 1; i < cnt; i++) {
		x1 = centroids.at<double>(i, 0);
		y1 = centroids.at<double>(i, 1);
		if (x < x1 && y < y1) { a = i; x_max = x1; y_max = y1; }
		if (x > x1 && y > y1) { b = i; x = x1; y = y1; }
	}
	Mat dst;
	cvtColor(src, dst, COLOR_GRAY2BGR);
	rectangle(dst, Rect(stats.at<int>(a, 0), stats.at<int>(a, 1), stats.at<int>(a, 2), stats.at<int>(a, 3)), Scalar(0, 0, 255));
	rectangle(dst, Rect(stats.at<int>(b, 0), stats.at<int>(b, 1), stats.at<int>(b, 2), stats.at<int>(b, 3)), Scalar(255, 0, 0));
	cout << "면적이 최대인 객체의 레이블:" << a << endl;
	cout << "무게중심:(x,y): " << setw(10) << x_max << setw(10) << y_max << endl;
	cout << "면적이 최소인 객체의 레이블:" << b << endl;
	cout << "무게중심:(x,y): " << setw(10) << x << setw(10) << y << endl;
	imshow("src", dst);
	waitKey();
	return 0;
}

#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main() {
	Mat dst = imread("polygon.bmp");
	if (dst.empty()) { cerr << "Image load failed!" << endl; return-1; }
	Mat bin, src;
	cvtColor(dst, src, COLOR_BGR2GRAY);
	threshold(src, bin, 150, 255, THRESH_BINARY_INV);
	Mat labels, stats, centroids;
	int cnt = connectedComponentsWithStats(bin, labels, stats, centroids);
	cout << "갯수" << cnt << endl;
	cout << "label x y width height area color[B,G,R]" << endl;
	double x, y;
	for (int i = 1; i < cnt; i++) {
		x = centroids.at<double>(i, 0);
		y = centroids.at<double>(i, 1);
		putText(dst, to_string(i), Point(x, y), FONT_HERSHEY_SIMPLEX, 1, Scalar(0, 0, 255));
		rectangle(dst, Rect(stats.at<int>(i, 0), stats.at<int>(i, 1), stats.at<int>(i, 2), stats.at<int>(i, 3)), Scalar(0, 255, 255));
		cout << i << " " << stats.at<int>(i, 0) << " " << stats.at<int>(i, 1) << " " << stats.at<int>(i, 2) << " " << stats.at<int>(i, 3) << " " << stats.at<int>(i, 4) << " " << dst.at<Vec3b>(y, x) << endl;
	}
	imshow("src", dst);
	imshow("gray", src);
	imshow("bin", bin);
	waitKey();
	return 0;
}

#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main() {
	Mat src = imread("polygon.bmp", IMREAD_GRAYSCALE);
	if (src.empty()) { cerr << "Image load failed!" << endl; return-1; }
	Mat bin;
	threshold(src, bin, 150, 255, THRESH_BINARY_INV);
	Mat labels, stats, centroids;
	int cnt = connectedComponentsWithStats(bin, labels, stats, centroids);
	double x, y;
	for (int i = 1; i < cnt; i++) {
		double x = centroids.at<double>(i, 0);
		double y = centroids.at<double>(i, 1);
		cout << i << "번 객체의 무게중심:(" << x << ", " << y << ")" << endl;
	}
	return 0;
}

#include "opencv2/opencv.hpp"
#include <iostream>
using namespace cv;
using namespace std;
int main(void) {
	Mat dst = imread("car.jpg");
	if (dst.empty()) { cerr << "Image load failed!" << endl; return-1; }
	Mat bin, src;
	cvtColor(dst, src, COLOR_BGR2GRAY);
	Mat dst1, dst2, dx, dx1;
	blur(src, dst2, Size(5, 5));
	Sobel(dst2, dx, CV_32FC1, 1, 0);
	dx.convertTo(dx1, CV_8UC1);
	threshold(dx1, bin, 105, 255, THRESH_BINARY);
	morphologyEx(bin, dst1, MORPH_CLOSE, getStructuringElement(MORPH_RECT, Size(32, 5)));
	Mat labels, stats, centroids;
	int cnt = connectedComponentsWithStats(dst1, labels, stats, centroids);
	rectangle(dst, Rect(stats.at<int>(39, 0), stats.at<int>(39, 1), stats.at<int>(39, 2), stats.at<int>(39, 3)), Scalar(0, 0, 255), 2);
	imshow("image", dst);
	waitKey();
	return 0;
}*/