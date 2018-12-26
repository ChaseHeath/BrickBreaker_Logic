#include "World.h"

#include <ostream>

namespace arkanoid
{
	World::World(int32_t w, int32_t h, Ball b, Paddle p, std::vector<Brick> bs)
	{


																//initialize each object with its' starting values
		width = w;
		height = h;
		bposition.setCenter(b.getCenter());
		bposition.setRadius(b.getRadius());
		bposition.setVelocity(b.getVelocity());
		pposition.setUpperLeft(p.getUpperLeft());
		pposition.setLowerRight(p.getLowerRight());
		pposition.setVelocity(p.getVelocity());
		bricks = bs;
	}	
	int32_t World::getWidth() const
	{
		return width;
	}
	int32_t World::getHeight() const
	{
		return height;
	}
	Ball World::getBall() const
	{
		return bposition;
	}
	Paddle World::getPaddle() const
	{

		return pposition;
	}
	std::vector<Brick> World::getBricks() const
	{
		return bricks;
	}
	bool World::isLegal() const
	{
		auto itr = bricks.begin();
		if (bricks.size() == 0)				//must have 1 brick in world
			return 0;
		if (bposition.getVelocity().vx == 0 || bposition.getVelocity().vy == 0)		//ball's velocity must not be 0
			return 0;
		if (bposition.getCenter().x + bposition.getRadius() > width || bposition.getCenter().x - bposition.getRadius() < 0 ||		//the ball must be in the world
			bposition.getCenter().y + bposition.getRadius() > height || bposition.getCenter().y - bposition.getRadius() < 0)
			return 0;
		if (pposition.getLowerRight().x > width || pposition.getLowerRight().y > height ||		//the paddle must be in the world
			pposition.getUpperLeft().x < 0 || pposition.getUpperLeft().y < 0)
			return 0;
		for (; itr != bricks.end(); itr++)
		{
			if ((*itr).getUpperLeft().x < 0 || (*itr).getUpperLeft().y < 0 || (*itr).getLowerRight().x > width || (*itr).getLowerRight().y > height)	//bricks should be inside world
				return 0;
		}
		printf("Checking Ball/Paddle\n");
		if (bposition.getCenter().x + bposition.getRadius() > pposition.getUpperLeft().x				//checking if the ball hits the paddle
			&& bposition.getCenter().x - bposition.getRadius() < pposition.getLowerRight().x
			&& bposition.getCenter().y + bposition.getRadius() < pposition.getLowerRight().y
			&& bposition.getCenter().y - bposition.getRadius() > pposition.getUpperLeft().y )
		{
			printf("Collision\n");
			return 0;
		}
			itr = bricks.begin();
			printf("Checking Ball/Brick\n");
		for (; itr != bricks.end(); itr++)
		{																							//checking if the ball intersects a brick
			if (bposition.getCenter().x + bposition.getRadius() > (*itr).getUpperLeft().x 
				&& bposition.getCenter().x - bposition.getRadius() < (*itr).getLowerRight().x
				&& bposition.getCenter().y + bposition.getRadius() < (*itr).getLowerRight().y 
				&& bposition.getCenter().y - bposition.getRadius() > (*itr).getUpperLeft().y)
			{	
				printf("Collision\n");
				return 0;
			}
			}
		itr = bricks.begin();
		printf("Checking Brick/Paddle\n");
		for (; itr != bricks.end(); itr++)
		{
			if (pposition.getUpperLeft().x < (*itr).getLowerRight().x							//checking if any brick intersects the paddle
				&& pposition.getLowerRight().x >(*itr).getUpperLeft().x
				&& pposition.getUpperLeft().y < (*itr).getLowerRight().y 
				&& pposition.getLowerRight().y > (*itr).getUpperLeft().y)
			{
				printf("Collision\n");
				return 0;
			}
		}
		itr = bricks.begin();
		auto itr2 = bricks.begin();
		printf("Checking Brick/Brick\n");
		for (; itr != bricks.end(); itr++)
		{
			for (; itr2 != bricks.end(); itr2++)										//checking if any bricks intersect other bricks
			{
				if ((!(itr == itr2)) && (*itr2).getUpperLeft().x < (*itr).getLowerRight().x 
					&& (*itr2).getLowerRight().x> (*itr).getUpperLeft().x
					&& (*itr2).getUpperLeft().y < (*itr).getLowerRight().y 
					&& (*itr2).getLowerRight().y > (*itr).getUpperLeft().y)
				{
					printf("Collision\n");
					return 0;
				}
			}
		}

			return 1;
	}
	void World::update(Input input)
	{
		if (input == Input::None)								//change the paddle's velocity accordingly
			pposition.setVelocity(0);
		if (input == Input::Left)
			pposition.setVelocity(-Paddle::DefaultVelocity);
		if (input == Input::Right)
			pposition.setVelocity(Paddle::DefaultVelocity);
		pposition.movePaddle();									//update paddle's and ball's position
		if(pposition.getUpperLeft().x < 0)
			pposition.leftEdgePaddle();
		if(pposition.getLowerRight().x > width)
			pposition.rightEdgePaddle(width);

		bposition.moveBall();
		if (bposition.getCenter().y + bposition.getRadius() > height)
			throw GameOverException();
		if (bposition.getCenter().x + bposition.getRadius()> width)					//check if the ball hits's something and update the game/velocity accordingly
			bposition.setVelocity(-Ball::DefaultHorizontalVelocity,bposition.getVelocity().vy);
		if (bposition.getCenter().x + bposition.getRadius()< 0)
			bposition.setVelocity(Ball::DefaultHorizontalVelocity,bposition.getVelocity().vy);
		if (bposition.getCenter().y - bposition.getRadius() < 0)
			bposition.setVelocity(bposition.getVelocity().vx, Ball::DefaultVerticalVelocity);
		if (bposition.getCenter().y + bposition.getRadius() > pposition.getUpperLeft().y)
			bposition.setVelocity(bposition.getVelocity().vx, -Ball::DefaultVerticalVelocity);
		
		auto itr3 = bricks.begin();
		for (; itr3 != bricks.end(); itr3++)
		{
			if (bposition.getCenter().x + bposition.getRadius() > (*itr3).getUpperLeft().x
				&& bposition.getCenter().x - bposition.getRadius() < (*itr3).getLowerRight().x
				&& bposition.getCenter().y + bposition.getRadius() < (*itr3).getLowerRight().y
				&& bposition.getCenter().y - bposition.getRadius() > (*itr3).getUpperLeft().y)
				bricks.erase(itr3);
		}
	}
std::ostream& operator<<(std::ostream& os, const std::vector<Brick>& bricks) {
	os << "[ ";
	for (auto const& b: bricks)
		os << b << "; ";
	os << "]";
	return os;
}

std::ostream& operator<<(std::ostream& os, const World& world) {
	os << "World {\n  width = " << world.getWidth() << "\n  height = " << world.getHeight() << "\n  " << world.getBall() << ",\n  " << world.getPaddle() << ",\n  " << world.getBricks() << "\n}";

	return os;
}

}
