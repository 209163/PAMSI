/*
 * IHash.h
 *
 *  Created on: 30 kwi 2016
 *      Author: paula
 */

#ifndef IHASH_H_
#define IHASH_H_
#include <string>
using namespace std;

class IHash {
public:
	IHash();
	virtual ~IHash();
	///funkcja hashująca
	virtual int hash(string key)=0;
	void addItem(string name, int tel);
	///liczba elementow w buckecie
	int numberOfItemsInIndex(int index);
	///wyswietla zawartosc bucketow
	void printTable();
	///wyswietla wszystkie itemy z bucketu o danym numerze indexu
	void printItemsInIndex(int index);
	///wyszukuje slowo i zwraca nr indexu pod ktorym sie znajduje
	void find(string name);
	int getTableSize();
};

#endif /* IHASH_H_ */
