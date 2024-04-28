#pragma once
#ifndef SIZE_H
#define SIZE_H

#include <cmath>

namespace Geometry
{
	/*
	* Here Width for X axis, Height for Y axis
	*/
	template<typename T>
	class Size
	{
	public:
		explicit Size(T w, T h) : width(w), height(h) {};

		void set_width(T w){ width = w; };
		void set_height(T h) { height = h; };

		// for X axis
		// always return absolute value
		T w() const { return std::abs(width); };

		// for Y axis
		// always return absolute value
		T h() const { return std::abs(height); };

	private:
		T width;
		T height;
	};

	using SizeF = Size<float>;
	using SizeD = Size<double>;
	using SizeI = Size<int>;
}
#endif