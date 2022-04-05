#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>

#include "../src/lib/geom2d.hpp"

TEST_SUITE("Point2d") {
	auto point1 = geom2d::point2d(1, 2);
	auto point2 = geom2d::point2d(4, 6);

	TEST_CASE("Definition") {
		CHECK_EQ(point1.x, 1);
		CHECK_EQ(point1.y, 2);
	}

	TEST_CASE("Operator overloads") {
		CHECK_EQ(point1, point1);
		CHECK_EQ(point1 + point2, geom2d::point2d(5, 8));
	}

	TEST_CASE("Methods") {
		CHECK_EQ(point1.distance_to(point2), 5);
	}
}

TEST_SUITE("Vector2d") {
	auto vector1 = geom2d::vector2d(1, 2);
	auto vector2 = geom2d::vector2d(4, 6);

	TEST_CASE("Definition") {
		CHECK_EQ(vector1.u, 1);
		CHECK_EQ(vector1.v, 2);
	}
}
