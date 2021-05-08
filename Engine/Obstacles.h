#pragma once
#include "Location.h"
#include "Board.h"
#include "Colors.h"
#include <random>
#include "Snake.h"
#include "Goal.h"

class Obstacles {

private:
	class ObstacleSingle{
	private:
		Location loc;
		Color c;
		static constexpr int padding = 2;
	public:
		
		const Location GetLocation() const;
		void Draw(Board& brd) const;
		void Init(const Location& in_loc);
	};


	static constexpr Color obstacle_color = { 0, 0, 255 };

	static constexpr int nObstaclesMax = 50;
	int nObstacles = 1;
	ObstacleSingle obstacles[nObstaclesMax];
	
public:
	Obstacles(std::mt19937& rng, const Board& brd,const Snake& snek,const Goal& goal,const Location& loc);
	void Draw(Board& brd) const;
	void SpawnNewObstacle(std::mt19937& rng, const Board& brd,const Snake& snek,const Goal& goal);
	
	bool IsInTile(const Location& target)const;

};