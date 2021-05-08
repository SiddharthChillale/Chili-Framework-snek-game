#include "Board.h"
#include <assert.h>

Board::Board(Graphics& gfx)
	:
	gfx(gfx)
{
	
	
}

void Board::DrawCell( const Location& loc, Color c, int padding)
{
	assert(loc.x >= 0);
	assert(loc.x <= width);
	assert(loc.y >= 0);
	assert(loc.y <= height);
	 
	
	int start_x = (loc.x * dimension) + offset + padding;
	int start_y = (loc.y * dimension) + offset + padding;
	int pad_dimension = dimension - padding;

	gfx.DrawRectDim(start_x, start_y , pad_dimension, pad_dimension, c);
}

int Board::GetGridWidth() const
{
	return width;
}

int Board::GetGridHeight() const
{
	return height;
}

bool Board::isInsideBoard(const Location& loc) const
{
	return loc.x >= 0 && loc.x <width &&
		   loc.y >= 0 && loc.y <height;
}

void Board::DrawBorder() {
	int y2 = (height * dimension ) + offset;
	int bottom_limit = y2 < gfx.ScreenHeight ? y2 : (gfx.ScreenHeight-offset);
	
	int x2 = (width * dimension ) + offset;
	int right_limit = x2 < gfx.ScreenWidth ? x2 : (gfx.ScreenWidth-offset);

	
	for (int x = offset; x < gfx.ScreenWidth - offset ; x++) {
		gfx.PutPixel(x, bottom_limit, { 255, 255, 255 });
		gfx.PutPixel(x, offset, { 255, 255, 255 });

	} 
	for (int y = offset; y < gfx.ScreenHeight - offset; y++) {
		gfx.PutPixel(right_limit, y, { 255, 255, 255 });
		gfx.PutPixel(offset, y, { 255, 255, 255 });

	}
}

void Board::DrawFood(const Location& loc)
{
	int x = (loc.x * dimension) + offset;
	int y = (loc.y * dimension) + offset;

	gfx.PutPixel(11 + x, 0 + y, 38, 92, 66);
	gfx.PutPixel(12 + x, 0 + y, 62, 137, 72);
	gfx.PutPixel(11 + x, 1 + y, 38, 92, 66);
	gfx.PutPixel(12 + x, 1 + y, 38, 92, 66);
	gfx.PutPixel(11 + x, 2 + y, 38, 92, 66);
	gfx.PutPixel(12 + x, 2 + y, 38, 92, 66);
	gfx.PutPixel(11 + x, 3 + y, 38, 92, 66);
	gfx.PutPixel(12 + x, 3 + y, 38, 92, 66);
	gfx.PutPixel(11 + x, 4 + y, 38, 92, 66);
	gfx.PutPixel(12 + x, 4 + y, 38, 92, 66);
	gfx.PutPixel(5 + x, 5 + y, 247, 118, 34);
	gfx.PutPixel(6 + x, 5 + y, 247, 118, 34);
	gfx.PutPixel(7 + x, 5 + y, 247, 118, 34);
	gfx.PutPixel(8 + x, 5 + y, 254, 174, 52);
	gfx.PutPixel(9 + x, 5 + y, 254, 174, 52);
	gfx.PutPixel(10 + x, 5 + y, 38, 92, 66);
	gfx.PutPixel(11 + x, 5 + y, 38, 92, 66);
	gfx.PutPixel(12 + x, 5 + y, 38, 92, 66);
	gfx.PutPixel(13 + x, 5 + y, 38, 92, 66);
	gfx.PutPixel(14 + x, 5 + y, 254, 174, 52);
	gfx.PutPixel(15 + x, 5 + y, 254, 174, 52);
	gfx.PutPixel(16 + x, 5 + y, 254, 174, 52);
	gfx.PutPixel(17 + x, 5 + y, 254, 174, 52);
	gfx.PutPixel(18 + x, 5 + y, 254, 174, 52);
	gfx.PutPixel(3 + x, 6 + y, 247, 118, 34);
	gfx.PutPixel(4 + x, 6 + y, 247, 118, 34);
	gfx.PutPixel(5 + x, 6 + y, 247, 118, 34);
	gfx.PutPixel(6 + x, 6 + y, 190, 74, 47);
	gfx.PutPixel(7 + x, 6 + y, 190, 74, 47);
	gfx.PutPixel(8 + x, 6 + y, 247, 118, 34);
	gfx.PutPixel(9 + x, 6 + y, 38, 92, 66);
	gfx.PutPixel(10 + x, 6 + y, 38, 92, 66);
	gfx.PutPixel(11 + x, 6 + y, 38, 92, 66);
	gfx.PutPixel(12 + x, 6 + y, 38, 92, 66);
	gfx.PutPixel(13 + x, 6 + y, 38, 92, 66);
	gfx.PutPixel(14 + x, 6 + y, 38, 92, 66);
	gfx.PutPixel(15 + x, 6 + y, 190, 74, 47);
	gfx.PutPixel(16 + x, 6 + y, 190, 74, 47);
	gfx.PutPixel(17 + x, 6 + y, 247, 118, 34);
	gfx.PutPixel(18 + x, 6 + y, 247, 118, 34);
	gfx.PutPixel(19 + x, 6 + y, 254, 174, 52);
	gfx.PutPixel(20 + x, 6 + y, 254, 174, 52);
	gfx.PutPixel(2 + x, 7 + y, 247, 118, 34);
	gfx.PutPixel(3 + x, 7 + y, 247, 118, 34);
	gfx.PutPixel(4 + x, 7 + y, 190, 74, 47);
	gfx.PutPixel(5 + x, 7 + y, 190, 74, 47);
	gfx.PutPixel(6 + x, 7 + y, 247, 118, 34);
	gfx.PutPixel(7 + x, 7 + y, 247, 118, 34);
	gfx.PutPixel(8 + x, 7 + y, 247, 118, 34);
	gfx.PutPixel(9 + x, 7 + y, 190, 74, 47);
	gfx.PutPixel(10 + x, 7 + y, 247, 118, 34);
	gfx.PutPixel(11 + x, 7 + y, 247, 118, 34);
	gfx.PutPixel(12 + x, 7 + y, 254, 174, 52);
	gfx.PutPixel(13 + x, 7 + y, 190, 74, 47);
	gfx.PutPixel(14 + x, 7 + y, 254, 174, 52);
	gfx.PutPixel(15 + x, 7 + y, 254, 174, 52);
	gfx.PutPixel(16 + x, 7 + y, 254, 174, 52);
	gfx.PutPixel(17 + x, 7 + y, 190, 74, 47);
	gfx.PutPixel(18 + x, 7 + y, 190, 74, 47);
	gfx.PutPixel(19 + x, 7 + y, 247, 118, 34);
	gfx.PutPixel(20 + x, 7 + y, 247, 118, 34);
	gfx.PutPixel(21 + x, 7 + y, 254, 174, 52);
	gfx.PutPixel(2 + x, 8 + y, 247, 118, 34);
	gfx.PutPixel(3 + x, 8 + y, 190, 74, 47);
	gfx.PutPixel(4 + x, 8 + y, 247, 118, 34);
	gfx.PutPixel(5 + x, 8 + y, 247, 118, 34);
	gfx.PutPixel(6 + x, 8 + y, 247, 118, 34);
	gfx.PutPixel(7 + x, 8 + y, 247, 118, 34);
	gfx.PutPixel(8 + x, 8 + y, 190, 74, 47);
	gfx.PutPixel(9 + x, 8 + y, 247, 118, 34);
	gfx.PutPixel(10 + x, 8 + y, 247, 118, 34);
	gfx.PutPixel(11 + x, 8 + y, 247, 118, 34);
	gfx.PutPixel(12 + x, 8 + y, 247, 118, 34);
	gfx.PutPixel(13 + x, 8 + y, 254, 174, 52);
	gfx.PutPixel(14 + x, 8 + y, 190, 74, 47);
	gfx.PutPixel(15 + x, 8 + y, 247, 118, 34);
	gfx.PutPixel(16 + x, 8 + y, 247, 118, 34);
	gfx.PutPixel(17 + x, 8 + y, 254, 174, 52);
	gfx.PutPixel(18 + x, 8 + y, 254, 174, 52);
	gfx.PutPixel(19 + x, 8 + y, 190, 74, 47);
	gfx.PutPixel(20 + x, 8 + y, 247, 118, 34);
	gfx.PutPixel(21 + x, 8 + y, 247, 118, 34);
	gfx.PutPixel(2 + x, 9 + y, 247, 118, 34);
	gfx.PutPixel(3 + x, 9 + y, 190, 74, 47);
	gfx.PutPixel(4 + x, 9 + y, 247, 118, 34);
	gfx.PutPixel(5 + x, 9 + y, 247, 118, 34);
	gfx.PutPixel(6 + x, 9 + y, 247, 118, 34);
	gfx.PutPixel(7 + x, 9 + y, 247, 118, 34);
	gfx.PutPixel(8 + x, 9 + y, 190, 74, 47);
	gfx.PutPixel(9 + x, 9 + y, 247, 118, 34);
	gfx.PutPixel(10 + x, 9 + y, 247, 118, 34);
	gfx.PutPixel(11 + x, 9 + y, 247, 118, 34);
	gfx.PutPixel(12 + x, 9 + y, 247, 118, 34);
	gfx.PutPixel(13 + x, 9 + y, 247, 118, 34);
	gfx.PutPixel(14 + x, 9 + y, 190, 74, 47);
	gfx.PutPixel(15 + x, 9 + y, 247, 118, 34);
	gfx.PutPixel(16 + x, 9 + y, 247, 118, 34);
	gfx.PutPixel(17 + x, 9 + y, 247, 118, 34);
	gfx.PutPixel(18 + x, 9 + y, 254, 174, 52);
	gfx.PutPixel(19 + x, 9 + y, 190, 74, 47);
	gfx.PutPixel(20 + x, 9 + y, 247, 118, 34);
	gfx.PutPixel(21 + x, 9 + y, 247, 118, 34);
	gfx.PutPixel(1 + x, 10 + y, 247, 118, 34);
	gfx.PutPixel(2 + x, 10 + y, 190, 74, 47);
	gfx.PutPixel(3 + x, 10 + y, 247, 118, 34);
	gfx.PutPixel(4 + x, 10 + y, 247, 118, 34);
	gfx.PutPixel(5 + x, 10 + y, 247, 118, 34);
	gfx.PutPixel(6 + x, 10 + y, 247, 118, 34);
	gfx.PutPixel(7 + x, 10 + y, 190, 74, 47);
	gfx.PutPixel(8 + x, 10 + y, 247, 118, 34);
	gfx.PutPixel(9 + x, 10 + y, 247, 118, 34);
	gfx.PutPixel(10 + x, 10 + y, 247, 118, 34);
	gfx.PutPixel(11 + x, 10 + y, 247, 118, 34);
	gfx.PutPixel(12 + x, 10 + y, 247, 118, 34);
	gfx.PutPixel(13 + x, 10 + y, 247, 118, 34);
	gfx.PutPixel(14 + x, 10 + y, 254, 174, 52);
	gfx.PutPixel(15 + x, 10 + y, 190, 74, 47);
	gfx.PutPixel(16 + x, 10 + y, 247, 118, 34);
	gfx.PutPixel(17 + x, 10 + y, 247, 118, 34);
	gfx.PutPixel(18 + x, 10 + y, 247, 118, 34);
	gfx.PutPixel(19 + x, 10 + y, 254, 174, 52);
	gfx.PutPixel(20 + x, 10 + y, 190, 74, 47);
	gfx.PutPixel(21 + x, 10 + y, 247, 118, 34);
	gfx.PutPixel(22 + x, 10 + y, 254, 174, 52);
	gfx.PutPixel(1 + x, 11 + y, 247, 118, 34);
	gfx.PutPixel(2 + x, 11 + y, 190, 74, 47);
	gfx.PutPixel(3 + x, 11 + y, 247, 118, 34);
	gfx.PutPixel(4 + x, 11 + y, 247, 118, 34);
	gfx.PutPixel(5 + x, 11 + y, 247, 118, 34);
	gfx.PutPixel(6 + x, 11 + y, 247, 118, 34);
	gfx.PutPixel(7 + x, 11 + y, 190, 74, 47);
	gfx.PutPixel(8 + x, 11 + y, 247, 118, 34);
	gfx.PutPixel(9 + x, 11 + y, 247, 118, 34);
	gfx.PutPixel(10 + x, 11 + y, 247, 118, 34);
	gfx.PutPixel(11 + x, 11 + y, 247, 118, 34);
	gfx.PutPixel(12 + x, 11 + y, 247, 118, 34);
	gfx.PutPixel(13 + x, 11 + y, 247, 118, 34);
	gfx.PutPixel(14 + x, 11 + y, 254, 174, 52);
	gfx.PutPixel(15 + x, 11 + y, 190, 74, 47);
	gfx.PutPixel(16 + x, 11 + y, 247, 118, 34);
	gfx.PutPixel(17 + x, 11 + y, 247, 118, 34);
	gfx.PutPixel(18 + x, 11 + y, 247, 118, 34);
	gfx.PutPixel(19 + x, 11 + y, 254, 174, 52);
	gfx.PutPixel(20 + x, 11 + y, 190, 74, 47);
	gfx.PutPixel(21 + x, 11 + y, 247, 118, 34);
	gfx.PutPixel(22 + x, 11 + y, 247, 118, 34);
	gfx.PutPixel(1 + x, 12 + y, 247, 118, 34);
	gfx.PutPixel(2 + x, 12 + y, 190, 74, 47);
	gfx.PutPixel(3 + x, 12 + y, 247, 118, 34);
	gfx.PutPixel(4 + x, 12 + y, 247, 118, 34);
	gfx.PutPixel(5 + x, 12 + y, 247, 118, 34);
	gfx.PutPixel(6 + x, 12 + y, 247, 118, 34);
	gfx.PutPixel(7 + x, 12 + y, 190, 74, 47);
	gfx.PutPixel(8 + x, 12 + y, 247, 118, 34);
	gfx.PutPixel(9 + x, 12 + y, 247, 118, 34);
	gfx.PutPixel(10 + x, 12 + y, 247, 118, 34);
	gfx.PutPixel(11 + x, 12 + y, 247, 118, 34);
	gfx.PutPixel(12 + x, 12 + y, 247, 118, 34);
	gfx.PutPixel(13 + x, 12 + y, 247, 118, 34);
	gfx.PutPixel(14 + x, 12 + y, 254, 174, 52);
	gfx.PutPixel(15 + x, 12 + y, 190, 74, 47);
	gfx.PutPixel(16 + x, 12 + y, 247, 118, 34);
	gfx.PutPixel(17 + x, 12 + y, 247, 118, 34);
	gfx.PutPixel(18 + x, 12 + y, 247, 118, 34);
	gfx.PutPixel(19 + x, 12 + y, 254, 174, 52);
	gfx.PutPixel(20 + x, 12 + y, 190, 74, 47);
	gfx.PutPixel(21 + x, 12 + y, 247, 118, 34);
	gfx.PutPixel(22 + x, 12 + y, 247, 118, 34);
	gfx.PutPixel(1 + x, 13 + y, 181, 80, 136);
	gfx.PutPixel(2 + x, 13 + y, 190, 74, 47);
	gfx.PutPixel(3 + x, 13 + y, 247, 118, 34);
	gfx.PutPixel(4 + x, 13 + y, 247, 118, 34);
	gfx.PutPixel(5 + x, 13 + y, 247, 118, 34);
	gfx.PutPixel(6 + x, 13 + y, 247, 118, 34);
	gfx.PutPixel(7 + x, 13 + y, 190, 74, 47);
	gfx.PutPixel(8 + x, 13 + y, 247, 118, 34);
	gfx.PutPixel(9 + x, 13 + y, 247, 118, 34);
	gfx.PutPixel(10 + x, 13 + y, 247, 118, 34);
	gfx.PutPixel(11 + x, 13 + y, 247, 118, 34);
	gfx.PutPixel(12 + x, 13 + y, 247, 118, 34);
	gfx.PutPixel(13 + x, 13 + y, 247, 118, 34);
	gfx.PutPixel(14 + x, 13 + y, 247, 118, 34);
	gfx.PutPixel(15 + x, 13 + y, 190, 74, 47);
	gfx.PutPixel(16 + x, 13 + y, 247, 118, 34);
	gfx.PutPixel(17 + x, 13 + y, 247, 118, 34);
	gfx.PutPixel(18 + x, 13 + y, 247, 118, 34);
	gfx.PutPixel(19 + x, 13 + y, 254, 174, 52);
	gfx.PutPixel(20 + x, 13 + y, 190, 74, 47);
	gfx.PutPixel(21 + x, 13 + y, 247, 118, 34);
	gfx.PutPixel(22 + x, 13 + y, 247, 118, 34);
	gfx.PutPixel(1 + x, 14 + y, 181, 80, 136);
	gfx.PutPixel(2 + x, 14 + y, 190, 74, 47);
	gfx.PutPixel(3 + x, 14 + y, 247, 118, 34);
	gfx.PutPixel(4 + x, 14 + y, 247, 118, 34);
	gfx.PutPixel(5 + x, 14 + y, 247, 118, 34);
	gfx.PutPixel(6 + x, 14 + y, 247, 118, 34);
	gfx.PutPixel(7 + x, 14 + y, 190, 74, 47);
	gfx.PutPixel(8 + x, 14 + y, 247, 118, 34);
	gfx.PutPixel(9 + x, 14 + y, 247, 118, 34);
	gfx.PutPixel(10 + x, 14 + y, 247, 118, 34);
	gfx.PutPixel(11 + x, 14 + y, 247, 118, 34);
	gfx.PutPixel(12 + x, 14 + y, 247, 118, 34);
	gfx.PutPixel(13 + x, 14 + y, 247, 118, 34);
	gfx.PutPixel(14 + x, 14 + y, 247, 118, 34);
	gfx.PutPixel(15 + x, 14 + y, 190, 74, 47);
	gfx.PutPixel(16 + x, 14 + y, 247, 118, 34);
	gfx.PutPixel(17 + x, 14 + y, 247, 118, 34);
	gfx.PutPixel(18 + x, 14 + y, 247, 118, 34);
	gfx.PutPixel(19 + x, 14 + y, 254, 174, 52);
	gfx.PutPixel(20 + x, 14 + y, 190, 74, 47);
	gfx.PutPixel(21 + x, 14 + y, 247, 118, 34);
	gfx.PutPixel(22 + x, 14 + y, 247, 118, 34);
	gfx.PutPixel(1 + x, 15 + y, 181, 80, 136);
	gfx.PutPixel(2 + x, 15 + y, 190, 74, 47);
	gfx.PutPixel(3 + x, 15 + y, 247, 118, 34);
	gfx.PutPixel(4 + x, 15 + y, 247, 118, 34);
	gfx.PutPixel(5 + x, 15 + y, 247, 118, 34);
	gfx.PutPixel(6 + x, 15 + y, 247, 118, 34);
	gfx.PutPixel(7 + x, 15 + y, 190, 74, 47);
	gfx.PutPixel(8 + x, 15 + y, 247, 118, 34);
	gfx.PutPixel(9 + x, 15 + y, 247, 118, 34);
	gfx.PutPixel(10 + x, 15 + y, 247, 118, 34);
	gfx.PutPixel(11 + x, 15 + y, 247, 118, 34);
	gfx.PutPixel(12 + x, 15 + y, 247, 118, 34);
	gfx.PutPixel(13 + x, 15 + y, 247, 118, 34);
	gfx.PutPixel(14 + x, 15 + y, 247, 118, 34);
	gfx.PutPixel(15 + x, 15 + y, 190, 74, 47);
	gfx.PutPixel(16 + x, 15 + y, 247, 118, 34);
	gfx.PutPixel(17 + x, 15 + y, 247, 118, 34);
	gfx.PutPixel(18 + x, 15 + y, 247, 118, 34);
	gfx.PutPixel(19 + x, 15 + y, 254, 174, 52);
	gfx.PutPixel(20 + x, 15 + y, 190, 74, 47);
	gfx.PutPixel(21 + x, 15 + y, 247, 118, 34);
	gfx.PutPixel(22 + x, 15 + y, 247, 118, 34);
	gfx.PutPixel(1 + x, 16 + y, 181, 80, 136);
	gfx.PutPixel(2 + x, 16 + y, 190, 74, 47);
	gfx.PutPixel(3 + x, 16 + y, 247, 118, 34);
	gfx.PutPixel(4 + x, 16 + y, 247, 118, 34);
	gfx.PutPixel(5 + x, 16 + y, 247, 118, 34);
	gfx.PutPixel(6 + x, 16 + y, 247, 118, 34);
	gfx.PutPixel(7 + x, 16 + y, 190, 74, 47);
	gfx.PutPixel(8 + x, 16 + y, 247, 118, 34);
	gfx.PutPixel(9 + x, 16 + y, 247, 118, 34);
	gfx.PutPixel(10 + x, 16 + y, 247, 118, 34);
	gfx.PutPixel(11 + x, 16 + y, 247, 118, 34);
	gfx.PutPixel(12 + x, 16 + y, 247, 118, 34);
	gfx.PutPixel(13 + x, 16 + y, 247, 118, 34);
	gfx.PutPixel(14 + x, 16 + y, 247, 118, 34);
	gfx.PutPixel(15 + x, 16 + y, 190, 74, 47);
	gfx.PutPixel(16 + x, 16 + y, 247, 118, 34);
	gfx.PutPixel(17 + x, 16 + y, 247, 118, 34);
	gfx.PutPixel(18 + x, 16 + y, 247, 118, 34);
	gfx.PutPixel(19 + x, 16 + y, 247, 118, 34);
	gfx.PutPixel(20 + x, 16 + y, 190, 74, 47);
	gfx.PutPixel(21 + x, 16 + y, 247, 118, 34);
	gfx.PutPixel(22 + x, 16 + y, 247, 118, 34);
	gfx.PutPixel(2 + x, 17 + y, 181, 80, 136);
	gfx.PutPixel(3 + x, 17 + y, 190, 74, 47);
	gfx.PutPixel(4 + x, 17 + y, 247, 118, 34);
	gfx.PutPixel(5 + x, 17 + y, 247, 118, 34);
	gfx.PutPixel(6 + x, 17 + y, 181, 80, 136);
	gfx.PutPixel(7 + x, 17 + y, 190, 74, 47);
	gfx.PutPixel(8 + x, 17 + y, 247, 118, 34);
	gfx.PutPixel(9 + x, 17 + y, 247, 118, 34);
	gfx.PutPixel(10 + x, 17 + y, 247, 118, 34);
	gfx.PutPixel(11 + x, 17 + y, 247, 118, 34);
	gfx.PutPixel(12 + x, 17 + y, 247, 118, 34);
	gfx.PutPixel(13 + x, 17 + y, 247, 118, 34);
	gfx.PutPixel(14 + x, 17 + y, 247, 118, 34);
	gfx.PutPixel(15 + x, 17 + y, 190, 74, 47);
	gfx.PutPixel(16 + x, 17 + y, 247, 118, 34);
	gfx.PutPixel(17 + x, 17 + y, 247, 118, 34);
	gfx.PutPixel(18 + x, 17 + y, 247, 118, 34);
	gfx.PutPixel(19 + x, 17 + y, 247, 118, 34);
	gfx.PutPixel(20 + x, 17 + y, 190, 74, 47);
	gfx.PutPixel(21 + x, 17 + y, 247, 118, 34);
	gfx.PutPixel(2 + x, 18 + y, 181, 80, 136);
	gfx.PutPixel(3 + x, 18 + y, 190, 74, 47);
	gfx.PutPixel(4 + x, 18 + y, 181, 80, 136);
	gfx.PutPixel(5 + x, 18 + y, 181, 80, 136);
	gfx.PutPixel(6 + x, 18 + y, 181, 80, 136);
	gfx.PutPixel(7 + x, 18 + y, 181, 80, 136);
	gfx.PutPixel(8 + x, 18 + y, 190, 74, 47);
	gfx.PutPixel(9 + x, 18 + y, 247, 118, 34);
	gfx.PutPixel(10 + x, 18 + y, 247, 118, 34);
	gfx.PutPixel(11 + x, 18 + y, 247, 118, 34);
	gfx.PutPixel(12 + x, 18 + y, 247, 118, 34);
	gfx.PutPixel(13 + x, 18 + y, 247, 118, 34);
	gfx.PutPixel(14 + x, 18 + y, 190, 74, 47);
	gfx.PutPixel(15 + x, 18 + y, 181, 80, 136);
	gfx.PutPixel(16 + x, 18 + y, 247, 118, 34);
	gfx.PutPixel(17 + x, 18 + y, 247, 118, 34);
	gfx.PutPixel(18 + x, 18 + y, 247, 118, 34);
	gfx.PutPixel(19 + x, 18 + y, 190, 74, 47);
	gfx.PutPixel(20 + x, 18 + y, 181, 80, 136);
	gfx.PutPixel(21 + x, 18 + y, 181, 80, 136);
	gfx.PutPixel(4 + x, 19 + y, 190, 74, 47);
	gfx.PutPixel(5 + x, 19 + y, 190, 74, 47);
	gfx.PutPixel(6 + x, 19 + y, 181, 80, 136);
	gfx.PutPixel(7 + x, 19 + y, 181, 80, 136);
	gfx.PutPixel(8 + x, 19 + y, 190, 74, 47);
	gfx.PutPixel(9 + x, 19 + y, 181, 80, 136);
	gfx.PutPixel(10 + x, 19 + y, 181, 80, 136);
	gfx.PutPixel(11 + x, 19 + y, 181, 80, 136);
	gfx.PutPixel(12 + x, 19 + y, 181, 80, 136);
	gfx.PutPixel(13 + x, 19 + y, 181, 80, 136);
	gfx.PutPixel(14 + x, 19 + y, 190, 74, 47);
	gfx.PutPixel(15 + x, 19 + y, 181, 80, 136);
	gfx.PutPixel(16 + x, 19 + y, 181, 80, 136);
	gfx.PutPixel(17 + x, 19 + y, 181, 80, 136);
	gfx.PutPixel(18 + x, 19 + y, 190, 74, 47);
	gfx.PutPixel(19 + x, 19 + y, 190, 74, 47);
	gfx.PutPixel(6 + x, 20 + y, 190, 74, 47);
	gfx.PutPixel(7 + x, 20 + y, 190, 74, 47);
	gfx.PutPixel(8 + x, 20 + y, 190, 74, 47);
	gfx.PutPixel(9 + x, 20 + y, 190, 74, 47);
	gfx.PutPixel(10 + x, 20 + y, 190, 74, 47);
	gfx.PutPixel(11 + x, 20 + y, 190, 74, 47);
	gfx.PutPixel(12 + x, 20 + y, 190, 74, 47);
	gfx.PutPixel(13 + x, 20 + y, 190, 74, 47);
	gfx.PutPixel(14 + x, 20 + y, 190, 74, 47);
	gfx.PutPixel(15 + x, 20 + y, 190, 74, 47);
	gfx.PutPixel(16 + x, 20 + y, 190, 74, 47);
	gfx.PutPixel(17 + x, 20 + y, 190, 74, 47);

}

