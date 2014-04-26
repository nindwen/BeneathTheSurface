#ifndef _LISTM
#define _LISTM


class nodeMap {
	public:
		nodeMap();
		virtual ~nodeMap();

		nodeMap* next;
		nodeMap* prev;
		nodeMap* parent;
		int F, G, H;
		int x,y;
};

class listMap {
	public:
		listMap();

		int add(int x, int y, int parentX, int parentY);
		int rm(int x, int y);
		int adv();
		void dCurrent() { delete current; }
		void setValues(int x, int y, int dx, int dy);
		nodeMap* getNode(int x, int y);
		nodeMap* lowestF();

		nodeMap *first;
		nodeMap *last;
		nodeMap *current;
};


#endif
