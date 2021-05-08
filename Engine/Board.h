#pragma once
#include "Graphics.h"
#include "Location.h"


class Board {
public:
	Board(Graphics& gfx);
	void DrawCell(const Location& loc, Color c, int padding);
	int GetGridWidth() const;
	int GetGridHeight() const;
	bool isInsideBoard(const Location& loc ) const;
	void DrawBorder();
	void DrawFood(const Location& loc);

private:
	static constexpr int dimension = 20;
	static constexpr int offset = 10;

	static constexpr int width = (Graphics::ScreenWidth - offset )/ dimension ;
	static constexpr int height = (Graphics::ScreenHeight - offset )/ dimension ;
	Graphics& gfx;
	

};