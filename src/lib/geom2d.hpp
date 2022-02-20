#include <cmath>
#include <Geom2d>

namespace Geom2d {
	class Base2d {
	}
	
	class Line2d : Base2d {
	public:
		Point2d StartPoint;
		Point2d EndPoint;

		Line2d (Point2d const &startPoint, Point2d const &endPoint) {
			(*this).StartPoint = startPoint;
			(*this).EndPoint = endPoint;
		}

		Line2d (double x1, double y1, double x2, double y2) {
			(*this).StartPoint = Point2d(x1, y1);
			(*this).EndPoint = Point2d(x2, y2);
		}

		double GetLength() { return StartPoint.DistanceTo(EndPoint); }
		Vector2d GetDirection() { return Vector2d(StartPoint, EndPoint).Normalise(); }
		Vector2d GetNormal() { return GetDirection.Normal(); }

	}

	class Point2d : Base2d {
	public:
		double X;
		double Y;

		Point2d (double x, double y) {
			(*this).X = x;
			(*this).Y = y;
		}

		Point2d static operator + (Point2d Point1, Point2d Point2) {
			return Point2d(Point1.X + Point2.X, Point1.Y + Point2.Y);
		}

		Geom2d::Vector2d static operator - (Point2d Point1, Point2d Point2) {
			return Vector2d (Point1.X - Point2.X, Point1.Y - Point2.Y);
		}

		double DistanceTo(Point2d Point2) {
			return std::sqrt(std::pow((X - Point2.X), 2) + std::pow(Y - Point2.Y), 2);
		}

		Point2d Move(Vector2d Vector) {
			return Vector2d(X + Vector.U, Y + Vector.V);
		}

		Point2d Rotate(double angleDeg, double u = 0, double v = 0) {
		private:
			double Pi = 3.14159;
			double AngleRad = Pi * angleDeg / 180;
			double Sin = std::Sin(AngleRad);
			double Cos = std::Cos(AngleRad);

			return Point2d(
				X * Cos - Y * Sin + u * (1 - Cos) + v * Sin,
				X * Sin + Y * Cos + v * (1 - Cos) - u * Sin
			);
		}

		Point2d Scale(double scaleX, double scaleY, double u = 0; double v = 0) {
			return Point2d(
				X * scaleX + u * (1 - scaleX),
				Y * scaleY + v * (1 - scaleY)
			);
		}
	}

	class Vector2d {}
};
