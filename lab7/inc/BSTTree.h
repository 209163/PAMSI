/*
 * BSTTree.h
 *
 *  Created on: 18 kwi 2016
 *      Author: paula
 */

#ifndef BSTTREE_H_
#define BSTTREE_H_
#define BEGIN_SIZE 3		//poczatkowy rozmiar drzewa
#include "IBSTTree.h"
/**
 * klasa implementujaca drzewo binarne
 */
class BSTTree : public IBSTTree {
public:
	BSTTree();
	virtual ~BSTTree();
	/**
	 * funkacja porownuje 2 elementy typu int
	 * @param a pierwszy element
	 * @param b drugi element
	 * @return zwraca wiekszy element
	 */
	int max(int a, int b);
	int getSize();
	void insertElement(int a);
	void enlarge_x2();
private:
	int size_;
	int *tree_;
	int count_;

};

#endif /* BSTTREE_H_ */
