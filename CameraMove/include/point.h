#pragma once
#ifndef POINT_H
#define POINT_H

namespace Geometry
{
	template<typename T>
	class Point
	{
	public:
		Point(T x, T y) : x_coord(x), y_coord(y) {};

		T x() const { return x_coord; };
		T y() const { return y_coord; };

		void set_x(T x) { x_coord = x; };
		void set_y(T y) { y_coord = y; };

		Point operator+(const Point& rhs) const
		{
			return { x_coord + rhs.x_coord, y_coord + rhs.y_coord };
		};

		Point operator-(const Point& rhs) const
		{
			return { x_coord - rhs.x_coord, y_coord - rhs.y_coord };
		}

		Point& operator+=(const Point& rhs)
		{
			x_coord += rhs.x_coord;
			y_coord += rhs.y_coord;
			return *this;
		}

		Point& operator-=(const Point& rhs)
		{
			x_coord -= rhs.x_coord;
			y_coord -= rhs.y_coord;
			return *this;
		}

		Point operator+(float value) const
		{
			return { x_coord + value, y_coord + value };
		}

		Point operator-(float value) const
		{
			return { x_coord - value, y_coord - value };
		}

		Point& operator+=(float value)
		{
			x_coord += value;
			y_coord += value;
			return *this;
		}

		Point& operator-=(float value)
		{
			x_coord -= value;
			y_coord -= value;
			return *this;
		}

	protected:
		T x_coord;
		T y_coord;
	};

	using PointF = Point<float>;
	using PointD = Point<double>;
	using PointI = Point<int>;
}

#endif