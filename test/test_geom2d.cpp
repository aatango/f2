#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>

#include "geom2d.hpp"
using namespace geom2d;

TEST_SUITE("Node2d") {

	TEST_CASE("Constructors") {
		SUBCASE("Default") {
			node2d point1;
			CHECK_EQ(point1._x, 0.0);
			CHECK_EQ(point1._y, 0.0);
			CHECK_EQ(typeid(point1._x), typeid(double));
			CHECK_EQ(typeid(point1._y), typeid(double));
		}
		SUBCASE("Defined") {
			node2d point1(1, 2);
			CHECK_EQ(point1._x, 1);
			CHECK_EQ(point1._y, 2);
			CHECK_EQ(typeid(point1._x), typeid(double));
			CHECK_EQ(typeid(point1._y), typeid(double));
		}
	}
}
