#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>

#include "geom2d.hpp"


TEST_SUITE("Point2d") {

	TEST_CASE("Constructors") {
		SUBCASE("Default") {
			geom2::point2d point1;
			CHECK_EQ(point1.x, 0);
			CHECK_EQ(point1.y, 0);
			CHECK_EQ(typeid(point1.x), typeid(double));
			CHECK_EQ(typeid(point1.y), typeid(double));
		}
		SUBCASE("Defined") {
			geom2::point2d point1(1, 2);
			CHECK_EQ(point1.x, 1);
			CHECK_EQ(point1.y, 2);
			CHECK_EQ(typeid(point1.x), typeid(double));
			CHECK_EQ(typeid(point1.y), typeid(double));
		}
	}

	geom2::point2d point1(1, 2);
	geom2::point2d point2(4, 6);
	TEST_CASE("Operator overloads") {
		CHECK_EQ(point1, point1);
		CHECK_EQ(point1 + point2, geom2::point2d(5, 8));
	}
	TEST_CASE("Methods") {
		CHECK_EQ(point1.distance_to(point2), 5);
	}
}

TEST_SUITE("Vector2d") {
	TEST_CASE("Constructors") {
		SUBCASE("Default") {
			geom2::vector2d vector1;
			CHECK_EQ(vector1.u, 0);
			CHECK_EQ(typeid(vector1.u), typeid(double));
			CHECK_EQ(vector1.v, 0);
			CHECK_EQ(typeid(vector1.v), typeid(double));
		}
	}
	geom2::vector2d vector1(1, 2);
	geom2::vector2d vector2(4, 6);
}

TEST_SUITE("Node2d") {
	TEST_CASE("Constructors") {
		SUBCASE("Default") {
			geom2::node2d node1;

			CHECK_EQ(node1.x, 0);
			CHECK_EQ(node1.y, 0);
		}
		SUBCASE("Defined") {
			geom2::node2d node1(2, 3);

			CHECK_EQ(node1.x, 2);
			CHECK_EQ(node1.y, 3);
		}
	}
}

TEST_SUITE("Line2d") {
	TEST_CASE("Constructors") {
		SUBCASE("From existing points") {
			geom2::point2d point1;
			geom2::point2d point2(1, 2);

			geom2::line2d line1(point1, point2);

			//New definitions to make sure we aren't doing circular tests.
			CHECK_EQ(line1.start_point, geom2::point2d());
			CHECK_EQ(line1.end_point, geom2::point2d(1, 2));
		}
		SUBCASE("From coordinates") {
			geom2::line2d line2(1, 2, 4, 6);

			CHECK_EQ(line2.start_point, geom2::point2d(1, 2));
			CHECK_EQ(line2.end_point, geom2::point2d(4, 6));
		}
	}
}
