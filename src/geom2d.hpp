#ifndef H_GEOM2D
#define GEOM2D_H

#include <array>

namespace geom2 {

	template <class T>
	class base2 {
	};


	template <class T>
	class vector2_generic : base2<T> {
	public:
		T u;
		T v;

		vector2_generic ();
		vector2_generic (const T _u, const T _v); 
	};
	template class vector2_generic<float>;
	template class vector2_generic<double>;
	typedef vector2_generic<float> vector2f;
	typedef vector2_generic<double> vector2d;

	template <class T>
	class point2_generic : base2<T> {
	public:
		T x = 0;
		T y = 0;

		point2_generic ();
		point2_generic (const T _x, const T _y);

		bool operator == (const point2_generic& point2) const;
		point2_generic operator + (const point2_generic& point2) const;
		geom2::vector2_generic<T> operator - (const point2_generic& point2) const;

		T distance_to(const point2_generic& point2);

		/*
		vector2d move(vector2d vector);

		point2d rotate(double angle_deg, double u,  double v);

		point2d scale(double scale_x, double scale_y, double u, double v);
		*/
	};
	template class point2_generic<float>;
	template class point2_generic<double>;
	typedef point2_generic<float> point2f;
	typedef point2_generic<double> point2d;

	template <class T>
	class node2_generic : public point2_generic<T> {
	public:
		int id = 0;
		std::array<T, 3> loads;
		std::array<T, 3> supports;

		node2_generic ();
		node2_generic (const T _x, const T _y);
	};
	template class node2_generic<float>;
	template class node2_generic<double>;
	typedef node2_generic<float> node2f;
	typedef node2_generic<double> node2d;

	
	class line2d : base2<double> {
	public:
		point2d start_point;
		point2d end_point;

		line2d (const point2d& _start_point, const point2d& _end_point);
		line2d (const double _x1, const double _y1, const double _x2, const double _y2);
		
		double get_length();
		vector2d get_direction();
		vector2d GetNormal();
	};
	/*
	class beam2d : line2d {
	public:
		int id = 0;
		double cross_section = 0;
		double young_modulus = 0;
	*/
};
# endif
