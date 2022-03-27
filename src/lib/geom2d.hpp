#include <cmath>

namespace Geom2d {
	class Base2d {
	};

	class Vector2d : Base2d {
	public:
		double U;
		double V;

		Vector2d (double x, double y) {
			U = x;
			V = y;
		};
	};

	class Point2d : Base2d {
	public:
		double X;
		double Y;

		Point2d (double x, double y) {
			X = x;
			Y = y;
		}

		Point2d operator + (Point2d Point2) {
			return Point2d(X + Point2.X, Y + Point2.Y);
		}

		Geom2d::Vector2d operator - (Point2d Point2) {
			return Vector2d (X - Point2.X, Y - Point2.Y);
		}

		double DistanceTo(Point2d Point2) {
			return std::sqrt(std::pow((X - Point2.X), 2) + std::pow((Y - Point2.Y), 2));
		}

		Vector2d Move(Vector2d Vector) {
			return Vector2d(X + Vector.U, Y + Vector.V);
		}

		Point2d Rotate(double angleDeg, double u = 0, double v = 0) {
			double AngleRad = 3.14159 * angleDeg / 180;
			double Sin = std::sin(AngleRad);
			double Cos = std::cos(AngleRad);

			return Point2d(
				X * Cos - Y * Sin + u * (1 - Cos) + v * Sin,
				X * Sin + Y * Cos + v * (1 - Cos) - u * Sin
			);
		}

		Point2d Scale(double scaleX, double scaleY, double u = 0, double v = 0) {
			return Point2d(
				X * scaleX + u * (1 - scaleX),
				Y * scaleY + v * (1 - scaleY)
			);
		}
	};

	/*
	class Line2d : Base2d {
	public:
		Point2d StartPoint;
		Point2d EndPoint;

		Line2d (Point2d const &startPoint, Point2d const &endPoint) {
			StartPoint = startPoint;
			EndPoint = endPoint;
		}

		Line2d (double x1, double y1, double x2, double y2) {
			StartPoint = Point2d(x1, y1);
			EndPoint = Point2d(x2, y2);
		}

		double GetLength() { return StartPoint.DistanceTo(EndPoint); }
		Vector2d GetDirection() { return Vector2d(StartPoint, EndPoint).Normalise(); }
		Vector2d GetNormal() { return GetDirection.Normal(); }

	};
	*/
};
