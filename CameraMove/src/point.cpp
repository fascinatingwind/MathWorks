#include "point.h"

namespace Geometry
{
	Point::Point(float x, float y)
		: x_coord(x), y_coord(y)
	{
	}

	float Point::x() const
	{
		return x_coord;
	}

	float Point::y() const
	{
		return y_coord;
	}

	void Point::set_x(float x)
	{
		x_coord = x;
	}

	void Point::set_y(float y)
	{
		y_coord = y;
	}

	Point Point::operator+(const Point& rhs) const
	{
		return { x_coord + rhs.x_coord, y_coord + rhs.y_coord };
	}

	Point Point::operator-(const Point& rhs) const
	{
		return { x_coord - rhs.x_coord, y_coord - rhs.y_coord };
	}

	Point& Point::operator+=(const Point& rhs)
	{
		x_coord += rhs.x_coord;
		y_coord += rhs.y_coord;
		return *this;
	}

	Point& Point::operator-=(const Point& rhs)
	{
		x_coord -= rhs.x_coord;
		y_coord -= rhs.y_coord;
		return *this;
	}

	Point Point::operator+(float value) const
	{
		return { x_coord + value, y_coord + value };
	}

	Point Point::operator-(float value) const
	{
		return { x_coord - value, y_coord - value };
	}

	Point& Point::operator+=(float value)
	{
		x_coord += value;
		y_coord += value;
		return *this;
	}

	Point& Point::operator-=(float value)
	{
		x_coord -= value;
		y_coord -= value;
		return *this;
	}
}