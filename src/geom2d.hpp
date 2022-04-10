
namespace geom2 {

	template <class T>
	class base2 {
	};


	template <class T>
	class vector2_generic : base2<T> {
	public:
		T u;
		T v;

		vector2_generic();
		vector2_generic (const T _u, const T _v); 
	};

	template class vector2_generic<float>;
	typedef vector2_generic<float> vector2f;

	template class vector2_generic<double>;
	typedef vector2_generic<double> vector2d;


	template <class T>
	class point2_generic : base2<T> {
	public:
		T x;
		T y;

		point2_generic ();
		point2_generic (const T _x, const T _y);

		bool operator == (const point2_generic& point2) const;
		
		point2_generic operator + (const point2_generic& point2) const;

		geom2::vector2_generic<T> operator - (const point2_generic& point2) const;

		T distance_to(point2_generic& point2);

		/*
		vector2d move(vector2d vector);

		point2d rotate(double angle_deg, double u,  double v);

		point2d scale(double scale_x, double scale_y, double u, double v);
		*/
	};

	template class point2_generic<float>;
	typedef point2_generic<float> point2f;

	template class point2_generic<double>;
	typedef point2_generic<double> point2d;

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
};
