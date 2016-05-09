/*
 * Graph.h
 *
 *  Created on: 25 kwi 2016
 *      Author: paula
 */
//adjacency list
#ifndef GRAPH_H_
#define GRAPH_H_
#define LIST_SIZE 3
#include "LinkedList.h"
#include "ArrayList.h"
#include <string>
#define VERTICES_AMOUNT 10  //rozmiar tablicy z wierzcholkami

template <class type>
class Graph : public LinkedList<type>{
private:
	//ArrayList<type> vertices_;
	template <class type2>
	struct vertex{
			int index;
			string name;
			int next;
			LinkedList<type> connections;
		};
	vertex<type> *vertices_;
	int count_;

public:
	Graph();
	virtual ~Graph();

	bool isVerticesEmpty();
	void addVertex(int position);
	void addEdge(int index1 , int index2, int w);
	int getNeighbours(vertex<type> v);
	bool hasEdge(vertex<type> x, int vertexIndex);

};

//*********************************************************************************************//
#include "Graph.h"
#include <iostream>
using namespace std;

template <class type>
Graph<type>::Graph() {

	vertices_=new vertex<type>[VERTICES_AMOUNT];
	for(int i=0; i<VERTICES_AMOUNT;i++)
		{
			vertices_[i].name="empty";
			vertices_[i].next=0;
			vertices_[i].index=0;
		}
	count_=0;
}

template <class type>
Graph<type>::~Graph() {
	delete [] vertices_;
}

/**
 * dodaje danemu wierzcholkowi polaczenie z wierzcholkiem pod zadanym nrem indexu
 * @param v
 * @param index
 * @param w - waga krawedzi
 */
template <class type>
void Graph<type>::addEdge(int index1, int index2, int w)
{
	w=1;


}


template <class type>
bool Graph<type>::isVerticesEmpty()
{
	if(count_==0) return 1;
	else return 0;
}

template <class type>
void Graph<type>::addVertex(int index)
{
	//tworze nowy wierzcholek
	vertex<type> v;
	v.index=index;
	v.name="taken";
	v.next=0;
	//wstawiam go do tablicy
	vertices_[index]=v;
	count_++;
}

//czy jest polaczenie miedzy wierzcholkiem v i wierzcholkiem o zadanym nrze indexu
template <class type>
bool Graph<type>::hasEdge(vertex<type> v, int vertexIndex)
{
	if(v.connections.isfound(vertexIndex)==1) return 1;
	else return 0;
}



#endif /* GRAPH_H_ */
