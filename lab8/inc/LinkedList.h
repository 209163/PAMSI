/*
 * LinkedList.h
 *
 *  Created on: 8 maj 2016
 *      Author: paula
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>
//#include "node.h"
using namespace std;

template <class type>
class LinkedList {
protected:

	template <class type2>
	struct node{
	public:
	  type data;
	  node *next;
	  node *prev;
	  node(){next=NULL; prev=NULL;}
	};
	bool isEmpty();
	/**
	 * wskaznik na pierwszy element
	 */
	node<type> *first;
	/**
	 * wskaznik na ostatni element
	 */
	node<type> *last;
public:
	LinkedList();
	virtual ~LinkedList();
	/**
	 * dodaje element na koncu
	 * @param a - element do dodania
	 */
	void addLast(type newData);
	int size();
	void printLinkedList(node<type> *first);
	node<type> *getFirst(){return first;};
	bool isfound(type data);
};



//************************************************************************************************//
template <class type>
LinkedList<type>::LinkedList() {
	first = NULL;
	last = NULL;

}
template <class type>
LinkedList<type>::~LinkedList() {
	node<type> *temp = first;
	while(temp != NULL)
	{
		temp = temp->next;
		delete(first);
		first=temp;
	}
}

template <class type>
bool LinkedList<type>::isfound(type dataToFind)
{
	node<type> *temp = first;
	while(temp != NULL)
	{
		if(temp->data==dataToFind) return 1;
		temp=temp->next;
	}
	return 0;
}

template <class type>
void LinkedList<type>::addLast(type newData)
{
	//tworze nowy wezel
	node<type>* newNode = new node<type>;
	newNode->data=newData;

	//node<type>* temp = first;

	if (first==NULL)
	{
		newNode->next=NULL;
		newNode->prev=NULL;
		first=newNode;
		last=newNode;
	}
	else
	{
		newNode->next=NULL;
		last->next=newNode;
		newNode->prev=last;
		last=newNode;
	}
}

template <class type>
void LinkedList<type>::printLinkedList(node<type> *first)
{
	node<type>* temp = first;

	while(temp != NULL)
	{
		cout<<temp->data<<" ";
		temp=temp->next;
	}
	cout<<endl;
}

template <class type>
int LinkedList<type>::size()
{
	if (first == NULL && last == NULL) return 0;
	node<type>* temp = first;
	int counter=0;

	while(temp != NULL)
	{
		counter++;
		temp=temp->next;
	}
	return counter;
}



#endif /* LINKEDLIST_H_ */
