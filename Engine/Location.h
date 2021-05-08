#pragma once

// difference between struct and class is that struct has its data members public by default and class has its data members as private by default
class Location {
public:
	void Add(const Location& val) {
		x += val.x;
		y += val.y;
	}
	int x;
	int y; 
	/*Location operator+(const Location& rhs) const {
		return { x + rhs.x, y + rhs.y };
	}*/
	bool operator==(const Location& rhs) const {
		return x == rhs.x && y == rhs.y;
	}
};