/*
 * PriorityQueue.cpp
 *
 *  Created on: Jul 15, 2019
 *      Author: alex
 */

#include "PriorityQueue.h"

PriorityQueue::PriorityQueue(Object objs[], int curSize, int maxSize) {
	objects = MaxHeap<Object>(objs, curSize, maxSize);
}

void PriorityQueue::enqueue(Object obj) {
	objects.insert(obj);
}

int PriorityQueue::dequeue() {
	Object toRemove = objects.removeFirst();
	return toRemove.getID();
}

void PriorityQueue::changeWeight(int ID, int newWeight) {
	// Create new object with same ID to replace old
	Object obj(ID, newWeight);
	// Find object to remove (objects match on ID) and remove it
	int objPos = objects.find(obj);
	objects.remove(objPos);
	// Insert new object
	objects.insert(obj);
}

int PriorityQueue::getSize() {
	return objects.getSize();
}
