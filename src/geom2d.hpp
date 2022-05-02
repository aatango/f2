#ifndef geom2d_hpp_INCLUDED
#define geom2d_hpp_INCLUDED

#include <array>

namespace geom2d {
	struct node2d {
		//unsigned char id;
		double x;
		double y;
		std::array<double, 2> forces;
		std::array<double, 2> displacements;

		node2d(const double x = 0, const double y = 0);

		// Exists mostly to allow other tests.
		bool operator == (const node2d& node2) const;


/*		point2_generic operator + (const point2_generic& point2) const;
		geom2::vector2_generic<T> operator - (const point2_generic& point2) const;

		T distance_to(const point2_generic& point2);

		vector2d move(vector2d vector);

		point2d rotate(double angle_deg, double u,  double v);

		point2d scale(double scale_x, double scale_y, double u, double v);
*/
	};

	// Currently defined as a bar element (axial stresses only).
	struct beam2d {
		//unsigned char id;
		node2d start_point;
		node2d end_point;
		double cross_section = 0;
		double young_modulus = 0;
		//double moment_inertia = 0; Not needed for truss structures
		std::array<double, 16> stiffness_matrix; // Symmetrical matrix, surely it can be optimised.

		beam2d (const node2d& start_point, const node2d& end_point);
		beam2d (const double x1, const double y1, const double x2, const double y2);

		// Exists mostly to allow other tests.
		bool operator == (const beam2d& beam2) const;
	
		/*double get_length();
		vector2d get_direction();
		vector2d GetNormal();*/
	};
};

# endif // geom2d_hpp_INCLUDED
