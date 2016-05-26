/*
 * main.cpp
 *
 *  Created on: 20 maj 2016
 *      Author: paula
 */
#include <iostream>
#include "GraphTest.h"
#include "QueuePriority.h"


using namespace std;

int main(){

	Graph<int> G(5);
	G.addEdge(1,2,2);
	G.addEdge(1,5,5);
	G.addEdge(4,2,2);
	G.addEdge(5,3,1);
	G.addEdge(2,3,8);
	G.displayMatrix();
	cout<<endl;
	cout<<G.min(5);

	return 0;
}

