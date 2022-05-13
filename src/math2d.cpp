#include <stdexcept>

#include "math2d.hpp"

using namespace math2d;

symm_matrix::symm_matrix(const int n) : size(n) {
	this->matrix.resize(n * n);
	this->l_decomp.resize(n * n);
	this->d_decomp.resize(n);
}

void symm_matrix::set_cell(const double i, const unsigned int r, const unsigned int c) {
	this->matrix.at(r * size + c) = i;
}

int symm_matrix::fill_matrix(const std::vector<double> v) {
	if (this->matrix.size() != this->size * this->size) { return 1; }

	this->matrix = v;

	return 0;
}

void symm_matrix::decompose() {
	for (unsigned int j = 0; j < size; ++j) {
		double d_sum = 0;
		for (unsigned int k = 0; k < j; ++k) {
			double l_jk = this->l_decomp.at(j * this->size + k);
			d_sum += l_jk * l_jk * this->d_decomp.at(k);
		}
		this->d_decomp.at(j) = this->matrix.at(j * this->size + j) - d_sum;
		this->l_decomp.at(j * this->size + j) = 1;

		for (unsigned int i = j + 1; i < this->size; ++i) {
			double l_sum = 0;
			for (unsigned int k = 0; k < j; ++k) {
				double l_ik = this->l_decomp.at(i * this->size + k);
				double l_jk = this->l_decomp.at(j * this->size + k);
				l_sum += l_ik * l_jk * this->d_decomp.at(k);
			}
			this->l_decomp.at(i * this->size + j) = 
				1 / this->d_decomp.at(j) * (this->matrix.at(i * this->size + j) - l_sum);

		}
	}
}

std::vector<double> symm_matrix::vector_multiplication(
	const std::vector<double>& v1,
	const std::vector<double>& v2
) const {
	if (v1.size() != v2.size()) { throw std::logic_error("Input vectors not the same size"); }

	std::vector<double> v{};
	for (unsigned int i = 0; i < v1.size(); ++i) { v.push_back(v1.at(i) * v2.at(i)); }

	return v;
}

std::vector<double> symm_matrix::forward_substitution(
	const std::vector<double>& l,
	const std::vector<double>& b) const
{
	throw std::logic_error("Not yet implemented");
}
