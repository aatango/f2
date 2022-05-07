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
		std::array<bool, 2> supports;

		node2d(const double x = 0, const double y = 0, const bool xx = false, const bool yy = false);

		// Exists mostly to allow other tests.
		bool operator == (const node2d& node2) const;

		double distance_to(const node2d& node2) const;

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
		node2d start_node;
		node2d end_node;
		double cross_section;
		double young_modulus;
		//double moment_inertia = 0; Not needed for truss structures

		/* saving both local and global stiffness matrices should help with execution speed,
                 * while not costing too much in space requirements.
                 * Also, these are symmetrical matrices, there's probably a way to optimise them.
                 */
		std::array<double, 16> global_stiffness_matrix;
		std::array<double, 4> local_stiffness_matrix;

		beam2d (
			const node2d& start_node,
			const node2d& end_node,
			const double cs = 0,
			const double e_mod = 0
		);
		beam2d (const double x1, const double y1, const double x2, const double y2);

		// Exists mostly to allow other tests.
		bool operator == (const beam2d& beam2) const;
	
		double get_length();
		/*vector2d get_direction();
		vector2d GetNormal();*/
	};
};

# endif // geom2d_hpp_INCLUDED
