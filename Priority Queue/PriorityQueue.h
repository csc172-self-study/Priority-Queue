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
	// Constructor passes everything to MaxHeap constructor
	PriorityQueue(Object objs[], int curSize, int maxSize);

	int getSize(); // Get size of queue
	void enqueue(Object obj); // Add object to queue
	int dequeue(); // Remove object with highest priority
	void changeWeight(int ID, int newWeight); // Change weight of existing object
};

#endif /* PRIORITYQUEUE_H_ */
