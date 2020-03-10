#pragma once
#include "Figure.h"
#include "Circle.h"
#include "Line.h"
#include "Point.h"
class Line :public Figure {
public:
	Line(int x1, int y1, int x2, int y2);
	Line(double A, double B, double C);
	set <Point> intersect(Figure* figure);
	double getA();
	double getB();
	double getC();
private:
	double A, B, C;
};

