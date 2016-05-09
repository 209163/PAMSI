/*
 * GraphTest.h
 *
 *  Created on: 9 maj 2016
 *      Author: paula
 */

#ifndef GRAPHTEST_H_
#define GRAPHTEST_H_
#include <time.h>
#include "Graph.h"

template <class type>
class GraphTest :public Graph<type>{
public:
	GraphTest();
	virtual ~GraphTest();
	void run();
};

//*****************************************************************************************//
#include "GraphTest.h"

template <class type>
GraphTest<type>::GraphTest() {

}

template <class type>
GraphTest<type>::~GraphTest() {
}

template <class type>
void GraphTest<type>::run()
{
	srand (time(NULL));
	Graph<int> graf;
	//tworze wierzcholki
	for (int i=0; i<10; i++)
	{
		graf.addVertex(i);
		cout<<"dodano wierzcholek nr "<<i<<endl;
		for (int j=0;j<rand()%10+1;j++)
		{
			graf.addEdge(v,j,1);
			cout<<"dodano krawedz nr "<<j<<endl;
		}
	}




}


#endif /* GRAPHTEST_H_ */
