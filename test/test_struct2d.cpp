#include "doctest.h"

#include <iostream>

#include "geom2d.hpp"
#include "struct2d.hpp"
using namespace struct2d;


TEST_SUITE("Model2d") {
	model2d structure; 

	TEST_CASE("Nodes 2d") {
		geom2d::node2d node1(1, 2);
		structure.add_node2d(1, node1);
		SUBCASE("Definition") {
			CHECK_EQ(structure.nodes2d.at(1), node1);
			CHECK_EQ(structure.nodes2d.count(1), 1);
		}
		SUBCASE("repeated definition") {
			geom2d::node2d node2(4, 6);
			structure.add_node2d(1, node2);
			CHECK_EQ(structure.nodes2d.at(1), node1);
			CHECK_EQ(structure.nodes2d.count(1), 1);
		}
	}
	TEST_CASE("Beams2d") {
		SUBCASE("Definition") {
			geom2d::node2d node1;
			geom2d::node2d node2(1, 2);

			geom2d::beam2d beam1(node1, node2);

			structure.add_beam2d(1, beam1);

			CHECK_EQ(structure.beams2d.at(1), beam1);
		}
	}
}
