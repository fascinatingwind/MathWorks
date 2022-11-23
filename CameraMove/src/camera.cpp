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

	Size Camera::size() const
	{
		return camera_size;
	}
}