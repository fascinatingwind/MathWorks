#include "camera.h"

#include <utility>

using namespace Geometry;

namespace Game
{
	Camera::Camera(const Point& point, const Size& size)
		: center_point(point), camera_size(size)
	{
	}

	Camera::Camera(Point&& point, Size&& size)
		: center_point(std::forward<Point>(point))
		, camera_size(std::forward<Size>(size))
	{
	}

	Point Camera::center() const
	{
		return center_point;
	}

	void Camera::set_center(const Point& point)
	{
		center_point = point;
	}

	void Camera::set_size(const Size& size)
	{
		camera_size = size;
	}

	Point Camera::top_left() const
	{
		return center_point + Point(-camera_size.w() / 2, camera_size.h() / 2);
	}

	Point Camera::top_right() const
	{
		return center_point + Point(camera_size.w() / 2, camera_size.h() / 2);
	}

	Point Camera::bottom_left() const
	{
		return center_point - Point(camera_size.w() / 2, camera_size.h() / 2);
	}

	Point Camera::bottom_right() const
	{
		return center_point + Point(camera_size.w() / 2, -camera_size.h() / 2);
	}

	Size Camera::size() const
	{
		return camera_size;
	}
}