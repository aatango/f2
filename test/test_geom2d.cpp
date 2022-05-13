#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include <iostream>
#include <cmath>

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
	TEST_CASE("Methods") {
		SUBCASE("distance_to") {
			node2d node1(1, 3);
			node2d node2(2, 4);

			CHECK_EQ(node1.distance_to(node2), std::sqrt(2));
		}
		SUBCASE("add loading") {
			node2d node1;
			node1.apply_loading(10,10);
			std::array<double, 2> actual = node1.forces;
			std::array<double, 2> expected { 10, 10 };
			CHECK_EQ(actual, expected);

			node1.apply_loading(0, 10);
			actual = node1.forces;
			REQUIRE_NE(actual, expected);

			expected = {0, 10};
			CHECK_EQ(actual, expected);
		}
	}
}

TEST_SUITE("Beam2d") {
	TEST_CASE("Constructors") {
		SUBCASE("from nodes") {
			node2d node1;
			node2d node2(2,1);
			beam2d beam1(node1, node2, 5, std::sqrt(5));
			std::array<double, 16> test_matrix {
				4, 2, -4, -2,
				2, 1, -2, -1,
				-4, -2, 4, 2,
				-2, -1, 2, 1
			};

			REQUIRE_EQ(beam1.start_node, node1);
			REQUIRE_EQ(beam1.end_node, node2);
			CHECK_EQ(beam1.global_stiffness_matrix, test_matrix);
		}
		SUBCASE("from coordinates") {
			beam2d beam1(1, 2, 4, 6);
			node2d node1(1, 2);
			node2d node2(4, 6);

			CHECK_EQ(beam1.start_node, node1);
			CHECK_EQ(beam1.end_node, node2);
		}
	}
	TEST_CASE("Operators") {
		SUBCASE("==") {
			beam2d beam1(0, 0, 1, 2);
			beam2d beam2(0, 0, 1, 2);

			CHECK_EQ(beam1, beam2);
		}
	}
	TEST_CASE("Methods") {
		SUBCASE("get_length()") {
			beam2d beam(2, -6, 7, 3);

			CHECK_EQ(beam.get_length(), std::sqrt(106));
		}
	}
}
