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

		listMap* findPath(int x, int y, int dX, int dY);
		//findPath returns listMap as path, or nullptr is path not found
};

#endif
