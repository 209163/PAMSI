/*
 * IList.h
 *
 *  Created on: 14 mar 2016
 *      Author: paula
 */

#ifndef ILIST_H_
#define ILIST_H_
#include <iostream>
#include <string>
using namespace std;

class IList {
public:
	IList();
	virtual ~IList();
	int size();				//zwraca aktualny rozmiar listy
	void add(int a, int position);		//dodaje element do listy (gdziekolwiek)
	int getElem(int index);				//pobiera element ze wskazanego indeksu (bez usuwania)
			//throw(EmptyListExeption);
		/*wyjatki*/
	int getSize();      				//zwraca rozmiar tablicy
	void display(int i);    			//wyswietla zawartosc i-tego elem listy
	int find(string item);				//przeszukuje liste
	int getNext(int index);
	string getName(int index);
	bool isEmpty();						//zwraca 1 gdy lista jest pusta
	void remove(int index);				//usuwa element o danym indeksie
	int getCount();
	void displayFree();


};

#endif /* ILIST_H_ */
