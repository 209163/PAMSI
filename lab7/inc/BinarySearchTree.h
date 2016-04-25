/*
 * BST.h
 *
 *  Created on: 18 kwi 2016
 *      Author: paula
 */

#ifndef BINARYSEARCHTREE_H_
#define BINARYSEARCHTREE_H_
#include <string>


#define BEGIN_SIZE 3		//poczatkowy rozmiar drzewa
#include "IBinarySearchTree.h"
#include "Lista.h"
/**
 * klasa implementujaca drzewo binarne
 */
class BinarySearchTree : public IBinarySearchTree
{
private:
	struct node
		{
		int key;
		node *parent;
		char color;
		node *left;
		node *right;
		};
	node *root_;
	node *q_;
	//Lista takenIndex;

public:
	BinarySearchTree();
	virtual ~BinarySearchTree();

	//int max(int a, int b);
	//int getSize();
	void add(int z);
	void find(int x);
	//void enlarge_x2();
	//int isEmpty();
	node getElem(int index);
	void addfix(node *t);
	void leftRotate(node *p);
	void rightRotate(node *p);
	void display();
	void display(node *p);
	//void quicksort(int *tab, int left, int right);

};

#endif /* BINARYSEARCHTREE_H_ */
