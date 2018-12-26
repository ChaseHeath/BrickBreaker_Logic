#pragma once

#include "Input.h"
#include "Point.h"

#include <iosfwd>

namespace arkanoid
{

class Paddle
{
private:
	struct Point upleft;
	struct Point lowright;
	int32_t vel, paddle_width;
public:
	static constexpr int32_t DefaultVelocity = 10;

	// Implement the member functions listed below
	Paddle();
	Paddle(Point p, int32_t w, int32_t h, int32_t v);

	Point getUpperLeft() const;
	Point getLowerRight() const;
	int32_t getVelocity() const;
	int32_t getPaddleWidth() const;
	void setUpperLeft(Point);
	void setLowerRight(Point);
	void setVelocity(int32_t);
	void movePaddle();
	void leftEdgePaddle();
	void rightEdgePaddle(int32_t);
};

// Additional logic to let std::cout work with Paddle objects
std::ostream& operator<<(std::ostream&, const Paddle&);

}
