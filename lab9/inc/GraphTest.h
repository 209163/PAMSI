/*
 * GraphTest.h
 *
 *  Created on: 20 maj 2016
 *      Author: paula
 */

#ifndef GRAPHTEST_H_
#define GRAPHTEST_H_
#include "Graph.h"
#include "QueuePriority.h"


template <class type>
class GraphTest : public Graph<type>{
private:
	int data;
public:
	GraphTest(int vAmount);
	virtual ~GraphTest();
	void run();
	//liczba danych
	int getData(){return data;};
};

template <class type>
GraphTest<type>::GraphTest(int vAmount) : Graph<type>(vAmount)
{
	data=vAmount;
}

template <class type>
GraphTest<type>::~GraphTest() {
	// TODO Auto-generated destructor stub
}


template <class type>
void GraphTest<type>::run(){

}


#endif /* GRAPHTEST_H_ */
