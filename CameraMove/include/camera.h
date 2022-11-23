#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include "point.h"
#include "size.h"

namespace Game
{
	using Point = Geometry::Point;
	using Size = Geometry::Size;

	class Camera
	{
	public:
		Camera(const Point& point, const Size& size);
		Camera(Point&& point, Size&& size);

		Point center() const;
		void set_center(const Point& point);

		Size size() const;
		void set_size(const Size& size);

	private:
		Point center_point;
		Size camera_size;
	};
}
#endif