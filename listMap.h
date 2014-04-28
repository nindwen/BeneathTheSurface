#ifndef _LISTM
#define _LISTM


class nodeMap {
	public:
		nodeMap();

		nodeMap* next;
		nodeMap* prev;
		nodeMap* parent;
		int F, G, H;
		int x,y;
};

class listMap {
	public:
		listMap();
		~listMap();

		int add(nodeMap* nod);
		int rm(int x, int y);
		//void dCurrent() { }//delete current; }
		void setValues(int x, int y, int dx, int dy);
		nodeMap* getNode(int x, int y);
		nodeMap* lowestF();

		nodeMap *first;
		nodeMap *last;

		void print();
};

#endif
