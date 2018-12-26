#pragma once

#include "Ball.h"
#include "Brick.h"
#include "Input.h"
#include "Paddle.h"

#include <iosfwd>
#include <vector>

namespace arkanoid
{

class World
{
private:
	int32_t width, height;
	Ball bposition;
	Paddle pposition;
	std::vector<Brick> bricks;
public:
	// Implement the member functions listed below

	World(int32_t w, int32_t h, Ball b, Paddle p, std::vector<Brick> bricks);

	int32_t getWidth() const;
	int32_t getHeight() const;
	Ball getBall() const;
	Paddle getPaddle() const;
	std::vector<Brick> getBricks() const;

	bool isLegal() const;
	void update(Input);
};

// The type of the exception that needs to be thrown when the game is over
class GameOverException: std::exception {};

// Additional logic to let std::cout work with World objects
std::ostream& operator<<(std::ostream&, const std::vector<Brick>&);
std::ostream& operator<<(std::ostream&, const World&);

}
