/*
 * Graph.cpp
 *
 *  Created on: 25 kwi 2016
 *      Author: paula
 */

#include "Graph.h"
#include <iostream>
using namespace std;

Graph::Graph() {
	//matrixSize_=MATRIX_SIZE;
	adjacMatrix_=new int*[vertexAmount_];
	vertexAmount_=0;
	count_=0;
	for (int i=0;i <vertexAmount_;++i)
	{
		adjacMatrix_[i]= new int [vertexAmount_];
		for(int j=0;i<vertexAmount_; ++j)
		{
			adjacMatrix_[i][j]=0;		//macierz sasiedztwa poczatkowo wypelniona zerami
		}
	}

}

Graph::~Graph() {
	for (int i = 0; i < vertexAmount_; i++)

	           delete[] adjacMatrix_[i];

	delete[] adjacMatrix_;
}

void Graph::addEdge(vertex x , vertex y, int w)
{
	w=1;
	adjacMatrix_[x.index][y.index]=1;
	adjacMatrix_[y.index][x.index]=1;
}

void Graph::addVertex(vertex x)
{
	//x.value=0;
	x.index=count_;
	vertexAmount_++;
	count_++;
}

bool Graph::hasEdge(vertex x, vertex y)
{
	return adjacMatrix_[x.index][y.index];
}

void Graph::dispAdjacMatrix()
{
	for (int i=0;i<vertexAmount_;++i, cout<<endl)
	{
		for(int j=0;j<vertexAmount_;++j)
		{
			cout<<adjacMatrix_[i][j]<<'\t';
		}
	}
}

void Graph::test()
{
	vertex x,y,z;
	addVertex(x);
	cout<<vertexAmount_<<endl;
	addVertex(y);
	cout<<vertexAmount_<<endl;
	addVertex(z);
	cout<<vertexAmount_<<endl;
	dispAdjacMatrix();

	addEdge(z,x, 1);
	addEdge(y,z, 1);
	addEdge(y,x, 1);

	dispAdjacMatrix();
}
