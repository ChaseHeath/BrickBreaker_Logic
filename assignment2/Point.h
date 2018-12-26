#pragma once

#include <cstdint>
#include <iosfwd>

namespace arkanoid
{

struct Point
{
	int32_t x, y;
};

struct Velocity
{
	int32_t vx, vy;
};

std::ostream& operator<<(std::ostream&, Point);
std::ostream& operator<<(std::ostream&, Velocity);

Point updatePoint(Point, Velocity);

}
