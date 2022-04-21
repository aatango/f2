#include "struct2d.hpp"

using namespace struct2d;

model2d::model2d() {}

int model2d::add_node2d(const unsigned int _id, const geom2d::node2d& _node2d) {
	model2d::nodes2d.insert({_id, _node2d});
	return 0;
}

int model2d::add_beam2d(const unsigned int _id, const geom2d::beam2d& _beam2d) {
	model2d::beams2d.insert({_id, _beam2d});
	return 0;
}
