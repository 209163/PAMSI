/*
 * Hash.h
 */
#ifndef HASH_H_
#define HASH_H_
#include <iostream>
#include <string>
#include <cstdlib>
#include "IHash.h"
#include "Stopwatch.h"
using namespace std;

class Hash : public Stopwatch, public IHash{
private:
	//liczba 'bucketow'
	int tableSize_;
	struct item{
		string name;
		int tel;
		item* next;
	};

	item *hashTable;

public:
	Hash(int tableSize);
	virtual ~Hash();
	///funkcja hashująca
	int hash(string key);
	void addItem(string name, int tel);
	///liczba elementow w buckecie
	int numberOfItemsInIndex(int index);
	///wyswietla zawartosc bucketow
	void printTable();
	///wyswietla wszystkie itemy z bucketu o danym numerze indexu
	void printItemsInIndex(int index);
	///wyszukuje slowo i zwraca nr indexu pod ktorym sie znajduje
	int find(string name);
	int getTableSize();
	///przeciazenie operatora []
	int operator [ ] (string key);
};

#endif /* HASH_H_ */
