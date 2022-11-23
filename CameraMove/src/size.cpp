#include "size.h"

#include <cmath>

namespace Geometry
{
	Size::Size(float w, float h)
		: width(w), height(h)
	{
	}

	void Size::set_width(float w)
	{
		width = w;
	}

	void Size::set_height(float h)
	{
		height = h;
	}

	float Size::w() const
	{
		return std::abs(width);
	}

	float Size::h() const
	{
		return std::abs(height);
	}
}