/*
 * Stopwatch.h
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
	int getAmountOfData();
	void setAmountOfData(int AmountOfData);
	void displayRunTime();

private:
	timeval time;
	double RunTime_;		//czas wykonania algorytmu
	double start_, stop_;
	int amountOfData_;
};

#endif /* STOPWATCH_H_ */
