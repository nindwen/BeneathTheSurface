#include "Library.h"
extern Library* library;

nodeMap::nodeMap()
{
	next=nullptr;
	prev=nullptr;
}

nodeMap::~nodeMap()
{
	next=nullptr;
	prev=nullptr;
}

listMap::listMap()
{
	first=nullptr;
	last=nullptr;
	current=nullptr;
}

nodeMap* listMap::getNode(int x, int y)
{
	if(first==nullptr) { return nullptr; }
	nodeMap* temp=first;
	while(1)
	{
		if(temp->x==x && temp->y==y)
		{
			return temp;
		}
		if(temp->next==nullptr)
		{
			return nullptr;
		}
		temp=temp->next;
	}
}

int listMap::add(int x, int y, int parentX, int parentY)
{
	nodeMap *node = new nodeMap();
	node->x=x;
	node->y=y;
	node->parent=getNode(parentX, parentY);
	if(node->parent==nullptr)
	{
		node->parent=node;
	}

	if(first==nullptr)
	{
		first=node;
		last=node;
		current=node;
		node->next=nullptr;
		node->prev=nullptr;
	}
	else
	{
		first->prev=node;
		
		nodeMap*temp = first;

		first=node;
		node->next=temp;
		node->prev=nullptr;
	}
	return 1;
}

int listMap::rm(int x, int y)
{
	current=getNode(x,y);
	if(current==first && current==last)
	{
		first = last = current = nullptr;
		dCurrent();
	}
	else if(current==last)
	{
		last=current->prev;
		last->next=nullptr;
		dCurrent();
		current=last;
	}
	else if(current==first)
	{
		first=current->next;
		first->prev=nullptr;
		dCurrent();
		current=first;
	}
	else
	{
		current->prev=current->next;
		nodeMap* temp=current->next;
		dCurrent();
		current=temp;
	}
	return 1;
}

int listMap::adv()
{
	if(current->next != nullptr)
	{
		current=current->next;
		return 1;
	}
	else
	{
		current=first;
		return 0;
	}
}

nodeMap* listMap::lowestF()
{
	if(first==nullptr)
	{
		return nullptr;
	}
	nodeMap* temp = first;
	nodeMap* low = first;

	while(1)
	{
		if(temp->F<low->F) { low=temp; }
		if(temp->next!=nullptr)
		{
			temp=temp->next;
		}
		else
		{
			return low;
		}
	}
}

void listMap::setValues(int x, int y, int dx, int dy)
{
	nodeMap* node = getNode(x,y);
	if(node->parent!=NULL)
	{
		node->G=node->parent->F+1;
	}
	node->H=abs(node->y - dy)+abs(node->x - dx);
	node->F=node->G + node->H;
}
