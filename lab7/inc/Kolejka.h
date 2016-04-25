#ifndef KOLEJKA_H
#define KOLEJKA_H
#include <iostream>

#include "IQueue.h"

class Kolejka : public IQueue
{
    public:
		Kolejka();
		virtual ~Kolejka();
		int getSize();      		//pobiera rozmiar tablicy
		virtual void enqueue(int a);		//dopisuje int a na koniec kolejki
		void display();    			//wyswietla zawartosc tablicy
		void dequeue();				//usuwa element z poczatku kolejki (FIFO)
		bool isEmpty();
		int getFront();
		int getRear();

    private:
		int *queue_;   			//wskaznik do tablicy dynamicznej
		int front_;
		int rear_;
		int size_;      		//aktualny rozmiar kolejki
		int count_;    			//liczba danych przechowywanych w kolejce
		void enlarge_x2();      //zwieksza rozmiar tablicy dwukrotnie, metoda nr 2

};


#endif // KOLEJKA_H
