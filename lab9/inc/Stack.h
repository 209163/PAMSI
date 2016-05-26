/*
 * Stos.h
 *
 *  Created on: 22 mar 2016
 *      Author: paula
 */

#ifndef STACK_H_
#define STACK_H_
#include "IStack.h"
#define STACK_SIZE 10
#include <string>

using namespace std;


template <class type>
class Stack : public IStack<type>
{
public:
	Stack();
	virtual ~Stack();
	void push(type a);			//doklada element a na wierzch stosu
	int getSize();				//wyswietla aktualny romiar stosu
	type top();			//zwraca bez usuwania element z wierzchu stosu
	void pop();					//zdejmuje element ze stosu
	bool isEmpty();				//sprawdza czy stos jest pusty
	void enlarge_x2();			//zwieksza rozmiar stosu x2
	type getTop(){return top_;};


private:
	type top_;
	int size_;
	type *stack_;
	int count_;					//counter - zlicza liczbę elementów na stosie
};


//****************************************************************************************************/

/**
 * konstruktor
 */
/**
 * stack_ - wskaznik do tablicy dynamicznej ze Stackem;
 * size_ - poczatkowy rozmiar Stacku;
 * top_ - nr indeksu elementu na wierzchu;
 * count - aktualna liczba elementow na Stackie;
 */
template <class type>
Stack<type>::Stack() {
	size_=STACK_SIZE;
	stack_= new type[size_];
	top_=-1;							//poczatkowo brak elementu na wierzchu Stacku
	count_=top_+1;
}
/**
 * destruktor
 */
template <class type>
Stack<type>::~Stack() {
	delete [] stack_;
}
/**
 * funkcja zwiekszajaca rozmiar Stacku dwukrotnie
 */
template <class type>
void Stack<type>::enlarge_x2()
{
	if(count_==size_)
	{
		size_=size_*2;
		int *tmp=new type[size_];
		for (int i=0; i<count_;i++)
		{
			tmp[i]=stack_[i];
		}
		stack_=tmp;
		delete [] tmp;
	}
}
/**
 * funkcja dokladajaca element na wierzch Stacku
 * @param a - element, ktory ma byc dodany
 */

template <class type>
void Stack<type>::push(type a)			//doklada element a na wierzch Stacku
{
	if (top_==size_) enlarge_x2();
	top_++;
	stack_[top_]=a;
}
/**
 * funkcja zwracajaca wartosc elementu na wierzchu Stacku
 * @return stack_[top_]
 */
template <class type>
type Stack<type>::top()						//pokazuje bez usuwania element z wierzchu Stacku
{
	if (top_ == -1)
		{
			//cout<<"top nie dziala"<<endl;
			throw string("Stack is empty");
		}
		return stack_[top_];
}
/**
 * funkcja zdejmujaca ze Stacku element z wierzchu
 */
template <class type>
void Stack<type>::pop()					//zdejmuje element ze Stacku
{
	if (top_ == -1)
		{
		//cout<<"pop nie dziala"<<endl;
		throw string("Stack is empty");
		}
	top_--;
}
/**
 * funkcja sprawdzajaca, czy Stos jest pusty
 * @return - zwraca 1 gdy pusty, 0 gdy niepusty
 */
template <class type>
bool Stack<type>::isEmpty()
{
	return (top_ == -1);
}
/**
 * funkcja zwracajaca rozmiar Stosu
 * @return size_
 */
template <class type>
int Stack<type>::getSize()
{
	return size_;
}


#endif /* STACK_H_ */
