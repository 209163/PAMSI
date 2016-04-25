/*
 * BSTtest.cpp
 *
 *  Created on: 24 kwi 2016
 *      Author: paula
 */

#include "BSTtest.h"
#include <cstdlib>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <iostream>
#include <cctype>
#include <iostream>

using namespace std;

BSTtest::BSTtest() {
	// TODO Auto-generated constructor stub

}

BSTtest::~BSTtest() {
	// TODO Auto-generated destructor stub
}

void BSTtest::run()
{
	srand (time(NULL));

		Lista list;
		list.add(10,0);
		list.add(100,1);
		list.add(1000,2);
		list.add(100000,3);
		list.add(1000000,4);
		list.add(1000000000,5);
		Stopwatch mea;
		BinarySearchTree tree;

	for(int j=0;j<5;j++)
	{
		mea.setStart();
		for (int i=0; i<list.getElem(j); i++)
		{

			int r=rand()%100+1;
			tree.add(r);
		}
		mea.setStop();
		mea.getRunTime();
		mea.sendToFile(j);
	}
}
