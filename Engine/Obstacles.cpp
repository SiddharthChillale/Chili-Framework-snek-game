#include "Obstacles.h"


Obstacles::Obstacles(std::mt19937& rng, const Board& brd,const Snake& snek,const Goal& goal, const Location& loc)
{
	obstacles[0].Init(loc);
	
}

void Obstacles::Draw(Board& brd) const
{
	for (int i = 0; i < nObstacles; i++) {
		obstacles[i].Draw(brd);
	}
}

void Obstacles::SpawnNewObstacle(std::mt19937& rng, const Board& brd,const Snake& snek,const Goal& goal)
{
	std::uniform_int_distribution<int> xDist(0, brd.GetGridWidth() - 10);
	std::uniform_int_distribution<int> yDist(0, brd.GetGridHeight() - 10);

	Location obsLoc;

	do {
		obsLoc.x = xDist(rng);
		obsLoc.y = yDist(rng);
	} while (snek.IsInTile(obsLoc) && goal.IsInTile(obsLoc) && IsInTile(obsLoc));

	
	obstacles[nObstacles].Init(obsLoc);
	nObstacles += 1;
}




const Location Obstacles::ObstacleSingle::GetLocation() const
{
	return loc;
}

void Obstacles::ObstacleSingle::Draw(Board& brd) const
{
	brd.DrawCell(loc, c, padding);
}

void Obstacles::ObstacleSingle::Init(const Location& in_loc)
{
	loc = in_loc;
	c = Obstacles::obstacle_color;
}

bool Obstacles::IsInTile(const Location& target) const
{
	for (int i = 0; i < nObstacles; i++) {
		if (obstacles[i].GetLocation() == target) {
			return true;
		}
	}
	return false;
}
