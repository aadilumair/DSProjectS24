#pragma once
#include <cmath>
struct Coordinate
{
	int x, y;

	Coordinate(int x = 0, int y = 0) {
		this->x = x;
		this->y = y;
	}

	Coordinate operator +(Coordinate other) {
		Coordinate retVal;
		retVal.x = other.x + this->x;
		retVal.y = other.y + this->y;

		return retVal;
	}

	Coordinate operator -(Coordinate other) {
		Coordinate retVal;
		retVal.x = other.x - this->x;
		retVal.y = other.y - this->y;

		return retVal;
	}

	float abs() { //absolute distance from (0,0)
		return sqrt(float(pow(x, 2) + pow(y, 2)));
	}

	bool operator >(Coordinate other) { //comparing abs distance from (0,0)
		return this->abs() > other.abs();
	}

	bool operator<(Coordinate other) {
		return !(this->abs() > other.abs());
	}

	static float distance(Coordinate a, Coordinate b) {
		return sqrt(pow(float(a.x - b.x), 2) + pow(float(a.y - b.y), 2));
	}
};