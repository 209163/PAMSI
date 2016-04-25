#include <iostream>

#include <cstdlib>
#include "Kolejka.h"

/**
 *poczatkowy rozmiar tablicy
 */
#define QUEUE_SIZE 2
using namespace std;

/**
 * konstruktor
 * size_-poczatkowy rozmiar kolejki
 * front_ - pierwszy element w kolejce
 * rear_ - ostatni element w kolejce
 * count_ - licznik elementow w kolejce
 */
Kolejka::Kolejka()
{
    size_=QUEUE_SIZE;
    queue_ = new int[size_];
    front_=0;
    rear_=0;
    count_=0;

}

Kolejka::~Kolejka()
{
	delete []queue_;
}

/**
 * funkcja zwiekszajaca rozmiar kolejki dwukrotnie
 */
void Kolejka::enlarge_x2()
   {
   	if(count_==size_-1)
   	{
   		size_=size_*2;
   		int *tmp=new int[size_];
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
void Kolejka::enqueue(int a)
{	count_=(size_-front_+rear_)%size_;

   		enlarge_x2();

   		queue_[rear_]=a;
   		rear_=(rear_+1)%size_;

}

/**
 * funkcja usuwajaca element z poczatku kolejki
 */
void Kolejka::dequeue()
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
 * funkcja, ktora sprawdza, czy kolejka jest pusta, zwraca 1, gdy tak
 * @return
 */
bool Kolejka::isEmpty()
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
int Kolejka::getSize()
{
  	return size_;
}

/**
 * funkcja zwracajaca wartosc pierwszego elementu w kolejce
 * @return
 */
int Kolejka::getFront()
{
	return queue_[front_];
}

/**
 * funkcja zwracajaca wartosc ostatneig elementu w kolejce
 * @return
 */
int Kolejka::getRear()
{
	return queue_[rear_];
}

/**
 * funkcja wyswietlajaca kolejke
 */
void Kolejka::display()
{
	for(int i=front_;i<rear_;i++)
	{
         cout<<queue_[i]<<endl;

	}
}
