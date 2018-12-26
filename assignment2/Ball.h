#pragma once

#include "Paddle.h"

#include <iosfwd>

namespace arkanoid
{

class Ball
{
private:
	int32_t rad;
	struct Velocity vel;
	struct Point center;
public:
	static constexpr int32_t DefaultHorizontalVelocity = 8;
	static constexpr int32_t DefaultVerticalVelocity = 8;

	// Implement the member functions listed below
	Ball();
	Ball(struct Point c, int32_t r,struct Velocity v);

	Velocity getVelocity() const;
	Point getCenter() const;
	int32_t getRadius() const;
	void setCenter(Point);
	void setVelocity(Velocity);
	void setRadius(int32_t);
	void moveBall();
	void setVelocity(int32_t, int32_t);
};

// Additional logic to let std::cout work with Ball objects
std::ostream& operator<<(std::ostream&, const Ball&);

}
