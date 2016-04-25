/*
 * Graph.h
 *
 *  Created on: 25 kwi 2016
 *      Author: paula
 */
//macierz sasiedztwa
#ifndef GRAPH_H_
#define GRAPH_H_
#define MATRIX_SIZE 3


class Graph {
private:
	int vertexAmount_;		//liczba wierzcholkow
	int **adjacMatrix_;		//wskaznik na dwuwymiarowa macierz sasiedztwa
	//int matrixSize_;		//rozmiar macierzy sasiedztwa
	int count_;				//do nadawania indeksow nowym wierzcholkom

public:
	Graph();
	virtual ~Graph();
	struct vertex{
		//int value;
		vertex *next;
		int index;
	};
	void addVertex(vertex v);
	void addEdge(vertex x, vertex y, int w);
	int getNeighbours(vertex v);
	bool hasEdge(vertex x, vertex y);
	void dispAdjacMatrix();
	void test();

};

#endif /* GRAPH_H_ */
