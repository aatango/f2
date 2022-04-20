#ifndef geom2d_hpp_INCLUDED
#define geom2d_hpp_INCLUDED

#include <array>

namespace geom2d {
	struct node2d {
		unsigned char id;
		double x;
		double y;
		std::array<double, 2> forces;
		std::array<double, 2> displacements;

		node2d();
		node2d(const double _x, const double _y);


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


	struct beam2d {
		unsigned char id;
		node2d start_point;
		node2d end_point;
		double cross_section;
		double young_modulus;

		beam2d (const unsigned char _id, const node2d& _start_point, const node2d& _end_point);
		beam2d (const unsigned char _id,
		        const double _x1, const double _y1,
		        const double _x2, const double _y2);
	
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
