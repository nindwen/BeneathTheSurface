#include "Library.h"
extern Library* library;

nodeMap::nodeMap()
{
	next=nullptr;
	prev=nullptr;
}

listMap::listMap()
{
	first=nullptr;
	last=nullptr;
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

int listMap::add(nodeMap* node)
{

	if(first==nullptr)
	{
		first=node;
		last=node;
		node->next=nullptr;
		node->prev=nullptr;
	}
	else
	{
		first->prev=node;
		node->next=first;
		first=node;
		node->prev=nullptr;
	}
	return 1;
}

int listMap::rm(int x, int y)
{
	nodeMap* current=getNode(x,y);
	if(current==nullptr)
	{
		return 0;
	}

	if(current==first && current==last)
	{
		first = last = nullptr;
	}
	else if(current==last)
	{
		last=current->prev;
		last->next=nullptr;
	}
	else if(current==first)
	{
		first=current->next;
		first->prev=nullptr;
	}
	else
	{
		current->prev->next=current->next;
		current->next->prev=current->prev;
	}
	return 1;
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
		if(temp->F < low->F) { low=temp; }
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
	if(node==nullptr) { std::cout << "prkl\n";return; }
	if(node->parent != nullptr)
	{
		node->G=node->parent->G+1;
	}
	else { node->G=0;std::cout << "hi\n"; }
	node->H=abs(node->y - dy)+abs(node->x - dx);
	node->F=node->G + node->H;
}

void listMap::print()
{
	if(first==nullptr)
	{
	}
	nodeMap* temp = first;
	while(1)
	{
		if(temp->parent==nullptr) 
		{
			break; 
		}

		std::cout << "(" << temp->x << ":" << temp->y << ") G: " << temp->G << ", F: " << temp->F << " Parent: (" << temp->parent->x << ":" << temp->parent->y << ")" << std::endl;
		if(temp->next!=nullptr)
		{
			temp=temp->next;
		}
		else
		{
			return;
		}
	}
}

