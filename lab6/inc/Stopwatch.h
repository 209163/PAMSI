/*
 * Stopwatch.h
 *
 *  Created on: 13 mar 2016
 *      Author: paula
 */

#ifndef STOPWATCH_H_
#define STOPWATCH_H_

class Stopwatch {
public:
	Stopwatch();
	virtual ~Stopwatch();
	double getRunTime();
	void setRunTime();
	void sendToFile(int number);
	double getStart();
	void setStart();
	double getStop();
	void setStop();

private:
	timeval time;
	double RunTime_;		//czas wykonania algorytmu
	double start_, stop_;
};

#endif /* STOPWATCH_H_ */
