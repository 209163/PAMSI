/*
 * ListaTest.h
 *
 *  Created on: 20 mar 2016
 *      Author: paula
 */

#ifndef LISTATEST_H_
#define LISTATEST_H_
#include <iostream>

#include "ArrayList.h"
#include "IRunnable.h"



class ListaTest : public ArrayList, public IRunnable
{
public:
	ListaTest();
	virtual ~ListaTest();
	void run(int AmountOfComp);

};

#endif /* LISTATEST_H_ */
