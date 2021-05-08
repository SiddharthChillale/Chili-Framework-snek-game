#pragma once

#include	 "Board.h"


class Snake {
private:
	class Segment {
	private:
		Location loc;
		Color c;
		static constexpr int padding = 2;
	public:
		void InitHead(const Location& in_loc);
		void InitBody(int nSegments);
		void MoveBy(const Location& delta_loc);
		void Follow( const Segment& next );
		void Draw( Board& brd ) const;
		const Location& GetLocation() const;

	};

private:
	static constexpr Color headColor = Colors::Yellow;
	static constexpr Color bodyColor0 = { 0, 180, 0 } ;
	static constexpr Color bodyColor1 = { 0, 255, 0 } ;
	static constexpr Color bodyColor2 = { 0, 80, 0 } ;

	static constexpr int nSegmentsMax = 100;
	
	Segment segments[nSegmentsMax];
	int nSegments = 1;

public:
	Snake(const Location& loc);
	Location GetNextHeadLocation(const Location& delta_loc) const;
	bool IsInTileExceptEnd(const Location& snektarget) const ;
	bool IsInTile(const Location& snektarget) const;
	void MoveBy(const Location& delta_loc);
	void Grow();
	void Draw(Board& brd) const;
};
