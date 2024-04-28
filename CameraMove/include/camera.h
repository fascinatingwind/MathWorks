#pragma once
#ifndef CAMERA_H
#define CAMERA_H

#include "point.h"
#include "size.h"

namespace Game
{
	class Camera
	{
		using PointF = Geometry::PointF;
		using SizeF = Geometry::SizeF;

	public:
		Camera(const PointF& point, const SizeF& size);
		Camera(PointF&& point, SizeF&& size);

		PointF center() const;
		void set_center(const PointF& point);

		SizeF size() const;
		void set_size(const SizeF& size);

		PointF top_left() const;
		PointF top_right() const;
		PointF bottom_left() const;
		PointF bottom_right() const;

	private:
		PointF center_point;
		SizeF camera_size;
	};
}
#endif