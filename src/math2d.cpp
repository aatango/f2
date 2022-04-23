#include "math2d.hpp"

using namespace math2d;

symm_matrix::symm_matrix(const int _n) : size(_n) {
	matrix.resize(_n * _n);
	l_decomp.resize(_n * _n);
	d_decomp.resize(_n);
}

void symm_matrix::set_cell(const double _i, const unsigned int _r, const unsigned int _c) {
	matrix.at(_r * size + _c) = _i;
}

int symm_matrix::fill_matrix(const std::vector<double> _v) {
	if (matrix.size() != size * size) { return 1; }

	matrix = _v;

	return 0;
}

void symm_matrix::decompose() {
	for (unsigned int j = 0; j < size; ++j) {
		double d_sum = 0;
		for (unsigned int k = 0; k < j; ++k) {
			double l_jk = l_decomp.at(j * size + k);
			d_sum += l_jk * l_jk * d_decomp.at(k);
		}
		d_decomp.at(j) = matrix.at(j * size + j) - d_sum;
		l_decomp.at(j * size + j) = 1;
		
		for (unsigned int i = j + 1; i < size; ++i) {
			double l_sum = 0;
			for (unsigned int k = 0; k < j; ++k) {
				double l_ik = l_decomp.at(i * size + k);
				double l_jk = l_decomp.at(j * size + k);
				l_sum += l_ik * l_jk * d_decomp.at(k);
			}
			l_decomp.at(i * size + j) = 1 / d_decomp.at(j) * (matrix.at(i * size + j) - l_sum);

		}
	}
}
