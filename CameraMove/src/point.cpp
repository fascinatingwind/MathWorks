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
}