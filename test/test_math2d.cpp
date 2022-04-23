#include <iostream>
#include <vector>

#include "doctest.h"

#include "math2d.hpp"
using namespace math2d;

TEST_SUITE("math2d") {
	TEST_CASE("Constructor") {
		symm_matrix matrix(3);
		REQUIRE_EQ(matrix.size, 3);
		REQUIRE_EQ(matrix.matrix.size(), 9);
		REQUIRE_EQ(matrix.d_decomp.size(), 3);
	}
	TEST_CASE("Filling the matrix") {
		symm_matrix matrix(3);
		// Non-symmetrical matrix to check values.
		// negative at lower triangle.
		SUBCASE("one-by-one") {
			matrix.set_cell(4, 0, 0);
			matrix.set_cell(-12, 1, 0);
			matrix.set_cell(-16, 2, 0);
			matrix.set_cell(12, 0, 1);
			matrix.set_cell(37, 1, 1);
			matrix.set_cell(-43, 2, 1);
			matrix.set_cell(16, 0, 2);
			matrix.set_cell(43, 1, 2);
			matrix.set_cell(98, 2, 2);

			CHECK_EQ(matrix.matrix.at(4), 37);
			CHECK_EQ(matrix.matrix.at(2), 16);
			CHECK_EQ(matrix.matrix.at(6), -16);
		}
		SUBCASE("All at once") {
			// reseting matrix, just to be sure.
			std::fill(matrix.matrix.begin(), matrix.matrix.end(), 0);
			std::vector<double> arr { 4, 12, 16, -12, 37, 43, -16, -43, 98 };
			matrix.fill_matrix(arr);

			CHECK_EQ(matrix.matrix.at(0), 4);
			CHECK_EQ(matrix.matrix.at(4), 37);
			CHECK_EQ(matrix.matrix.at(2), 16);
			CHECK_EQ(matrix.matrix.at(6), -16);
		}
	}
	TEST_CASE("LDLT decomposition ex1") {
		symm_matrix matrix(3);
		std::vector<double> arr { 4, 12, -16, 12, 37, -43, -16, -43, 98 };
		matrix.fill_matrix(arr);
		matrix.decompose();

		SUBCASE("L matrix") {
			CHECK_EQ(matrix.l_decomp.at(0), 1);
			CHECK_EQ(matrix.l_decomp.at(1), 0);
			CHECK_EQ(matrix.l_decomp.at(2), 0);
			CHECK_EQ(matrix.l_decomp.at(3), 3);
			CHECK_EQ(matrix.l_decomp.at(4), 1);
			CHECK_EQ(matrix.l_decomp.at(5), 0);
			CHECK_EQ(matrix.l_decomp.at(6), -4);
			CHECK_EQ(matrix.l_decomp.at(7), 5);
			CHECK_EQ(matrix.l_decomp.at(8), 1);
		}
		SUBCASE("D matrix") {
			CHECK_EQ(matrix.d_decomp.at(0), 4);
			CHECK_EQ(matrix.d_decomp.at(1), 1);
			CHECK_EQ(matrix.d_decomp.at(2), 9);
		}
	}
	TEST_CASE("LDLT decomposition ex2") {
		symm_matrix matrix(4);
		std::vector<double> arr { 2, 4, -2, 2, 4, 9, -1, 6, -2, -1, 14, 13, 2, 6, 13, 35 };
		matrix.fill_matrix(arr);
		matrix.decompose();

		SUBCASE("L matrix") {
			CHECK_EQ(matrix.l_decomp.at(0), 1);
			CHECK_EQ(matrix.l_decomp.at(1), 0);
			CHECK_EQ(matrix.l_decomp.at(2), 0);
			CHECK_EQ(matrix.l_decomp.at(3), 0);
			CHECK_EQ(matrix.l_decomp.at(4), 2);
			CHECK_EQ(matrix.l_decomp.at(5), 1);
			CHECK_EQ(matrix.l_decomp.at(6), 0);
			CHECK_EQ(matrix.l_decomp.at(7), 0);
			CHECK_EQ(matrix.l_decomp.at(8), -1);
			CHECK_EQ(matrix.l_decomp.at(9), 3);
			CHECK_EQ(matrix.l_decomp.at(10), 1);
			CHECK_EQ(matrix.l_decomp.at(11), 0);
			CHECK_EQ(matrix.l_decomp.at(12), 1);
			CHECK_EQ(matrix.l_decomp.at(13), 2);
			CHECK_EQ(matrix.l_decomp.at(14), 3);
			CHECK_EQ(matrix.l_decomp.at(15), 1);
		}
		SUBCASE("D matrix") {
			CHECK_EQ(matrix.d_decomp.at(0), 2);
			CHECK_EQ(matrix.d_decomp.at(1), 1);
			CHECK_EQ(matrix.d_decomp.at(2), 3);
			CHECK_EQ(matrix.d_decomp.at(3), 2);
		}
	}
}
