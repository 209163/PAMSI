/*
 * IBSTTree.h
 *
 *  Created on: 18 kwi 2016
 *      Author: paula
 */

#ifndef IBSTTREE_H_
#define IBSTTREE_H_

/**
 * Interfejs klasy BSTTree
 */
class IBSTTree {
public:
	IBSTTree();
	virtual ~IBSTTree();
	/**
	 * funkcja porownujaca 2 liczby
	 * @param a
	 * @param b
	 * @return
	 */
	int compare(int a, int b);
	/**
	 * funkcja dodajaca liczbe do drzewa
	 * @param a
	 */
	void add(int a);
	int size();



};

#endif /* IBSTTREE_H_ */
