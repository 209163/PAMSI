/*
 * ILinkedList.h
 *
 *  Created on: 17 kwi 2016
 *      Author: paula
 */

#ifndef ILINKEDLIST_H_
#define ILINKEDLIST_H_

class ILinkedList {
public:
	ILinkedList();
	virtual ~ILinkedList();
	int size();
	void printList();
};

#endif /* ILINKEDLIST_H_ */
