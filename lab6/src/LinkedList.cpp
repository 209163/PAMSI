/*
 * LinkedList.cpp
 *
 *  Created on: 17 kwi 2016
 *      Author: paula
 */

#include "LinkedList.h"



LinkedList::LinkedList()
{
	firstElement = lastElement = new LinkedListElement();
	sizeOfList = 0;
	iteratorElementId =0;
	iterator=NULL;
	isIteratorAfterPop = 1; //to znaczy ze jeszcze raz trzeba bedzie sprawdzic pozycje iteratora 1- znaczy ze trzeba sprawdzic
}

LinkedList :: LinkedListElement::LinkedListElement(const LinkedListElement &linkedListElement)
{
	this->number = linkedListElement.number;
	this->name = linkedListElement.name;
	this->nextElement = linkedListElement.nextElement;
	this->previousElement = linkedListElement.previousElement;
}

LinkedList::~LinkedList() {
}


void LinkedList :: push_back(LinkedListElement arg)
{
	LinkedListElement *newLinkedListElement = new LinkedListElement(arg);
	if(!sizeOfList++)
	{
		firstElement = lastElement = newLinkedListElement;
	}
	//newMyListElement -> nextElement = 0;
	newLinkedListElement -> previousElement = this -> lastElement;
	this -> lastElement -> nextElement = newLinkedListElement;
	this->lastElement = newLinkedListElement;
}
void LinkedList :: push_front(LinkedListElement arg)
{
	LinkedListElement *newLinkedListElement = new LinkedListElement(arg);
	if(!sizeOfList++)
	{
		firstElement = lastElement = newLinkedListElement;
	}
	//newMyListElement -> previousElement =  0;
	newLinkedListElement -> nextElement = this -> firstElement;
	this -> firstElement -> previousElement = newLinkedListElement;
	this->firstElement = newLinkedListElement;
	++iteratorElementId;
}

void LinkedList :: insertAfter(LinkedListElement arg, int iteratorID)
{
	if(iteratorID==0)
	{
		push_front(arg);
		return;
	}
	if(iteratorID==this->sizeOfList-1)
	{
		push_back(arg);
		return;
	}
	LinkedListElement *newLinkedListElement = new LinkedListElement(arg);
	LinkedListElement &tmpThis=(*this)[iteratorID], &tmpNext=(*this)[iteratorID+1];
	if(!sizeOfList++)
	{
		firstElement = lastElement = newLinkedListElement;
	}
	newLinkedListElement -> nextElement = tmpThis.nextElement;
	newLinkedListElement -> previousElement = &tmpThis;
	tmpThis.nextElement = newLinkedListElement;
	tmpNext.previousElement = newLinkedListElement;
	isIteratorAfterPop=1;
}


LinkedList::LinkedListElement  LinkedList::pop_back()
{
	if(!(sizeOfList--))
	{
		sizeOfList=0; return (*(new LinkedListElement()));
	}
	LinkedListElement tmpNumber = *(this -> lastElement);
	LinkedListElement *originLinkedListElement = this -> lastElement;
	this -> lastElement = this -> lastElement -> previousElement;
	delete originLinkedListElement;
	isIteratorAfterPop=1;
	return tmpNumber;
}
LinkedList::LinkedListElement  LinkedList :: pop_front()
{
	if(!(sizeOfList--))
	{
		sizeOfList=0; return (*(new LinkedListElement()));
	}
	LinkedListElement tmpNumber = *(this -> firstElement);
	LinkedListElement *originLinkedListElement = this -> firstElement;
	this -> firstElement = this -> firstElement -> nextElement;

	delete originLinkedListElement;
	isIteratorAfterPop=1;
	return tmpNumber;
}

LinkedList :: LinkedListElement :: LinkedListElement(int arg, std::string str)
{
	this -> number = arg;
	this -> name = str;
	this -> nextElement =0;
	this -> previousElement =0;
}
LinkedList :: LinkedListElement :: LinkedListElement()
{
	this -> number = 0;
	this -> name = "";
	this -> nextElement =0;
	this -> previousElement =0;
}

LinkedList::LinkedListElement &LinkedList:: show_front(){
	return *firstElement;
}
LinkedList::LinkedListElement &LinkedList:: show_back(){
	return *lastElement;
}

int LinkedList::size()
{
	return sizeOfList;
}

void LinkedList::LinkedListElement::set(int arg, string str){
	this -> number = arg;
	this -> name = str;
}


LinkedList::LinkedListElement &LinkedList::operator[](int numberOfElement)
{
	if(numberOfElement > (sizeOfList-1)) // jezeli wyszedl poza liste
		{
			std::cerr<<"\n! Error indeks o numerze: "<<numberOfElement<<" nie istnieje !";
			return *iterator;
		}
	if(isIteratorAfterPop)
		{
			iteratorElementId=0;  // czyli iterator byl zpopowany
			iterator = firstElement;
			isIteratorAfterPop=0;
		}
	if((numberOfElement <= iteratorElementId-numberOfElement) &&(iteratorElementId-numberOfElement>=0))
	{
		iterator = (this->firstElement);
		for (int i =0; i< numberOfElement ; i++)
			iterator = (iterator->nextElement);
	}
	else if(numberOfElement > iteratorElementId)
	{
		for (; iteratorElementId< numberOfElement ; iteratorElementId++)
					iterator = (iterator->nextElement);
	}
	else if( numberOfElement < iteratorElementId)
	{
		for (; iteratorElementId> numberOfElement ; iteratorElementId--)
					iterator = (iterator->previousElement);
	}
	return *iterator;
}

void  LinkedList :: printList()
{
	LinkedList::LinkedListElement *elem = (this->firstElement);
	std::cout<<"\nWyswietlam liste (size:"<<this->sizeOfList<<"): ";
	for(int i=0; i< this->sizeOfList; i++)
	{
		std::cout<<" "<<elem->number;
		elem = elem->nextElement;
	}
}
