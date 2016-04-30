/*
 * Lista.h
Lista określona jest przez 2 tablice, ktore maja nazwy 'name' i 'next'.
Jeżeli 'element' jest indeksem do tych tablic, to 'name[element]' jest zapamietanym obiektem,
a 'next[element]' indeksem nastepnego obiektu na liscie, o ile nastepny istnieje.
 */

#ifndef ARRAYLIST_H_
#define ARRAYLIST_H_
#include <iostream>
#include "Dictionary.h"
#include "IArrayList.h"
#include "Stopwatch.h"
#include "Kolejka.h"

class ArrayList : public IArrayList, public Dictionary, public Stopwatch, public Kolejka
{
public:
	ArrayList();
	virtual ~ArrayList();
	virtual void add(string item, int position);//dodaje element do listy (gdziekolwiek), item - dodawany element, position - indeks elementu listy, po ktorym ma byc wstawiony item
		//throw(EmptyListExeption);
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

private:
    string *name_;     		//wskaznik do tablicy dynamicznej z zapamietanymi obiektami
    int *next_;				//wskaznik do tab dyn (kolejki) z indeksami nastepnych elementow
    Kolejka free_;			//obiekt typu kolejka wolnych lokalizacji
    int size_;      		//aktualny rozmiar tablicy
    int count_;    			//liczba danych przechowywanych w tablicy
    int end_;
    void enlarge_by1();     //zwieksza rozmiar tablicy o 1, metoda nr 1
    void enlarge_x2();      //zwieksza rozmiar tablicy dwukrotnie, metoda nr 2
    void enlarge_x3();		//zwieksza rozmiar tablicy trzykrotnie, metoda nr 3
};

#endif /* ARRAYLIST_H_ */
