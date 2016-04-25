/*
 * IBinarySearchTree.h
 *
 *  Created on: 18 kwi 2016
 *      Author: paula
 */

#ifndef IBINARYSEARCHTREE_H_
#define IBINARYSEARCHTREE_H_

/**
 * Interfejs klasy BSTTree
 */
class IBinarySearchTree {
public:
	IBinarySearchTree();
	virtual ~IBinarySearchTree();
	/**
	 * funkcja dodajaca liczbe do drzewa
	 * @param a
	 */
	virtual void add(int a)=0;
	void enlarge_x2();



};

#endif /* IBINARYSEARCHTREE_H_ */
