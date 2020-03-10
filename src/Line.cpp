#include "Line.h"
#include <string>
#include <math.h>
Line::Line(int x1, int y1, int x2, int y2) {
	if (x1 == x2) {
		this->A = 1;
		this->B = 0;
		this->C = -x1;
	} else {
		this->A = (double(y1) - double(y2)) / (double(x1) - double(x2));
		this->B = -1;
		this->C = y1 - A * x1;
	}
}

Line::Line(double A, double B, double C) {
	this->A = A;
	this->B = B;
	this->C = C;
}

set<Point> Line::intersect(Figure* figure) {
	double x, y;
	set<Point> points;
	if (typeid(*figure) == typeid(Line)) {
		Line* line = (Line*)figure;
		double A1, B1, C1, A2, B2, C2;
		A1 = this->A; B1 = this->B; C1 = this->C;
		A2 = line->getA(); B2 = line->getB(); C2 = line->getC();
		//((B1*C2-B2*C1)/(A1*B2-A2*B1)£¬(A2*C1-A1*C2)/(A1*B2-A2*B1))
		//((b1*c2-b2*c1)/(a1*b2-a2*b1)£¬(a2*c1-a1*c2)/(a1*b2-a2*b1))
		if (A1 * B2 != A2 * B1) {
			x = (B1 * C2 - B2 * C1) / (A1 * B2 - A2 * B1);
			y = (A2 * C1 - A1 * C2) / (A1 * B2 - A2 * B1);
			points.insert(Point(x, y));
		}
	} else if (typeid(*figure) == typeid(Circle)) {
		Circle* circle = (Circle*)figure;
		double tA, tB, tC, a, b, r, k, m, Delta;
		a = circle->getX();
		b = circle->getY();
		r = circle->getR();
		if (B != 0) {
			k = -A / B;
			m = -C / B;

			//tA=1+k^2
			tA = 1 + k * k;
			//tB=2(km-bk-a)
			tB = 2 * (k * m - b * k - a);
			//tC=a^2+(b-m)^2-r^2
			tC = a * a + (b - m) * (b - m) - r * r;

			Delta = tB * tB - 4 * tA * tC;
			if (Delta > 0) {
				x = (-tB + sqrt(Delta)) / (2 * tA);
				y = k * x + m;
				points.insert(Point(x, y));

				x = (-tB - sqrt(Delta)) / (2 * tA);
				y = k * x + m;
				points.insert(Point(x, y));
			} else if (Delta == 0) {
				x = -tB / (2 * tA);
				y = k * x + m;
				points.insert(Point(x, y));
			}
		} else {
			x = m = -C / A;
			y = b + sqrt(r * r - (m - a) * (m - a));
			points.insert(Point(x, y));

			y = b - sqrt(r * r - (m - a) * (m - a));
			points.insert(Point(x, y));
		}
	}
	return points;
}

double Line::getA() {
	return A;
}
double Line::getB() {
	return B;
}
double Line::getC() {
	return C;
}

