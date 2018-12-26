#include "Ball.h"

#include <ostream>

namespace arkanoid
{
Ball::Ball()
{
}
Ball::Ball(Point c, int32_t r,Velocity v)
{
	center.x = c.x;
	center.y = c.y;
	rad = r;
	vel.vx = v.vx;
	vel.vy = v.vy;
}
struct Point Ball::getCenter() const
{

	return center;
}
struct Velocity Ball::getVelocity() const
{

	return vel;
}
int32_t Ball::getRadius() const
{

	return rad;
}
void Ball::setCenter(struct Point c)
{
	center.x = c.x;
	center.y = c.y;
}
void Ball::setVelocity(struct Velocity v)
{
vel.vx = v.vx;
vel.vy = v.vy;
}
void Ball::setVelocity(int32_t x, int32_t y)
{
	vel.vx = x;
	vel.vy = y;
}
void Ball::setRadius(int32_t r)
{
	rad = r;
}
void Ball::moveBall()
{
	center.x += vel.vx;
	center.y += vel.vy;
}
std::ostream& operator<<(std::ostream& os, const Ball& ball) {

	os << "Ball { center = " << ball.getCenter() << ", radius = " << ball.getRadius() << ", velocity = " << ball.getVelocity() << " }";
	return os;
}

}
