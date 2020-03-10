#pragma once

#include <typeinfo>
#include <set>
#include <vector>
#include "Point.h"
using namespace std;

class Figure {
public:
	virtual set<Point> intersect(Figure* figure) = 0;
};

