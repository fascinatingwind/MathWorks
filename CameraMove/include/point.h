#pragma once
#ifndef POINT_H
#define POINT_H

namespace Geometry
{
	class Point
	{
	public:
		Point(float x, float y);

		float x();
		float y();

		void set_x(float x);
		void set_y(float y);

	protected:
		float x_coord;
		float y_coord;
	};
}

#endif