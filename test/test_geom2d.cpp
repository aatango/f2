#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>

#include "geom2d.hpp"
using namespace geom2d;

TEST_SUITE("Node2d") {
	TEST_CASE("Constructors") {
		SUBCASE("Default") {
			node2d point1;
			CHECK_EQ(point1.x, 0);
			CHECK_EQ(point1.y, 0);
			CHECK_EQ(typeid(point1.x), typeid(double));
			CHECK_EQ(typeid(point1.y), typeid(double));
		}
		SUBCASE("Defined") {
			node2d point1(1, 2);
			CHECK_EQ(point1.x, 1);
			CHECK_EQ(point1.y, 2);
			CHECK_EQ(typeid(point1.x), typeid(double));
			CHECK_EQ(typeid(point1.y), typeid(double));
		}
	}
	TEST_CASE("Operators") {
		SUBCASE("==") {
			node2d point1(1, 2);
			node2d point2(1, 2);
			CHECK_EQ(point1, point2);
		}
	}
}

TEST_SUITE("Beam2d") {
	TEST_CASE("Constructors") {
		SUBCASE("from nodes") {
			node2d node1;
			node2d node2(1,2);
			beam2d beam1(node1, node2);
			CHECK_EQ(beam1.start_point, node1);
			CHECK_EQ(beam1.end_point, node2);
		}
		SUBCASE("from coordinates") {
			beam2d beam1(1, 2, 4, 6);
			node2d node1(1, 2);
			node2d node2(4, 6);
			CHECK_EQ(beam1.start_point, node1);
			CHECK_EQ(beam1.end_point, node2);
		}
	}
	TEST_CASE("Operators") {
		SUBCASE("==") {
			beam2d beam1(0, 0, 1, 2);
			beam2d beam2(0, 0, 1, 2);
			CHECK_EQ(beam1, beam2);
}
