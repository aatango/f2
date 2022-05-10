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
		std::vector<double> arr { 4, 12, 16, -12, 37, 43, -16, -43, 98 };
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
			CHECK_EQ(matrix.matrix, arr);
		}
		SUBCASE("All at once") {
			std::fill(matrix.matrix.begin(), matrix.matrix.end(), 0);	// Reseting the matrix
			matrix.fill_matrix(arr);
			CHECK_EQ(matrix.matrix, arr);
		}
	}
	TEST_CASE("LDLT decomposition ex1") {
		symm_matrix matrix(3);
		std::vector<double> arr { 4, 12, -16, 12, 37, -43, -16, -43, 98 };
		matrix.fill_matrix(arr);
		matrix.decompose();

		SUBCASE("L matrix") {
			std::vector<double> test_l { 1, 0, 0, 3, 1, 0, -4, 5, 1 };
			CHECK_EQ(matrix.l_decomp, test_l);
		}
		SUBCASE("D matrix") {
			std::vector<double> test_d { 4, 1, 9 };
			CHECK_EQ(matrix.d_decomp, test_d);
		}
	}
	TEST_CASE("LDLT decomposition ex2") {
		symm_matrix matrix(4);
		std::vector<double> arr { 2, 4, -2, 2, 4, 9, -1, 6, -2, -1, 14, 13, 2, 6, 13, 35 };
		matrix.fill_matrix(arr);
		matrix.decompose();

		SUBCASE("L matrix") {
			std::vector<double> test_l { 1, 0, 0, 0, 2, 1, 0, 0, -1, 3, 1, 0, 1, 2, 3, 1 };
			CHECK_EQ(matrix.l_decomp, test_l);
		}
		SUBCASE("D matrix") {
			std::vector<double> test_d { 2, 1, 3, 2 };
			CHECK_EQ(matrix.d_decomp, test_d);
		}
	}
	TEST_CASE("Forward substitution") {
	}
	TEST_CASE("Diagonal multiplication") {
		symm_matrix s(5);
		std::vector<double> v1 { 1, 1, 2, 3, 5 };
		std::vector<double> v2 { 8, 13, 21, 34, 55 };
		std::vector<double> expected_v { 8, 13, 42, 102, 275 };
		std::vector<double> actual_v = s.vector_multiplication(v1, v2);

		CHECK_EQ(actual_v, expected_v);
	}
	TEST_CASE("Backward subtitution") {
	}
}
