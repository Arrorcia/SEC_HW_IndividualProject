#include "pch.h"
#include "CppUnitTest.h"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace test {
	TEST_CLASS(test) {
public:

	TEST_METHOD(Test1) {//for Circle.cpp, Line.cpp, Figure.cpp, Point.cpp
		Point* p1 = new Point(1, 0);
		Point* p2 = new Point(100000, 0);
		Point* p3 = new Point(1, -100000);
		Point* p4 = new Point(-100000, 100000);
		Assert::AreNotEqual((int)p1, NULL);
		Assert::AreNotEqual((int)p2, NULL);
		Assert::AreNotEqual((int)p3, NULL);
		Assert::AreNotEqual((int)p4, NULL);

		Circle* c1 = new Circle(0, 0, 1);
		Circle* c2 = new Circle(-100000, 100000, 100000);
		Assert::AreNotEqual((int)c1, NULL);
		Assert::AreNotEqual((int)c2, NULL);

		Line* l1 = new Line(0, 0, 1, 100000);
		Line* l2 = new Line(100000, 0, 1, 100000);
		Line* l3 = new Line(0, 0, -100000, 100000);
		Line* l4 = new Line(0, -334, 1, 100000);
		Assert::AreNotEqual((int)l1, NULL);
		Assert::AreNotEqual((int)l2, NULL);
		Assert::AreNotEqual((int)l3, NULL);
		Assert::AreNotEqual((int)l4, NULL);
	}
	TEST_METHOD(Test2) {//for PlaneContainer.cpp
		//test for condition1: all objs are lines
		PlaneContainer* pc1 = new PlaneContainer();
		Assert::AreEqual(pc1->countIntersectionPoints(), 0);
		Line* l1 = new Line(0, 1, 0);
		pc1->insert(l1);
		Assert::AreEqual(pc1->countIntersectionPoints(), 0);
		Line* l2 = new Line(1, 0, 0);
		pc1->insert(l2);
		Assert::AreEqual(pc1->countIntersectionPoints(), 1);
		Line* l3 = new Line(1, 1, 1);
		pc1->insert(l3);
		Assert::AreEqual(pc1->countIntersectionPoints(), 3);
		Line* l4 = new Line(1, 1, -1);
		pc1->insert(l4);
		Assert::AreEqual(pc1->countIntersectionPoints(), 5);
		Line* l5 = new Line(1, -1, 1);
		pc1->insert(l5);
		Assert::AreEqual(pc1->countIntersectionPoints(), 5);
		Line* l6 = new Line(1, -1, -1);
		pc1->insert(l6);
		Assert::AreEqual(pc1->countIntersectionPoints(), 5);

		//test for condition2: all objs are circles
		PlaneContainer* pc2 = new PlaneContainer();
		Assert::AreEqual(pc2->countIntersectionPoints(), 0);
		Circle* c1 = new Circle(0, 0, 1);
		pc2->insert(c1);
		Assert::AreEqual(pc2->countIntersectionPoints(), 0);
		Circle* c2 = new Circle(1, 0, 1);
		pc2->insert(c2);
		Assert::AreEqual(pc2->countIntersectionPoints(), 2);
		Circle* c3 = new Circle(0, 1, 1);
		pc2->insert(c3);
		Assert::AreEqual(pc2->countIntersectionPoints(), 6);
		Circle* c4 = new Circle(-1, 0, 1);
		pc2->insert(c4);
		Assert::AreEqual(pc2->countIntersectionPoints(), 9);
		Circle* c5 = new Circle(0, -1, 1);
		pc2->insert(c5);
		Assert::AreEqual(pc2->countIntersectionPoints(), 13);
		Circle* c6 = new Circle(0, 0, 2);
		pc2->insert(c6);
		Assert::AreEqual(pc2->countIntersectionPoints(), 17);

		//test for condition3: objs contains lines and circles
		PlaneContainer* pc3 = new PlaneContainer();
		pc3->insert(l1);
		pc3->insert(l2);
		pc3->insert(l3);
		pc3->insert(l4);
		pc3->insert(l5);
		pc3->insert(l6);
		Assert::AreEqual(pc3->countIntersectionPoints(), 5);

		pc3->insert(c1);
		Assert::AreEqual(pc3->countIntersectionPoints(), 5 + 0);

		pc3->insert(c2);
		Assert::AreEqual(pc3->countIntersectionPoints(), 5 + 2 + 5);

	}
	};
}
