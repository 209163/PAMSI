/*
 * HashTest.cpp
 *
 *  Created on: 27 kwi 2016
 *      Author: paula
 */

#include "HashTest.h"
#include "Kolejka.h"
#include "Hash.h"
#include "Dictionary.h"
#include "Stopwatch.h"
#include "ArrayList.h"
#include <iostream>
#include <string>

HashTest::HashTest() {


}

HashTest::~HashTest() {

}

void HashTest::run()
{

	Kolejka que;
	que.enqueue(10);
	que.enqueue(100);
	que.enqueue(1000);
	que.enqueue(100000);
	que.enqueue(1000000);
	que.enqueue(1000000000);
	//**********************************************************************

		for(int i =0; i<6; i++)
		{
			Dictionary dict;
			dict.setWords();									//wczytuje slownik do tablicy
			//ArrayList list;
			Stopwatch mea;

//			int data=100000;		//liczba elementow

				mea.setAmountOfData(que.getFront());
				int data=mea.getAmountOfData();
				que.dequeue();
				Hash h(data/10);	//liczba slotow
				mea.setStart();
				//cout<<"rozpoczeto pomiar"<<endl;
				//wpisuje
				for (int j=0; j<(data-1);j++)					//lista randomowych wyrazow
				{
					h.addItem(dict.RandomWords(), j);

				}
				//cout<<"dodano"<<endl;
				h.addItem("tofind", data);
				mea.setStop();
				mea.displayRunTime();
				mea.sendToFile(data);
				//przeszukuje
				mea.setStart();
				h.find("tofind");
				mea.setStop();
				mea.displayRunTime();
				mea.sendToFile(data);

		}


}
