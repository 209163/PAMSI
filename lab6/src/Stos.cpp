/*
 * Stos.cpp
 *
 *  Created on: 22 mar 2016
 *      Author: paula
 */

#include "Stos.h"
#include <string>
#define STACK_SIZE 2


using namespace std;
/**
 * konstruktor
 */
/**
 * stack_ - wskaznik do tablicy dynamicznej ze stosem;
 * size_ - poczatkowy rozmiar stosu;
 * top_ - nr indeksu elementu na wierzchu;
 * count - aktualna liczba elementow na stosie;
 */
Stos::Stos() {
	if(size_<=0)
			throw string("Stack's capacity must be a positive");
	stack_= new int[size_];
	size_=STACK_SIZE;
	top_=-1;							//poczatkowo brak elementu na wierzchu stosu
	count_=top_+1;
}
/**
 * destruktor
 */
Stos::~Stos() {
	delete [] stack_;
}
/**
 * funkcja zwiekszajaca rozmiar stosu dwukrotnie
 */
void Stos::enlarge_x2()
{
	if(count_==size_)
	{
		size_=size_*2;
		int *tmp=new int[size_];
		for (int i=0; i<count_;i++)
		{
			tmp[i]=stack_[i];
		}
		stack_=tmp;
		delete [] tmp;
	}
}
/**
 * funkcja dokladajaca element na wierzch stosu
 * @param a - element, ktory ma byc dodany
 */
void Stos::push(int a)			//doklada element a na wierzch stosu
{
	if (top_==size_)
		enlarge_x2();
	top_++;
	stack_[top_]=a;
}
/**
 * funkcja zwracajaca wartosc elementu na wierzchu stosu
 * @return stack_[top_]
 */
int Stos::top()						//pokazuje bez usuwania element z wierzchu stosu
{
	if (top_ == -1)
		throw string("Stack is empty");
	return stack_[top_];
}
/**
 * funkcja zdejmujaca ze stosu element z wierzchu
 */
void Stos::pop()					//zdejmuje element ze stosu
{
	if (top_ == -1)
		throw string("Stack is empty");
	top_--;
}
/**
 * funkcja sprawdzajaca, czy stos jest pusty
 * @return - zwraca 1 gdy pusty, 0 gdy niepusty
 */
bool Stos::isEmpty()
{
	if (top_==-1)
		return 1;
	else
		return 0;
}
/**
 * funkcja zwracajaca rozmiar stosu
 * @return size_
 */
int Stos::getSize()
{
	return size_;
}
