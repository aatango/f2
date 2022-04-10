#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>

#include "geom2d.hpp"

TEST_SUITE("Point2f") {
	geom2::point2f point1(1, 2);
	geom2::point2f point2(4, 6);

	TEST_CASE("Definition") {
		REQUIRE_EQ(point1.x, 1);
		REQUIRE_EQ(typeid(point1.x), typeid(float));

		REQUIRE_EQ(point1.y, 2);
		REQUIRE_EQ(typeid(point1.y), typeid(float));

	}

	// To avoid duplication, further tests are made only on double precision objects.
}

TEST_SUITE("Point2d") {
	geom2::point2d point1(1, 2);
	geom2::point2d point2(4, 6);

	TEST_CASE("Definition") {
		REQUIRE_EQ(point1.x, 1);
		REQUIRE_EQ(typeid(point1.x), typeid(double));
		
		REQUIRE_EQ(point1.y, 2);
		REQUIRE_EQ(typeid(point1.y), typeid(double));
	}

	TEST_CASE("Operator overloads") {
		CHECK_EQ(point1, point1);
		CHECK_EQ(point1 + point2, geom2::point2d(5, 8));
	}

	TEST_CASE("Methods") {
		CHECK_EQ(point1.distance_to(point2), 5);
	}
}

TEST_SUITE("Vector2d") {
	geom2::vector2d vector1(1, 2);
	geom2::vector2d vector2(4, 6);

	TEST_CASE("Definition") {
		REQUIRE_EQ(vector1.u, 1);
		REQUIRE_EQ(typeid(vector1.u), typeid(double));
		
		REQUIRE_EQ(vector1.v, 2);
		REQUIRE_EQ(typeid(vector1.v), typeid(double));
	}
}

