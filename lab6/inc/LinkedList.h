/*
 * LinkedList.h
 *
 *  Created on: 17 kwi 2016
 *      Author: paula
 */

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_


#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class LinkedList {
private:
	int sizeOfList;
public:
	///@brief klasa 'malych struktur' gdzie jest numer i wskaznik do nast elementu
	class LinkedListElement{
	public:
		///Liczba przechowywana
		int number;
		string name;
		///wskaznik do nastepnej 'malej struktury' w liscie
		LinkedListElement *nextElement;
		///wskaznik do poprzedniej 'malej struktury' w liscie
		LinkedListElement *previousElement;
		/**
		 * @brief Konstruktor wewn klasy 'malych struktur'
		 */
		LinkedListElement();
		/**
		 * @brief Konstruktor wewnetrznej klasy 'malych struktur'
		 * @param arg liczba do zapisania w kolejnym elemencie listy
		 * @param str klucz tablicy asocjacyjnej
		 */
		LinkedListElement(int arg, string str);
		/**
		 * @brief Konstruktor kopiujacy wewnetrznej klasy 'malych struktur'
		 * @param linkedListElement element do przekopiowania
		 */
		LinkedListElement(const LinkedListElement &linkedListElement);
		/**
		 * @brief Ustawia liczbe oraz klucz slownika dla elementu
		 * @param arg liczba do zapisania
		 * @param str slowo do zapisania
		 */
		void set(int arg, string str);
		friend class LinkedList;
	};
	///wskaznik do 'malej struktury' ktora jest pierwsza na liscie
	LinkedListElement *firstElement;
	///wskaznik do 'malej struktury' ktora jest ostatnia na liscie
	LinkedListElement *lastElement;

	///konstruktor
	LinkedList();
	///destruktor
	virtual ~LinkedList();
	LinkedListElement *iterator;
	int iteratorElementId;
	int isIteratorAfterPop;
	/**
	 * @brief Zwraca ilosc elementow listy
	 * @return ilosc elementow listy
	 */
	int size();
	/**
	 * @brief Zwraca ostatni element w liscie
	 * @return ostatni element w liscie
	 */
	LinkedListElement pop_back();
	/**
	 * @brief zwraca pierwszy element w liscie
	 * @return pierwszy element w liscie
	 */
	LinkedListElement pop_front();
	/**
	 * @brief wklada element na ostatnie miejsce w liscie
	 * @param arg
	 */
	void push_back(LinkedListElement arg);
	/**
	 * @brief Wklada element na ostatnie miejsce w liscie
	 * @param arg
	 */
	void push_front(LinkedListElement arg);
	/**
	 * @brief Pokazuje element z poczatku listy
	 * @return zwraca kopie tego elementu
	 */
	LinkedListElement &show_front();
	/**
	 * @brief Pokazuje element z konca listy
	 * @return zwraca kopie tego elementu
	 */
	LinkedListElement &show_back();
	/**
	 * @brief @brief Wyswietla elementy listy
	 */
	void printList();
	/**
	 * @brief Pobiera element z listy
	 * @return Zwraca 0 gdy zapisywanie powiodlo sie
	 */
	LinkedListElement &operator[](int numberOfElements);
	/**
	 * @brief Wsadza element po obiekcie iteratora
	 */
	void insertAfter(LinkedListElement arg, int iteratorID);


};

#endif /* LINKEDLIST_H_ */
