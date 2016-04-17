/*
 * kolejkaTest.cpp
 *
 *  Created on: 13 mar 2016
 *      Author: paula
 */
#include <iostream>
#include <cstdio>
using namespace std;

#include "KolejkaTest.h"

KolejkaTest::KolejkaTest() {
}

KolejkaTest::~KolejkaTest() {
}

void KolejkaTest::run(int AmountOfComp)		//liczba skladnikow do dodania
{
	Kolejka que;	//queue
	for (int i=0; i<AmountOfComp; i++)
	{
		que.enqueue(i);	//dopisanie elementu do kolejki
	}

}
