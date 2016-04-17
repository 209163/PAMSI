/*
 * ListaTest.cpp
 *
 *  Created on: 20 mar 2016
 *      Author: paula
 */
#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <ctime>
#include "ListaTest.h"
#include "Dictionary.h"
#include "Lista.h"

using namespace std;

ListaTest::ListaTest() {


}

ListaTest::~ListaTest() {

}
/**
 * funkcja testujaca przeszukiwanie listy
 * @param AmountOfComp
 */

void ListaTest::run(int AmountOfComp)					//liczba skladnikow do dodania
{
//**********************************************************************
	Dictionary dict;
	dict.setWords();									//wczytuje slownik do tablicy
	Lista list;

	for (int i=0; i<AmountOfComp;i++)					//lista randomowych wyrazow
	{
		list.add(dict.RandomWords(), list.getSize() );
		//list.display(i);
	}
//************************************************************************
	for (int i=0;i<10;i++)
	{
	string a,b,c;
	int j=0.1 * AmountOfComp;							//sprawdzam jakie wyrazy sa na poczatku, w srodku oraz blisko konca listy
	int k=0.5 * AmountOfComp;
	int l=0.9 * AmountOfComp;
	a=list.getName(list.getNext(j));
	b=list.getName(list.getNext(k));
	c=list.getName(list.getNext(l));
	cout<<"words to find:"<<endl;
	cout<<a<<", "<<b<<", "<<c<<endl;
//************************************************************************
	/*PRZESZUKIWANIE - string a*/
	{cout<<"pomiar nr"<<i<<endl;
	Stopwatch mea;									//measure
	mea.setStart();									//wlaczenie stopera
	list.find(a);
	mea.setStop();								//wylaczenie stopera
	mea.setRunTime();							//obliczenie czasu wykonywania algorytmu
	//mea.sendToFile(1);							//przeslanie obliczen do pliku
	printf("%.8f sek\n", mea.getRunTime());
	}
	/*PRZESZUKIWANIE - string b*/
	{
	Stopwatch mea;
	mea.setStart();									//wlaczenie stopera
	list.find(a);
	mea.setStop();								//wylaczenie stopera
	mea.setRunTime();							//obliczenie czasu wykonywania algorytmu
	//mea.sendToFile(2);							//przeslanie obliczen do pliku
	printf("%.8f sek\n", mea.getRunTime());
	}

	/*PRZESZUKIWANIE - string c*/
	{
	Stopwatch mea;
	mea.setStart();									//wlaczenie stopera
	list.find(c);
	mea.setStop();								//wylaczenie stopera
	mea.setRunTime();							//obliczenie czasu wykonywania algorytmu
	//mea.sendToFile(3);							//przeslanie obliczen do pliku
	printf("%.8f sek\n", mea.getRunTime());
	}
	}
}
