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
#include <iostream>
#include <string>
#include "LinkedList.h"
#include <list>
#include "Stack.h"
#include <stack>
#include "Queue.h"
#include <queue>
#include "ArrayList.h"
#include <vector>
#include <algorithm>
#include "Graph.h"
#include <iostream>
using namespace std;

using namespace std;

//#define VERTICES_AMOUNT 10  //rozmiar tablicy z wierzcholkami oraz liczba wierzchlokow

template <class type>
class Graph {
private:

	struct vertex{
		//waga krawedzi
		int weight_;
		//dolna granica
		int bound_;
		//dlugosc trasy
		int length_;
		//indeksy odwiedzonych wierzcholkow
		int *visited_;
	};
	//macierz sasiedztwa
	vertex **verticesMatrix_;
	//wskaznik do tablicy z nformacja czy wierzcholek jest juz dodany 1-ta, 0-nie

	//0-gdy dany wierzcholek ma krawedzie, 1-gdy jest pusty
	bool *isVertexEmpty_;
	int count_;
	int verticesAmount_;

public:
	Graph(int V);
	virtual ~Graph();

	/**
	 * funkcja dodajaca krawedz miedzy wierzcholkami
	 * @param index1 - nr indeksu pierwszego wierzcholka
	 * @param index2 - nr indeksu drugiego wierzcholka
	 * @param w - waga krawedzi
	 * @return
	 */
	int addEdge(int index1 , int index2, int w);
	//bool hasEdge(int vertex, int vertexToCheck);
	int getVerticesAmount(){return verticesAmount_;};
	//sortuje adjacency list dla i-tego wierzcholka
	void printVisited();
	//bool isFound(int vertex1, int vertex2);
	/**
	 * wybiera najkrotsza trase z wierzcholka (minimum w j-tym wierszu macierzy)
	 * do wyznaczania dolnej granicy
	 */
	int min(int index);
	void displayMatrix();

};

//*********************************************************************************************//

template <class type>
Graph<type>::Graph(int V)
{
	//rozmiar macierzy o jeden wiekszy niz liczba wierzcholkow,
	//dla indeksu 0 nie bedzie krawedzi
	verticesAmount_=V+1;
	count_=0;
	//alokacja pamieci
	verticesMatrix_= new vertex *[verticesAmount_];
	isVertexEmpty_= new bool [verticesAmount_];
	for(int i=0;i<verticesAmount_;++i)
	{
		isVertexEmpty_[i]=1;
		verticesMatrix_[i]=new vertex [verticesAmount_]; //alokacja pamieci
		for(int j=0; j<verticesAmount_;++j)
		{
			//0 dla i==j
			if(i==j) verticesMatrix_[i][j].weight_=0;
			else if(i==0 || j==0) verticesMatrix_[i][j].weight_=0;
			else
			//wypelniam macierz duza liczba (niskonczonosc) - brak krawedzi
			verticesMatrix_[i][j].weight_=999;
		}
	}
}

template <class type>
Graph<type>::~Graph()
{
	for (int i=0; i<verticesAmount_;++i)
	{
		delete [] verticesMatrix_[i];
	}
	delete [] verticesMatrix_;
	verticesMatrix_=NULL;
}

template <class type>
int Graph<type>::addEdge(int index1, int index2, int w)
{
	if(index1>verticesAmount_ || index2>verticesAmount_)
	{
		cout<<"nie ma takiego wierzcholka, przekroczona tablica"<<endl;
		return 0;
	}
	else if (index1==index2)
	{
		//
		verticesMatrix_[index1][index2].weight_=0;
	}
	else{
		verticesMatrix_[index1][index2].weight_=w;
		verticesMatrix_[index2][index1].weight_=w;
		isVertexEmpty_[index1]=0;
		isVertexEmpty_[index2]=0;

	}
	return 0;
}

template <class type>
int Graph<type>::min(int index)
{
	int min=998;
	if(isVertexEmpty_[index]==0){
		for(int i=1; i<verticesAmount_;i++)
		{
			if (verticesMatrix_[i][index].weight_!=0 && verticesMatrix_[i][index].weight_<min)
				{
					min=verticesMatrix_[i][index].weight_;
				}
		}
		return min;
	}
return 0;
}

template <class type>
void Graph<type>::displayMatrix()
{
	for (int i=0; i< verticesAmount_;i++)
	{
		for (int j=0; j<verticesAmount_; j++)
		{
			cout<<verticesMatrix_[i][j].weight_<<" ";
		}
		cout<<endl;
	}
}

#endif /* GRAPH_H_ */
