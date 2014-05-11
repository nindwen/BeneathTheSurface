#ifndef _LEVEL
#define _LEVEL
#include "Library.h"

class Tile : public gameObject {
	public:
		Tile();
		virtual int update();
		bool Solid;
};

class Level {
	public:
		Level(int n);
		Tile **level;
		int n;
	
	private:
		int roomCount;
		int rMinSize;
		int rMaxSize;

		listMap* findPath(int x, int y, int dX, int dY);
		//findPath returns listMap as path, or nullptr is path not found

};

class Room {
	public:
		Room();
		Room(int xValue, int yValue, int width, int height);
		bool roomsCollide(Room room);

		int x;
		int y;
		int w;
		int h;
};

#endif
