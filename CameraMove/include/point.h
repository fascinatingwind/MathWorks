#pragma once
#ifndef POINT_H
#define POINT_H

namespace Geometry
{
	class Point
	{
	public:
		Point(float x, float y);

		float x() const;
		float y() const;

		void set_x(float x);
		void set_y(float y);

		Point operator+(const Point& rhs) const;
		Point operator-(const Point& rhs) const;

		Point& operator+=(const Point& rhs);
		Point& operator-=(const Point& rhs);

		Point operator+(float value) const;
		Point operator-(float value) const;

		Point& operator+=(float value);
		Point& operator-=(float value);

	protected:
		float x_coord = 1.f;
		float y_coord = 1.f;
	};
}

#endif