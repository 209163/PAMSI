/*
 * LinkedList.h
 *
 *  Created on: 8 maj 2016
 *      Author: paula
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_
#include <iostream>
#include "Stack.h"
using namespace std;

template <class type>
class LinkedList  {
protected:

	template <class type2>
	struct node{
	public:
	  //int index;
	  type data;
	  node *next;
	  node *prev;
	  node(){next=NULL; prev=NULL;}
	};
	bool isEmpty();
	node<type>* partition(node<type> *start, node<type> *end);
	void quicksortAlg(node<type> *start, node<type> *end);

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
	void quicksort(node<type> *start);
	void printLinkedList(node<type> *first);
	node<type> *getFirst(){return first;};
	bool isfound(type data);
	type getElem(int index);
	node<type> *lastNode(node<type> *root);
	void swap(int* a, int* b);
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
void LinkedList<type>::swap(int* a, int* b)
{
	int tmp=*a;
	*a=*b;
	*b=tmp;
}

template <class type>
type LinkedList<type>::getElem(int index)
{
	node<type> *temp = first;
	while(temp!=NULL)
	{
		for(int i=1; i<=index;i++)
		{
			if(i==index) return temp->data;
			else temp=temp->next;
		}
	}
	return 0;
}


/**
 * odnajduje  ostatni wezel w dwukierunkowej liscie
 * @param root
 * @return zwraca ostatni wezel
 */
template <class type>
LinkedList<type>::node<type> *LinkedList<type>::lastNode(node<type> *root)
{
	while (root && root->next)
	{
		root=root->next;
	}
	return root;
}

/**
 * odnajduje ostatni wezel oraz wywoluje quicksortAlg()
 * @param start
 */
template <class type>
void LinkedList<type>::quicksort(node<type> *start)
{
	node<type> *last = lastNode(start);
	quicksortAlg(start, last);
}



/**
 * glowne zalozenie dzialania algorytmu quicksort
 * @param start
 * @param end
 */
template <class type>
void LinkedList<type>::quicksortAlg(node<type> *start, node<type> *end)
{
	//if(start=>end) return;
	if( end!=NULL && start != end && start != end->next)
	{
		//zwraca wskaznik do pivota po sortowaniu
		node<type> *pivotPointer = partition(start, end);
		quicksortAlg(start, pivotPointer->prev);
		quicksortAlg(pivotPointer->next, end);
	}

}
/**
 * przerzuca na lewo wartosci mniejsze od pivota, a na prawo wieksze
 * @param start pierwszy element listy
 * @param end ostatni element listy
 * @return
 */

template <class type>
LinkedList<type>::node<type> *LinkedList<type>::partition(node<type> *start, node<type> *end)
{
	//wybieram ostatni element na pivota
	type pivot = end->data;
	//i=start-1;
	node<type> *i = start->prev;
	//for (int j=start; j<=end-1; j++)
	for (node<type> *j=start; j !=end; j=j->next)
	{
		if (j->data <= pivot)
		{
			if(i==NULL) i=start;
			else i=i->next;
			swap(&(i->data), &(j->data));
		}
	}
	//wstawiam pivota w odpowiednie miejsce
	if (i==NULL) i=start;
	else i=i->next;
	swap(&(i->data), &(end->data));
	return i;
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
