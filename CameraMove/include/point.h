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

	protected:
		float x_coord = 1.f;
		float y_coord = 1.f;
	};
}

#endif