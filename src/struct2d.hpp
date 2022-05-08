#ifndef struct2d_hpp_INCLUDED
#define struct2d_hpp_INCLUDED

#include <vector>

#include "geom2d.hpp"

namespace f2 {
	struct struct2d {
		unsigned int dof = 2;	// Degrees of Freedom (dof): truss = 2; frame = 3
		std::vector<geom2d::node2d> nodes;
		std::vector<geom2d::beam2d> beams;
		std::vector<double> global_stiffness_matrix;

		struct2d();

		void add_node2d(const geom2d::node2d& n);
		void set_nodes(const std::vector<geom2d::node2d>& n);
		void add_beam2d(const geom2d::beam2d& b);
		void set_beams(const std::vector<geom2d::beam2d>& b);

		void build_stiffness_matrix();
	};


};


#endif // struct2d_hpp_INCLUDED
