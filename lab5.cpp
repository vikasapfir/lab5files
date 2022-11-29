#include <iostream>
#include <string>
#include <cmath>
#include "lab5.h"

using namespace std;

class Point
{
public:
	Point(int x, int y) {
		this->x = x;
		this->y = y;
	}
	Point() {
		x = 0;
		y = 0;
	}
	int getX() {
		return x;
	}
	int getY() {
		return y;

	}
	void print() {
		cout << "(" << x << "," << y << ")";
	}
};
class Polynom {
	int points_number;
	Point* points;
public:
	Polynom(Point* points, int points_number) {
		this->points_number = points_number;
		this->points = points;
	}
	Point* getPoints() {
		return points;
	}
	int getPointsNumbers() {
		return points_number;
	}
	void print() {
		cout << "points number: " << points_number << ", points: ";
		for (int i = 0; i < points_number; i++) {
			points[i].print();
			cout << " ";
		}
		cout << endl;
	}
	~Polynom() {
		points_number = 0;
		points = nullptr;
	}
};
double length(Point point1, Point point2) {
	return sqrt(pow(point2.getX() - point1.getX(), 2) + (pow(point2.getY() - point1.getY(), 2)));
}
double perimetr(Polynom polynom) {
	Point* points = polynom.getPoints();
	int points_number = polynom.getPointsNumbers();
	if (points == nullptr) {
		return 0;
	}
	double p = 0;
	for (int i = 0; i < points_number - 1; i++) {
		p += length(points[i], points[i + 1]);
	}
	p += length(points[0], points[points_number - 1]);
	return p;
}
double maxDiagonal(Polynom polynom) {
	Point* points = polynom.getPoints();
	int points_number = polynom.getPointsNumbers();
	if (points == nullptr || points_number < 4) {
		return 0;
	}
	double max_length = 0;
	Point first_point, second_point;
	for (int i = 0; i < points_number; i++) {
		Point current = points[i];
		for (int j = i + 2; j < points_number; j++) {
			if (i == 0 && j == points_number - 1) {
				break;
			}
			double l = length(current, points[j]);
			if (l > max_length) {
				max_length = l;
				first_point = current;
				second_point = points[j];
			}
		}
	}
	cout << "Diagonal: ";
	first_point.print();
	cout << "->";
	second_point.print();
	return max_length;
}
void swap(Point& point1, Point& point2) {
	Point point = point1;
	point1 = point2;
	point2 = point;
}
void bubbleSort(Point points[], int size, bool by_x) {
	bool swapped = false;
	for (int i = 1; i < size; i++) {
		swapped = false;
		for (int j = 0; j < size - i; j++) {
			if ((by_x && points[j].getX() > points[j + 1].getX()) || (!by_x && points[j].getY() > points[j + 1].getY())) {
				swap(points[j], points[j + 1]);
				swapped = true;
			}
		}
		if (!swapped) {
			break;
		}
	}
}
void printPoints(Point points[], int size) {
	for (int i = 0; i < size; i++) {
		points[i].print();
		cout << " ";
	}
	cout << endl;
}
int main()
{
	Point points[] = { Point(2, 2), Point(5, 2), Point(5, 5), Point(2, 5) };
	Polynom squar(points, 4);
	squar.print();
	double max = maxDiagonal(squar);
	cout << " smax length: " << max << endl;
	double p = perimetr(squar);
	cout << "perimetr: " << p << endl;
	Point arr[] = { Point(2, 2), Point(5, 6), Point(7, 2) };
	Polynom triang(arr, 3);
	triang.print();
	p = perimetr(triang);
	cout << "perimetr: " << p << endl;
	Point arr2[] = { Point(2, 2), Point(4, 1), Point(6, 3), Point(4, 6), Point(1, 5) };
	Polynom pentagon(arr2, 5);
	pentagon.print();
	p = perimetr(pentagon);
	cout << "perimetr: " << p << endl;
	max = maxDiagonal(pentagon);
	cout << " max length: " << max << endl;
	bubbleSort(arr2, 5, true);
	printPoints(arr2, 5);
	bubbleSort(arr2, 5, false);
	printPoints(arr2, 5);
	return 0;
}
