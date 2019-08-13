/*
 * PriorityQueue.h
 *
 *  Created on: Jul 15, 2019
 *      Author: alex
 */

#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

#include "Object.h"
#include "MaxHeap.h"

class PriorityQueue {
private:
	MaxHeap<Object> objects;

public:
	void enqueue(Object obj);
	int dequeue();
	void changeWeight(Object obj);
};



#endif /* PRIORITYQUEUE_H_ */
