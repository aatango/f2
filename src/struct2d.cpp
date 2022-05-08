#include <algorithm>
#include <vector>

#include "struct2d.hpp"

using namespace f2;

struct2d::struct2d() {
	nodes.clear();
	beams.clear();
	global_stiffness_matrix.clear();
}

void struct2d::add_node2d(const geom2d::node2d& n) { this->nodes.push_back(n); }
void struct2d::set_nodes(const std::vector<geom2d::node2d>& n) { this->nodes = n; }

void struct2d::add_beam2d(const geom2d::beam2d& b) {this->beams.push_back(b); }
void struct2d::set_beams(const std::vector<geom2d::beam2d>& b) {this->beams = b; }

void struct2d::build_stiffness_matrix() {
	unsigned int global_dof = this->dof * this->nodes.size();
	this->global_stiffness_matrix.resize(global_dof * global_dof);
	std::fill(
		this->global_stiffness_matrix.begin(),
		this->global_stiffness_matrix.end(),
		0);

	for (auto& beam : beams) {
		unsigned int start_index = std::distance(
			this->nodes.begin(),
			std::find(this->nodes.begin(), this->nodes.end(), beam.start_node));
		unsigned int end_index = std::distance(
			this->nodes.begin(),
			std::find(this->nodes.begin(), this->nodes.end(), beam.end_node));
		std::vector<unsigned int> dof_index { start_index, end_index };

		/* decompose beam stiffness matrix, which are in linear form, onto n_cr (column, row) format;
                 * find corresponding DoF in structure matrix, and add the component stiffness.
                 */
		unsigned int beam_dof = 2 * this->dof;
		for (unsigned int i = 0; i < beam_dof * beam_dof; ++i) {
			unsigned int beam_c = i % beam_dof;
			unsigned int beam_r = i / beam_dof;

			unsigned int struct_c = beam_c % this->dof + dof_index.at(beam_c / this->dof) * this->dof;
			unsigned int struct_r = beam_r % this->dof + dof_index.at(beam_r / this->dof) * this->dof;

			this->global_stiffness_matrix.at(struct_c + struct_r * global_dof) +=
				beam.global_stiffness_matrix.at(beam_c + beam_r * beam_dof);
		}
	}
}
