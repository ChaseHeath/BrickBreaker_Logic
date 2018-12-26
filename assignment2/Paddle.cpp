#include "Paddle.h"

#include <ostream>

namespace arkanoid
{
	Paddle::Paddle()
	{
	}
	Paddle::Paddle(Point p, int32_t w, int32_t h, int32_t v)
	{
		paddle_width = w;
		lowright.x = p.x + w;
		lowright.y = p.y + h;
		upleft.x = p.x;
		upleft.y = p.y;
		vel = v;
	}
struct Point Paddle::getLowerRight() const
	{
	return lowright;
	}
struct Point Paddle::getUpperLeft() const
	{
	return upleft;
	}
int32_t Paddle::getVelocity() const
	{
	return vel;
	}
int32_t Paddle::getPaddleWidth() const
{
	return paddle_width;
}
void Paddle::setLowerRight(struct Point p)
{
	lowright.x = p.x;
	lowright.y = p.y;
}
void Paddle::setUpperLeft(struct Point p)
{
	upleft.x = p.x;
	upleft.y = p.y;
}
void Paddle::setVelocity(int32_t v)
{
	vel = v;
}
void Paddle::movePaddle()
{
	upleft.x += vel;
	lowright.x += vel;
}
void Paddle::leftEdgePaddle()
{
	upleft.x = 0;
	lowright.x = 0 + paddle_width;
}
void Paddle::rightEdgePaddle(int32_t world_width)
{
	upleft.x = world_width - paddle_width;
	lowright.x = world_width;
}
std::ostream& operator<<(std::ostream& os, const Paddle& paddle) {
	os << "Paddle { " << paddle.getUpperLeft() << ", " << paddle.getLowerRight() << ", velocity = " << paddle.getVelocity() << " }"; 
	return os;
}

}
