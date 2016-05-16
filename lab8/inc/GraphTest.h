/*
 * GraphTest.h
 *
 *  Created on: 9 maj 2016
 *      Author: paula
 */

#ifndef GRAPHTEST_H_
#define GRAPHTEST_H_
#include <time.h>
#include <cstdlib>
#include <cstdio>
#include "Graph.h"
#include "Stack.h"
#include "Stopwatch.h"
#include "Queue.h"

template <class type>
class GraphTest :public Graph<type>{
public:
	GraphTest(int vAmount);
	virtual ~GraphTest();
	void run();
	int data;
};

//*****************************************************************************************//
#include "GraphTest.h"

template <class type>
GraphTest<type>::GraphTest(int vAmount) : Graph<type>(vAmount)
{
	data=vAmount;
}

template <class type>
GraphTest<type>::~GraphTest() {
}

template <class type>
void GraphTest<type>::run()
{

		Queue<int> que;
		que.enqueue(10);
		que.enqueue(100);
		que.enqueue(1000);
		que.enqueue(100000);
		que.enqueue(1000000);
		que.enqueue(1000000000);
//*********************************************************************************

	srand(time(NULL));
//	for(int n=0; n<2; n++)
//	{
		Stopwatch mea;
		mea.setAmountOfData(que.getFront());
		//int data=50;//mea.getAmountOfData();
		que.dequeue();
		Graph<int> graf(data);


	//*********************** przygotowuje graf ******************************************************//
		//tworze wierzcholki
		for (int i=1; i<graf.getVerticesAmount(); i++)
		{
			graf.addVertex(i);
			//cout<<"dodano wierzcholek nr "<<i<<endl;
		}
		//dodaje krawedzie
		for (int i=1; i<graf.getVerticesAmount(); i++)
		{
			for (int j=0;j<rand()%data+1;j++)
			{
				int k=rand()%data+1;
				if(i==k) {
					//cout<<"te same indexy "<<endl;
					break;
				}
				else {
					graf.addEdge(i,k,1);
					cout<<"dodano krawedz miedzy"<<i<<" a "<< k<<endl;
				}

			}
		}
		//sortuje zeby wrzucac na stos od najmniejszego indeksu do najwiekszego
		for (int i=1; i<graf.getVerticesAmount(); i++)
			{
				graf.adjListSort(i);
				//cout<<"posortowano adjacency lists "<<endl;
			}
		//algorytm DFS
		mea.setStart();
		graf.BFS(1);
		mea.setStop();
		mea.getRunTime();
		mea.displayRunTime();
		mea.sendToFile(data);

	//	wyswietlam tablice odwiedzonych wierzcholkow
		graf.printVisited();

//}
}


#endif /* GRAPHTEST_H_ */
