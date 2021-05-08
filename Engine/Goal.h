#pragma once

#include "Snake.h"
#include "Board.h"
#include "Colors.h"
#include <random>

class Goal {
public:
	Goal(std::mt19937& rng, const Board& brd, const Snake& snek);
	void Respawn( std::mt19937& rng, const Board& brd, const Snake& snek);
	void Draw(Board& brd) const;
	const Location& GetLocation() const;

	bool IsInTile(const Location& target) const;
	
private:
	// static constexpr Color c = Colors::Red;

	Location loc;
};