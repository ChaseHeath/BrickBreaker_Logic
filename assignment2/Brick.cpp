#include "Brick.h"

#include <ostream>

namespace arkanoid
{
	Brick::Brick()
	{
	}
	Brick::Brick(Point b, int32_t w, int32_t h)
	{
		leftup.x = b.x;
		leftup.y = b.y;
		rightdown.x = b.x + w;
		rightdown.y = b.y + h;
	}
	Point Brick::getUpperLeft() const
	{
		return leftup;
	}
	Point Brick::getLowerRight() const
	{
		return rightdown;
	}
	void Brick::setUpperLeft(Point b)
	{
		leftup.x = b.x;
		leftup.y = b.y;
	}
	void Brick::setLowerRight(Point b)
	{
		rightdown.x = b.x;
		rightdown.y = b.y;
	}
std::ostream& operator<<(std::ostream& os, const Brick& brick) {
	os << "Brick { " << brick.getUpperLeft() << ", " << brick.getLowerRight() << " }";
	return os;
}

}
