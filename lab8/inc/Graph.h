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
#include "Stack.h"
#include "ArrayList.h"
#include <string>
//#define VERTICES_AMOUNT 10  //rozmiar tablicy z wierzcholkami oraz liczba wierzchlokow

template <class type>
class Graph {
private:
	//ArrayList<type> vertices_;
	template <class type2>
	struct vertex{
			int index;
			string name;
			//int next;
			LinkedList<type> adjList;
		};
	vertex<type> *vertices_;
	//lista z odwiedzonymi wierzcholkaami
	bool *visited_;
	bool *visitedQ_;
	//stos z krawedziami kolejnych wierzcholkow
	Stack<type> toTraverse_;
	Queue<type> toTraverseQ_;
	int count_;
	int verticesAmount_;
	//void DFSvisited(int i, Stack S);


public:
	Graph(int V);
	virtual ~Graph();

	bool isVerticesEmpty();
	void addVertex(int vertexIndex);
	int addEdge(int index1 , int index2, int w);
	//int getNeighbours(vertex<type> v);
	bool hasEdge(int vertex, int vertexToCheck);
	void DFS(int startVertexIndex);
	void BFS(int startVertexIndex);
	int getVerticesAmount(){return verticesAmount_;};
	//sortuje adjacency list dla i-tego wierzcholka
	void adjListSort(int i);
	void printVisited();
	//dodaje nieodwiedzone nastepniki wierzcholka do stosu
	void addSuccessorToStack(int vertexIndex);
	void addSuccessorToQueue(int vertexIndex);
};

//*********************************************************************************************//
#include "Graph.h"
#include <iostream>
using namespace std;

template <class type>
Graph<type>::Graph(int V) {

	verticesAmount_=V+1;
	vertices_=new vertex<type>[verticesAmount_];
	visited_ = new bool[verticesAmount_];
	visitedQ_ = new bool[verticesAmount_];

	for(int i=0; i<verticesAmount_;i++)
		{
			vertices_[i].name="empty";
			//vertices_[i].next=0;
			vertices_[i].index=0;
			//NV-not visited, V-visited
			visited_[i]=0;
			visitedQ_[i]=0;
		}
	count_=0;
}

template <class type>
Graph<type>::~Graph() {
	delete [] vertices_;
	delete [] visited_;
	delete [] visitedQ_;
}

template <class type>
void Graph<type>::printVisited()
{
	for (int i = 1; i<verticesAmount_;i++)
	{
		cout<<visited_[i]<<" ";
	}
}


template <class type>
void Graph<type>::adjListSort(int i)
{
	vertices_[i].adjList.quicksort(vertices_[i].adjList.getFirst());
}


template <class type>
void Graph<type>::addSuccessorToQueue(int vertexIndex)
{
	ArrayList<type> A;

	int j=1;
	int sizeOfA=0;

	for (int i=1;i<=vertices_[vertexIndex].adjList.size();i++)
	{
		if(visitedQ_[vertices_[vertexIndex].adjList.getElem(i)] == 0)
		{

			//zapisuje do listy zeby potem przepisac w odwrotnej kolejnosci do stosu
			A.add(vertices_[vertexIndex].adjList.getElem(i),j);
			//cout<<vertices_[vertexIndex].adjList.getElem(i)<<endl;
			//cout<<"j= "<<j<<endl;
			//oznaczam jako odwiedzony "na potem", zeby wiecej sie w stosie nie pojawil
			visitedQ_[vertices_[vertexIndex].adjList.getElem(i)]=1;
			sizeOfA=j;
			j++;
		}


	}
	cout<<"sizeOfA= "<<sizeOfA<<endl;
	//cout<<"wychodzi z fora"<<endl;
	//przepisuje w odwrotnej kolejnosci
	for(int k=1; k>sizeOfA; k++)
	{
		//cout<<"for2 "<<k<<endl;
		toTraverseQ_.enqueue(A.getElem(k));

		//cout<<A.getElem(k)<<endl;
	}

}


template <class type>
void Graph<type>::BFS(int startVertexIndex)
{

	//vertices_[1].adjList.printLinkedList(vertices_[1].adjList.getFirst());

	//startujacy wierzcholek
	int start=startVertexIndex;
	//wrzucam startujacy wierzcholek do kolejki
	toTraverseQ_.enqueue(start);

	while(!toTraverseQ_.isEmpty())
	{
		//cout<<"top= "<<toTraverse_.getTop()<<endl;
		//biore element pierwszy z kolejki
		start = toTraverseQ_.getFront();
		cout<<"front= "<<toTraverseQ_.getFront()<<endl;
		//usuwam z kolejki odwiedzony element
		toTraverseQ_.dequeue();
		cout<<"odwiedzam "<<start<<endl;
		//juz odwiedzony
		visitedQ_[start]=1;
		//wrzucam nieodwiedzonych sasiadow do kolejki
		addSuccessorToQueue(start);
	}
}



template <class type>
void Graph<type>::addSuccessorToStack(int vertexIndex)
{
	ArrayList<type> A;

	int j=1;
	int sizeOfA=0;

	for (int i=1;i<=vertices_[vertexIndex].adjList.size();i++)
	{
		if(visited_[vertices_[vertexIndex].adjList.getElem(i)] == 0)
		{

			//zapisuje do listy zeby potem przepisac w odwrotnej kolejnosci do stosu
			A.add(vertices_[vertexIndex].adjList.getElem(i),j);
			//cout<<vertices_[vertexIndex].adjList.getElem(i)<<endl;
			//cout<<"j= "<<j<<endl;
			//oznaczam jako odwiedzony "na potem", zeby wiecej sie w stosie nie pojawil
			visited_[vertices_[vertexIndex].adjList.getElem(i)]=1;
			sizeOfA=j;
			j++;
		}


	}
	cout<<"sizeOfA= "<<sizeOfA<<endl;
	//cout<<"wychodzi z fora"<<endl;
	//przepisuje w odwrotnej kolejnosci
	for(int k=sizeOfA; k>0; k--)
	{
		//cout<<"for2 "<<k<<endl;
		toTraverse_.push(A.getElem(k));

		//cout<<A.getElem(k)<<endl;
	}

}

template <class type>
void Graph<type>::DFS(int startVertexIndex)
{

	//vertices_[1].adjList.printLinkedList(vertices_[1].adjList.getFirst());

	//startujacy wierzcholek
	int start=startVertexIndex;
	//wrzucam startujacy wierzcholek na stos
	toTraverse_.push(start);

	while(!toTraverse_.isEmpty())
	{
		//cout<<"top= "<<toTraverse_.getTop()<<endl;
		//biore element z gory stosu
		start = toTraverse_.top();
		cout<<"top= "<<toTraverse_.getTop()<<endl;
		//zdejmuje ze stosu odwiedzony element
		toTraverse_.pop();
		//cout<<"odwiedzam "<<start<<endl;
		//juz odwiedzony
		visited_[start]=1;
		//wrzucam nieodwiedzonych sasiadow na stos
		addSuccessorToStack(start);
	}
}


/**
 * dodaje danemu wierzcholkowi polaczenie z wierzcholkiem pod zadanym nrem indexu
 * @param v
 * @param index
 * @param w - waga krawedzi
 */
template <class type>
int Graph<type>::addEdge(int index1, int index2, int w)
{
	w=1;
	if(vertices_[index1].name=="empty")
	{
		addVertex(index1);
	}
	if(index1==index2) {
		//cerr<<"can't add edge, index1=index2= "<<index1<<endl;
		return 0;
	}

	else if(hasEdge(index1,index2)==1) {
		//cerr<<"edge almost add"<<endl;
		return 0;
	}

	else
		{
			vertices_[index1].adjList.addLast(index2);
			vertices_[index2].adjList.addLast(index1);
		}
	return 0;

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
	if(vertices_[index].name=="empty")
	{
	vertices_[index].name="taken";
	vertices_[index].index=index;
	count_++;
	}
}

//czy jest polaczenie miedzy wierzcholkiem v i wierzcholkiem o zadanym nrze indexu
template <class type>
bool Graph<type>::hasEdge(int vertex, int vertexToCheck)
{
	if(vertices_[vertex].adjList.isfound(vertexToCheck)==1) return 1;
	else return 0;
}



#endif /* GRAPH_H_ */
