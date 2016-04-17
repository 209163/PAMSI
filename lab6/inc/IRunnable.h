/*
 * IRunnable.h
 */

#ifndef IRUNNABLE_H_
#define IRUNNABLE_H_

class IRunnable {
public:
	IRunnable();
	virtual ~IRunnable();
	virtual void run(int AmountOfComp)=0;		//informacja czy dobiegl
	//virtual bool prepared()=0;	//inf czy gotowy
};

#endif /* IRUNNABLE_H_ */
