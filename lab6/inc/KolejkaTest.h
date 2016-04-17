/*
 * KolejkaTest.h
 */

#ifndef KOLEJKATEST_H_
#define KOLEJKATEST_H_

#include <string>
#include "IRunnable.h"
#include "Kolejka.h"


class KolejkaTest : public Kolejka, public IRunnable
{
public:
	KolejkaTest();
	 ~KolejkaTest();
	 void run(int AmountOfComp);


};

#endif /* KOLEJKATEST_H_ */
