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
/*
class Line2d : Base2d {
public:
	point2d StartPoint;
	point2d EndPoint;

	Line2d (point2d const &startPoint, point2d const &endPoint) {
		StartPoint = startPoint;
		EndPoint = endPoint;
	}

	Line2d (double x1, double y1, double x2, double y2) {
		StartPoint = point2d(x1, y1);
		EndPoint = point2d(x2, y2);
	}

	double GetLength() { return StartPoint.DistanceTo(EndPoint); }
	vector2d GetDirection() { return vector2d(StartPoint, EndPoint).Normalise(); }
	vector2d GetNormal() { return GetDirection.Normal(); }

};
*/
