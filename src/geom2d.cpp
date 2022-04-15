#include <cmath>

#include "geom2d.hpp"


using namespace geom2;


template<class T>
vector2_generic<T>::vector2_generic () {}

template <class T> 
vector2_generic<T>::vector2_generic (const T _u, const T _v): u(_u), v(_v) {}


template<class T>
point2_generic<T>::point2_generic () {}

template <class T> 
point2_generic<T>::point2_generic (const T _x, const T _y): x(_x), y(_y) {}

template <class T> 
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


template <class T>
node2_generic<T>::node2_generic () {}

template <class T>
node2_generic<T>::node2_generic (const T _x, const T _y) {
	this->x = _x;
	this->y = _y;
}
/*
vector2d point2d::move(vector2d vector) {
	return vector2d(x + vector.u, y + vector.v);
}

point2d point2d::rotate(double angle_deg, double u = 0, double v = 0) {
	double angle_rad = 3.14159 * angle_deg / 180;
	double sin = std::sin(angle_rad);
	double cos = std::cos(angle_rad);

	return point2d(
		x * cos - y * sin + u * (1 - cos) + v * sin,
		x * sin + y * cos + v * (1 - cos) - u * sin
	);
}

point2d point2d::scale(double scale_x, double scale_y, double u = 0, double v = 0) {
	return point2d(
		x * scale_x + u * (1 - scale_x),
		y * scale_y + v * (1 - scale_y)
	);
}
*/
line2d::line2d (const point2d& _start_point, const point2d& _end_point) : 
	start_point(_start_point), end_point(_end_point) {}

line2d::line2d (const double _x1, const double _y1, const double _x2, const double _y2) :
	start_point(point2d(_x1, _y1)), end_point(point2d(_x2, _y2)) {}

double line2d::get_length() { return start_point.distance_to(end_point); }
//auto line2d::get_direction() { return vector2d(start_point, end_point).normalise(); }
//auto line2d::get_normal() { return Line2d::get_direction.normal(); }
