/*
 * IQueue.h
 */

#ifndef IQUEUE_H_
#define IQUEUE_H_

class IQueue {			//interfejs
public:
	IQueue();
	virtual ~IQueue();
	virtual void enqueue(int a) =0;		//dodaje element int a na koncu kolejki
		//throw(TakenIndexExeption);
	int size();		//aktualny rozmiar
	bool isEmpty();		//sprawdza czy tablica nie jest pusta
	void dequeue();		//usuwa pierwszy element kolejki (LIFO)
		//throw(EmptyQueueExeption);

};

#endif /* IQUEUE_H_ */
