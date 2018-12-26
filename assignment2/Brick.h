#pragma once

#include "Point.h"

#include <iosfwd>

namespace arkanoid
{

class Brick
{
private:
	Point leftup, rightdown;
public:
	// Implement the member functions listed below
	Brick();
	Brick(Point b, int32_t w, int32_t h);

	Point getUpperLeft() const;
	Point getLowerRight() const;
	void setUpperLeft(Point);
	void setLowerRight(Point);

};

// Additional logic to let std::cout work with Brick objects
std::ostream& operator<<(std::ostream&, const Brick&);

}
