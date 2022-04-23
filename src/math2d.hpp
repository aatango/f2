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
	struct symm_matrix {
		unsigned int size;
		std::vector<double> matrix;
		std::vector<double> l_decomp;	// Decomposed L matrix
		std::vector<double> d_decomp;	// Decomposed D matrix

		symm_matrix(const int _n);

		// operator overloads

		void set_cell(const double _d, const unsigned int _r, const unsigned int _c);
		int fill_matrix(const std::vector<double> _v);
		void decompose(); //LDLT decomposition
	};
}

#endif // math2d_hpp_INCLUDED

