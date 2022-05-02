#ifndef struct2d_hpp_INCLUDED
#define struct2d_hpp_INCLUDED

#include <unordered_map>

#include "geom2d.hpp"

namespace struct2d {
	struct model2d {
		std::unordered_map<unsigned int, geom2d::node2d> nodes2d;
		std::unordered_map<unsigned int, geom2d::beam2d> beams2d;

		model2d();

		int add_node2d(const unsigned int id, const geom2d::node2d& node2d);
		int add_beam2d(const unsigned int id, const geom2d::beam2d& beam2d);
	};
		

};


#endif // struct2d_hpp_INCLUDED
