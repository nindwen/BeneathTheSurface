#ifndef _LEVEL
#define _LEVEL
#include "Library.h"

class Tile : public gameObject {
	public:
		Tile();
		bool Solid;
};

class Level {
	public:
		Level(int n);
		Tile **level;
		int n;

		listMap* findPath(int x, int y, int dX, int dY);
};

#endif
