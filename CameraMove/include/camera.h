#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include "point.h"
#include "size.h"

namespace Game
{
	class Camera
	{
		using Point = Geometry::Point;
		using Size = Geometry::Size;

	public:
		Camera(const Point& point, const Size& size);
		Camera(Point&& point, Size&& size);

		Point center() const;
		void set_center(const Point& point);

		Size size() const;
		void set_size(const Size& size);

		Point top_left() const;
		Point top_right() const;
		Point bottom_left() const;
		Point bottom_right() const;

	private:
		Point center_point;
		Size camera_size;
	};
}
#endif