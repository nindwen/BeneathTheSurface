#include "Library.h"

//listObject - list of nodeObjects that point to gameObjects

nodeObject::nodeObject()
{
	next=nullptr;
	prev=nullptr;
}

nodeObject::~nodeObject()
{
	next=nullptr;
	prev=nullptr;
	delete data;
}

listObject::listObject()
{
	first=nullptr;
	last=nullptr;
	current=nullptr;
}

int listObject::add(gameObject* data)
{
	nodeObject *node = new nodeObject();
	node->data=data;
	if(first==nullptr)
	{
		first=node;
		last=node;
		current=node;
		node->sNext(nullptr);
		node->sPrev(nullptr);
	}
	else
	{
		first->sPrev(node);
		node->sNext(first);
		node->sPrev(nullptr);
		first=node;
	}
	return 1;
}

int listObject::rm()
{
	if(current==first && current==last)
	{
		first = last = current = nullptr;
		dCurrent();
	}
	else if(current==last)
	{
		last=current->gPrev();
		last->sNext(nullptr);
		dCurrent();
		current=last;
	}
	else if(current==first)
	{
		first=current->gNext();
		first->sPrev(nullptr);
		dCurrent();
		current=first;
	}
	else
	{
		current->sPrev(current->gNext());
		nodeObject* temp=current->gNext();
		dCurrent();
		current=temp;
	}
	return 1;
}

int listObject::adv()
{
	if(current->gNext() != nullptr)
	{
		current=current->gNext();
		return 1;
	}
	else
	{
		current=first;
		return 0;
	}
}

