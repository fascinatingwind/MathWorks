#pragma once
#ifndef SIZE_H
#define SIZE_H

namespace Geometry
{
	/*
	* Here Width for X axis, Height for Y axis
	*/
	class Size
	{
	public:
		Size(float w, float h);

		void set_width(float w);
		void set_height(float h);

		// for X axis
		// always return absolute value
		float w() const;

		// for Y axis
		// always return absolute value
		float h() const;

	private:
		float width = 1.f;
		float height = 1.f;
	};
}
#endif