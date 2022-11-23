#pragma once
#ifndef SIZE_H
#define SIZE_H

namespace Geometry
{
	class Size
	{
	public:
		Size(float w, float h);

		void set_width(float w);
		void set_height(float h);

		float w() const;
		float h() const;

	private:
		float width = 1.f;
		float height = 1.f;
	};
}
#endif