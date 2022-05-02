#include "struct2d.hpp"

using namespace struct2d;

model2d::model2d() {}

int model2d::add_node2d(const unsigned int id, const geom2d::node2d& node2d) {
	this->nodes2d.insert({id, node2d});
	return 0;
}

int model2d::add_beam2d(const unsigned int id, const geom2d::beam2d& beam2d) {
	this->beams2d.insert({id, beam2d});
	return 0;
}
