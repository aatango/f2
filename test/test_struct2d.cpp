#include "doctest.h"

#include <array>
#include <iostream>
#include <vector>

#include "geom2d.hpp"
#include "struct2d.hpp"

using namespace f2;
using namespace geom2d;


TEST_SUITE("Struct2d") {
	//From Finite Elemente in der Baustatik (3. Aufl.), Ch. 3.2, pg. 91
	TEST_CASE("Ex. 1") {
		double a = 0.004;
		double e = 210000000;

		node2d node1(0, 3);
		node2d node2(3, 3);
		node2d node3(3, 0, false, true);
		node2d node4(0, 0, true, true);
		std::vector<node2d> nodes { node1, node2, node3, node4};

		beam2d beam1(node1, node2, a, e);
		beam2d beam2(node3, node2, a, e);
		beam2d beam3(node4, node3, a, e);
		beam2d beam4(node4, node1, a, e);
		beam2d beam5(node4, node2, a, e);
		beam2d beam6(node3, node1, a, e);
		std::vector<beam2d> beams { beam1, beam2, beam3, beam4, beam5, beam6 };

		struct2d model;

		model.set_nodes(nodes);
		model.set_beams(beams);

		SUBCASE("nodes") {
			REQUIRE_EQ(model.nodes.front(), node1);
			REQUIRE_EQ(model.nodes.at(1), node2);
			REQUIRE_EQ(model.nodes.back(), node4);

			CHECK_EQ(model.nodes.at(2).supports.front(), false);
			CHECK_EQ(model.nodes.at(2).supports.back(), true);
		}
		SUBCASE("beams") {
			REQUIRE_EQ(model.beams.front(), beam1);
			REQUIRE_EQ(model.beams.at(1), beam2);
			REQUIRE_EQ(model.beams.back(), beam6);

			double s = 280000;
			std::array<double, 16> beam_stiffness {
				s * 1, 0, s * -1, 0,
				0, 0, 0, 0,
				s * -1, 0, s * 1, 0,
				0, 0, 0, 0
			};
			REQUIRE_EQ(beam1.global_stiffness_matrix.size(), beam_stiffness.size());
			CHECK_EQ(beam1.global_stiffness_matrix, beam_stiffness);
		}
		SUBCASE("stiffness matrix") {
			model.build_stiffness_matrix();

			double s = 280000;	//stiffness constant
			std::vector<double> test_matrix = {
				s * 1.35, s * -0.35, s * -1.0, 0, s * -0.35, s * 0.35, 0, 0,
				s * -0.35, s * 1.35, 0, 0, s * 0.35, s * -0.35, 0, s * -1.0,
				s * -1.0, 0, s * 1.35, s * 0.35, 0, 0, s * -0.35, s * -0.35,
				0, 0, s * 0.35, s * 1.35, 0, s * -1.0, s * -0.35, s * -0.35,
				s * -0.35, s * 0.35, 0, 0, s * 1.35, s * -0.35, s * -1.0, 0,
				s * 0.35, s * -0.35, 0, s * -1.0, s * -0.35, s * 1.35, 0, 0,
				0, 0, s * -0.35, s * -0.35, s * -1.0, 0, s * 1.35, s * 0.35,
				0, s * -1.0, s * -0.35, s * -0.35, 0, 0, s * 0.35, s * 1.35
			};

			REQUIRE_EQ(model.global_stiffness_matrix.size(), test_matrix.size());

			/* Since the provided example works with a reduced precision (2 decimal places),
                          * a direct comparison of the stiffness matrices is not possible.
                         */
			for (unsigned int i = 0; i < test_matrix.size(); ++i) {
				CHECK_EQ(
					test_matrix.at(i),
					doctest::Approx(model.global_stiffness_matrix.at(i)).epsilon(0.05)
				);
			}

			model.apply_restraints();
			unsigned int no_dof = model.dof * model.nodes.size();
			CHECK_NE(model.global_stiffness_matrix.at(2 * 2 * (1 + no_dof)), 1.0);
			CHECK_EQ(model.global_stiffness_matrix.at((2 * 2 + 1) * (1 + no_dof)), 1.0);
			CHECK_EQ(model.global_stiffness_matrix.at((3 * 2) * (1 + no_dof)), 1.0);
			CHECK_EQ(model.global_stiffness_matrix.at((3 * 2 + 1) * (1 + no_dof)), 1.0);
			CHECK_EQ(model.nodes.at(2).forces.at(1), 0.0);
			CHECK_EQ(model.nodes.at(3).forces.at(0), 0);
			CHECK_EQ(model.nodes.at(3).forces.at(1), 0);
		}
	}
}
