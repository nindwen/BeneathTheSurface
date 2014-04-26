#ifndef _ACTOR
#define _ACTOR
#include "object.h"
#include "Library.h"

class Actor : public gameObject
{
	public:
		void move(int x, int y);
		virtual int update();


	protected:
		listMap open;
		listMap closed;
		int destinationX;
		int destinationY;
};


#endif
