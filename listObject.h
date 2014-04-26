#ifndef _LISTO
#define _LISTO


class nodeObject {
	public:
		nodeObject();
		virtual ~nodeObject();
		nodeObject* gNext() { return next; }
		nodeObject* gPrev() { return prev; }
		void sNext(nodeObject* next) { this->next=next; }
		void sPrev(nodeObject* prev) { this->prev=prev; }
		gameObject* data;

	private:
		nodeObject* next;
		nodeObject* prev;
};

class listObject {
	public:
		listObject();
		nodeObject* gFirst() { return first; }
		nodeObject* gLast() { return last; }
		nodeObject* gCurrent() { return current; }
		void sFirst(nodeObject *first) { this->first=first; }
		void sLast(nodeObject *last) { this->last=last; }
		void sCurrent(nodeObject *current) { this->current=current; }
		void dCurrent() { delete current; }


		int add(gameObject* data);
		int rm();
		int adv();

	private:
		nodeObject *first;
		nodeObject *last;
		nodeObject *current;
};


#endif
