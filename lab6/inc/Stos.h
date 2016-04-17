/*
 * Stos.h
 *
 *  Created on: 22 mar 2016
 *      Author: paula
 */

#ifndef STOS_H_
#define STOS_H_
#include "IStack.h"

class Stos : public IStack
{
public:
	Stos();
	virtual ~Stos();
	void push(int a);			//doklada element a na wierzch stosu
	int getSize();				//wyswietla aktualny romiar stosu
	virtual int top();			//pokazuje bez usuwania element z wierzchu stosu
	void pop();					//zdejmuje element ze stosu
	bool isEmpty();				//sprawdza czy stos jest pusty
	void enlarge_x2();			//zwieksza rozmiar stosu x2


private:
	int top_;
	int size_;
	int *stack_;
	int count_;					//counter - zlicza liczbę elementów na stosie
};

#endif /* STOS_H_ */
