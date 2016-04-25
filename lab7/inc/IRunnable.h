/*
 * IRunnable.h
 *
 *  Created on: 25 kwi 2016
 *      Author: paula
 */

#ifndef IRUNNABLE_H_
#define IRUNNABLE_H_

class IRunnable {
public:
	IRunnable();
	virtual ~IRunnable();
	virtual void run()=0;
};

#endif /* IRUNNABLE_H_ */
