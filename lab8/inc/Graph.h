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

template <class type>
class Graph : public LinkedList<type>, public ArrayList<type>{
private:
	ArrayList<type> vertices_;

public:
	Graph();
	virtual ~Graph();
	template <class type2>
	struct vertex{
		type data;
		LinkedList<type> connections;
	};

	void addVertex(int position);
	void addEdge(vertex<type> v , int index, int w);
	int getNeighbours(vertex<type> v);
	bool hasEdge(vertex<type> x, int vertexIndex);

};

//*********************************************************************************************//
#include "Graph.h"
#include <iostream>
using namespace std;

template <class type>
Graph<type>::Graph() {

}

template <class type>
Graph<type>::~Graph() {

}

/**
 * dodaje danemu wierzcholkowi polaczenie z wierzcholkiem pod zadanym nrem indexu
 * @param v
 * @param index
 * @param w - waga krawedzi
 */
template <class type>
void Graph<type>::addEdge(vertex<type> v , int index, int w)
{
	w=1;

	v.connections.addLast(index);
}

template <class type>
void Graph<type>::addVertex(int position)
{
	vertex<type> v;
	vertices_.add(v.connections, position);
}

//czy jest polaczenie miedzy wierzcholkiem v i wierzcholkiem o zadanym nrze indexu
template <class type>
bool Graph<type>::hasEdge(vertex<type> v, int vertexIndex)
{
	if(v.connections.isfound(vertexIndex)==1) return 1;
	else return 0;
}



#endif /* GRAPH_H_ */
