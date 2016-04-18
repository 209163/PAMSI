/*
 * BSTTree.cpp
 *
 *  Created on: 18 kwi 2016
 *      Author: paula
 */

#include "BSTTree.h"
//#include <cstddef>

BSTTree::BSTTree() {
	tree_=new int[size_];
	size_=BEGIN_SIZE;
	count_=0;

}

BSTTree::~BSTTree() {
	delete [] tree_;
}

void BSTTree::insertElement(int a)
{
	int currentIndex=0;
	while(true)
	{
		if (tree_[currentIndex]==0)
		{
			tree_[currentIndex]=a;	//
			break;
		}

	}
}

int BSTTree::max(int a, int b)
{
	if(a>b) return a;
	else return b;
}

void BSTTree::enlarge_x2()
{
	if(size_==(count_+1) )
	    {
	        size_=size_*2;
	        int *tmp= new int[size_];
	        for(int i=0; i<=count_;i++)
	        {
	            tmp[i]=tree_[i];      //przepisuje dane ze starej tablicy do nowej
	        }
	        delete [] tree_;
	        tree_ =tmp;

	    }
}
