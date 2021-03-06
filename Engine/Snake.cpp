#include "Snake.h"
#include <assert.h>

Location Snake::GetNextHeadLocation(const Location& delta_loc) const
{
	Location l(segments[0].GetLocation());
	l.Add(delta_loc);
	return l;
	
}

bool Snake::IsInTileExceptEnd(const Location& snektarget) const
{
	for (int i = 0; i < nSegments-1; i++) {
		if (segments[i].GetLocation() == snektarget) {
			return true;
		}

	}
	return false;
}

bool Snake::IsInTile(const Location& snektarget) const
{
	for (int i = 0; i < nSegments ; i++) {
		if (segments[i].GetLocation() == snektarget) {
			return true;
		}
	}
	return false;
}
Snake::Snake(const Location& loc)
{
	segments[0].InitHead(loc);
}

void Snake::MoveBy(const Location& delta_loc)
{
	for (int i = nSegments - 1; i > 0; i--) {
		segments[i].Follow(segments[i - 1]);
	}
	segments[0].MoveBy(delta_loc);
}

void Snake::Grow()
{
	if (nSegments < nSegmentsMax) { 
		segments[nSegments].InitBody(nSegments);
		nSegments += 1;
	}
}

void Snake::Draw(Board& brd) const
{
	for (int i = 0; i < nSegments; i++) {
		segments[i].Draw(brd);
	}
}

void Snake::Segment::InitHead(const Location& in_loc)
{
	loc = in_loc;
	c = Snake::headColor;
}

void Snake::Segment::InitBody(int nSegments)
{

	if (nSegments % 3 == 2) {
		c = Snake::bodyColor0;
	}
	else if (nSegments % 3 == 1) {
		c = Snake::bodyColor1;
	}
	else {
		c = Snake::bodyColor2;
	}
}

void Snake::Segment::MoveBy(const Location& delta_loc)
{
	assert( abs(delta_loc.x) + abs(delta_loc.y ) == 1);

	loc.Add(delta_loc);
}

void Snake::Segment::Follow( const Segment& next)
{
	loc = next.loc;
}

void Snake::Segment::Draw( Board& brd ) const
{
	brd.DrawCell(loc, c, padding);
}

const Location& Snake::Segment::GetLocation() const
{
	return loc ;
}
