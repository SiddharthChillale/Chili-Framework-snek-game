#include "Goal.h"

Goal::Goal(std::mt19937& rng, const Board& brd, const Snake& snek)
{
	Respawn(rng, brd, snek);
}

void Goal::Respawn(std::mt19937& rng, const Board& brd, const Snake& snek)
{
	std::uniform_int_distribution<int> xDist(0, brd.GetGridWidth() - 10);
	std::uniform_int_distribution<int> yDist(0, brd.GetGridHeight() - 10);

	Location newLoc;

	do {
		newLoc.x = xDist(rng);
		newLoc.y = yDist(rng);
	} while(snek.IsInTile(newLoc));
	
	loc = newLoc;

}

void Goal::Draw(Board& brd) const
{
	//brd.DrawCell(loc, c); // code from Chili for drawing food
	brd.DrawFood(loc);      // Use a putpixel graphic of pumpkin
}

const Location& Goal::GetLocation() const
{
	return loc;
}


bool Goal::IsInTile(const Location& target) const
{
	if (Goal::loc == target) {
		return true;
	}
	else {
		return false;
	}
}