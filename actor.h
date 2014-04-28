#ifndef _ACTOR
#define _ACTOR
#include "object.h"
#include "Library.h"

class Actor : public gameObject
{
	public:
		Actor(int x, int y);
		void move(int x, int y);
		virtual int update();
		int setDestination(int x, int y);


	protected:
		//listMap open;
		//listMap closed;
		bool selected;
		int destinationX;
		int destinationY;
};


#endif
