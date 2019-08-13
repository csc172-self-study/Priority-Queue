/*
 * PriorityQueue.cpp
 *
 *  Created on: Jul 15, 2019
 *      Author: alex
 */

#include "PriorityQueue.h"

void PriorityQueue::enqueue(Object obj) {
	objects.insert(obj);
}

int PriorityQueue::dequeue() {
	Object toRemove = objects.removeFirst();
	return toRemove.getID();
}

void PriorityQueue::changeWeight(Object obj) {
	int objPos = objects.find(obj);
	objects.remove(objPos);
	objects.insert(obj);
}
