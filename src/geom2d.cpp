#include <cmath>

#include "geom2d.hpp"


using namespace geom2d;

node2d::node2d(const double x, const double y) :  x(x), y(y) {}

bool node2d::operator == (const node2d& node2) const {
	return this->x == node2.x && this->y == node2.y;
}

/*template <class T> 
bool point2_generic<T>::operator == (const point2_generic& point2) const {
	return this == &point2 ? true : x == point2.x && y == point2.y;
}

template <class T>
bool point2_generic<T>::operator == (const T  _point[2]) const {
	return *this == point2_generic<T>(_point[0], _point[1]);
}

template <class T>
bool point2_generic<T>::operator == (const std::array<T, 2>& _point) const {
	return *this == point2_generic<T>(_point[0], _point[1]);
}
	
template <class T> 
point2_generic<T> point2_generic<T>::operator + (const point2_generic& point2) const {
	return point2_generic(this->x + point2.x, this->y + point2.y);
}

template <class T>
vector2_generic<T> point2_generic<T>::operator - (const point2_generic& point2) const {
	return vector2_generic (x - point2.x, y - point2.y);
}
*/
double node2d::distance_to(const node2d& node2) const {
	return std::sqrt(std::pow((this->x - node2.x), 2) + std::pow((this->y - node2.y), 2));
}


beam2d::beam2d (
	const node2d& start_point, const node2d& end_point, double cs, double e_mod) :
	start_point(start_point), end_point(end_point), cross_section(cs), young_modulus(e_mod)	{
		double l = this->get_length();
		double c = (this->end_point.x - this->start_point.x) / l;
		double s = (this->end_point.y - this->start_point.y) / l;
		double stiffness = this->cross_section * this->young_modulus / l;

		this->local_stiffness_matrix = {
			stiffness, -1 * stiffness,
			-1 * stiffness, stiffness
		};

		this->global_stiffness_matrix = {
			stiffness * c * c, stiffness * c * s, -1 * stiffness * c * c, -1 * stiffness * c * s,
			stiffness * c * s, stiffness * s * s, -1 * stiffness * c * s, -1 * stiffness * s * s,
			-1 * stiffness * c * c, -1 * stiffness * c * s, stiffness * c * c, stiffness * c * s,
			-1 * stiffness * c * s, -1 * stiffness * s * s, stiffness * c * s, stiffness * s * s
		};
	}

beam2d::beam2d (const double x1, const double y1,const double x2, const double y2) :
        start_point(node2d(x1, y1)), end_point(node2d(x2, y2)) {}

bool beam2d::operator == (const beam2d& beam2) const {
	return this->start_point == beam2.start_point && this->end_point == beam2.end_point;
}

double beam2d::get_length() { return this->start_point.distance_to(this->end_point); }
//auto line2d::get_direction() { return vector2d(start_point, end_point).normalise(); }
//auto line2d::get_normal() { return Line2d::get_direction.normal(); }
