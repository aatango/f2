#include <cmath>

#include "geom2d.hpp"


using namespace geom2d;

node2d::node2d() : x(0), y(0) {}
node2d::node2d(const double _x, const double _y) :  x(_x), y(_y) {}

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

template <class T> 
T point2_generic<T>::distance_to(const point2_generic& point2) {
	return std::sqrt(std::pow((x - point2.x), 2) + std::pow((y - point2.y), 2));
}
*/

beam2d::beam2d (const unsigned char _id, const node2d& _start_point, const node2d& _end_point) :
	id(_id), start_point(_start_point), end_point(_end_point) {}

beam2d::beam2d (const unsigned char _id,
        const double _x1, const double _y1,
        const double _x2, const double _y2) :
        id(_id), start_point(node2d(_x1, _y1)), end_point(node2d(_x2, _y2)) {}

//double line2d::get_length() { return start_point.distance_to(end_point); }
//auto line2d::get_direction() { return vector2d(start_point, end_point).normalise(); }
//auto line2d::get_normal() { return Line2d::get_direction.normal(); }
