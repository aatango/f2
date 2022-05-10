#ifndef math2d_hpp_INCLUDED
#define math2d_hpp_INCLUDED

#include <vector>

namespace math2d {
/*	class vector2d {
		double _u = 0;
		double _v = 0;

	public:
		vector2d ();
		vector2d (const double u, const double y);*/

	// TODO? : separate types of matrices (gen., square, symm., tri., diag., etc)
	// TODO : validate symmetry of matrix
	struct symm_matrix {
		unsigned int size;
		std::vector<double> matrix;
		std::vector<double> l_decomp;	// Decomposed L matrix
		std::vector<double> d_decomp;	// Decomposed D matrix

		symm_matrix(const int n);

		// operator overloads

		void set_cell(const double d, const unsigned int r, const unsigned int c);
		int fill_matrix(const std::vector<double> v);
		void decompose(); //LDLT decomposition

		std::vector<double> vector_multiplication(const std::vector<double>& v1, const std::vector<double>& v2) const;
	};
}

#endif // math2d_hpp_INCLUDED

