#ifndef geom2d_hpp_INCLUDED
#define geom2d_hpp_INCLUDED

#include <array>

namespace geom2d {
	class node2d {
		public:
		unsigned char _id;
		double _x;
		double _y;
		std::array<double, 2> _forces;
		std::array<double, 2> _displacements;

		public:
		node2d();
		node2d(const double x, const double y);

/*		bool operator == (const point2_generic& point2) const;
		bool operator == (const  T _point[2]) const;
		bool operator == (const std::array<T, 2>& _point) const;
		point2_generic operator + (const point2_generic& point2) const;
		geom2::vector2_generic<T> operator - (const point2_generic& point2) const;

		T distance_to(const point2_generic& point2);

		vector2d move(vector2d vector);

		point2d rotate(double angle_deg, double u,  double v);

		point2d scale(double scale_x, double scale_y, double u, double v);
*/
	};


	class beam2d {
		unsigned char _id;
		node2d _start_point;
		node2d _end_point;
		double _cross_section;
		double _young_modulus;

	public:
		beam2d (const unsigned char id, const node2d& start_point, const node2d& end_point);
		beam2d (const unsigned char id,
		        const double x1, const double y1,
		        const double x2, const double y2);
	
		/*double get_length();
		vector2d get_direction();
		vector2d GetNormal();*/
	};
	/*
	class beam2d : line2d {
	public:
		int id = 0;
		double cross_section = 0;
		double young_modulus = 0;
	*/
};

# endif // geom2d_hpp_INCLUDED
