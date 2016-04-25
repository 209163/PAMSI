/*
 * BSTtest.h
 *
 *  Created on: 24 kwi 2016
 *      Author: paula
 */

#ifndef BSTTEST_H_
#define BSTTEST_H_
#include "IRunnable.h"
#include "Lista.h"
#include "Stopwatch.h"
#include "BinarySearchTree.h"

class BSTtest : public IRunnable, public Lista, public BinarySearchTree, public Stopwatch
{
public:
	BSTtest();
	virtual ~BSTtest();
	void run();
};

#endif /* BSTTEST_H_ */
