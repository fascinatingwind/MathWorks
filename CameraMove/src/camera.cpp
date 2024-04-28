#include "camera.h"

#include <utility>

using namespace Geometry;

namespace Game
{
	Camera::Camera(const PointF& point, const SizeF& size)
		: center_point(point), camera_size(size)
	{
	}

	Camera::Camera(PointF&& point, SizeF&& size)
		: center_point(std::forward<PointF>(point))
		, camera_size(std::forward<SizeF>(size))
	{
	}

	PointF Camera::center() const
	{
		return center_point;
	}

	void Camera::set_center(const PointF& point)
	{
		center_point = point;
	}

	void Camera::set_size(const SizeF& size)
	{
		camera_size = size;
	}

	PointF Camera::top_left() const
	{
		return center_point + PointF(-camera_size.w() / 2, camera_size.h() / 2);
	}

	PointF Camera::top_right() const
	{
		return center_point + PointF(camera_size.w() / 2, camera_size.h() / 2);
	}

	PointF Camera::bottom_left() const
	{
		return center_point - PointF(camera_size.w() / 2, camera_size.h() / 2);
	}

	PointF Camera::bottom_right() const
	{
		return center_point + PointF(camera_size.w() / 2, -camera_size.h() / 2);
	}

	SizeF Camera::size() const
	{
		return camera_size;
	}
}