#ifndef Queue_H
#define Queue_H
#include <iostream>

/**
 *poczatkowy rozmiar tablicy
 */
#define QUEUE_SIZE 2
using namespace std;

#include "IQueue.h"

template <class type>
class Queue : public IQueue<type>
{
    public:
		Queue();
		virtual ~Queue();
		int getSize();      		//pobiera rozmiar tablicy
		void enqueue(int a);		//dopisuje int a na koniec kolejki
		void display();    			//wyswietla zawartosc tablicy
		void dequeue();				//usuwa element z poczatku kolejki (FIFO)
		bool isEmpty();
		type getFront();
		type getRear();

    private:
		type *queue_;   			//wskaznik do tablicy dynamicznej
		type front_;
		type rear_;
		int size_;      		//aktualny rozmiar kolejki
		int count_;    			//liczba danych przechowywanych w kolejce
		void enlarge_x2();      //zwieksza rozmiar tablicy dwukrotnie, metoda nr 2

};

/****************************************************************************************************/


/**
 * konstruktor
 * size_-poczatkowy rozmiar kolejki
 * front_ - pierwszy element w kolejce
 * rear_ - ostatni element w kolejce
 * count_ - licznik elementow w kolejce
 */
template <class type>
Queue<type>::Queue()
{
    size_=QUEUE_SIZE;
    queue_ = new type[size_];
    front_=0;
    rear_=0;
    count_=0;

}

template <class type>
Queue<type>::~Queue()
{
	delete []queue_;
}

/**
 * funkcja zwiekszajaca rozmiar kolejki dwukrotnie
 */
template <class type>
void Queue<type>::enlarge_x2()
   {
   	if(count_==size_-1)
   	{
   		size_=size_*2;
   		int *tmp=new type[size_];
   		for (int i=0; i<count_;i++)
   		{
   			tmp[i]=queue_[i];
   		}
   		delete [] queue_;
   		queue_=tmp;
  	}
}
/**
 * funkcja dodajaca element na koncu kolejki
 */
template <class type>
void Queue<type>::enqueue(int a)
{	count_=(size_-front_+rear_)%size_;

   		enlarge_x2();

   		queue_[rear_]=a;
   		rear_=(rear_+1)%size_;

}

/**
 * funkcja usuwajaca element z poczatku kolejki
 */

template <class type>
void Queue<type>::dequeue()
{
	if (isEmpty())
		throw string("Stack is empty");
	else
	{
		//int temp=queue_[front_];
		front_=(front_+1)%size_;
		//return temp;
	}
}
/**
 * funkcja, ktora sprawdza, czy Queue jest pusta, zwraca 1, gdy tak
 * @return
 */
template <class type>
bool Queue<type>::isEmpty()
{
   	if (front_==rear_)
   		return 1;
   	else
  		return 0;
}


/**
 * funkcja, ktora zwraca rozmiar kolejki
 * @return
 */
template <class type>
int Queue<type>::getSize()
{
  	return size_;
}

/**
 * funkcja zwracajaca wartosc pierwszego elementu w kolejce
 * @return
 */
template <class type>
type Queue<type>::getFront()
{
	return queue_[front_];
}

/**
 * funkcja zwracajaca wartosc ostatneig elementu w kolejce
 * @return
 */
template <class type>
type Queue<type>::getRear()
{
	return queue_[rear_];
}

/**
 * funkcja wyswietlajaca kolejke
 */
template <class type>
void Queue<type>::display()
{
	for(int i=front_;i<rear_;i++)
	{
         cout<<queue_[i]<<endl;

	}
}


#endif // Queue_H
