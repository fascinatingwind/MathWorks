#include "size.h"

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
		return width;
	}

	float Size::h() const
	{
		return height;
	}
}