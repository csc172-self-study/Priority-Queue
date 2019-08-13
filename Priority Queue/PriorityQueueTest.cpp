/*
 * PriorityQueueTest.cpp
 *
 * Driver to test priority queue.
 *
 *  Created on: Aug 13, 2019
 *      Author: alex
 */

#include "PriorityQueue.h"
#include <algorithm>
#include <iostream>
using std::cout;

int main() {
	// Init variables and "randomize" IDs
	const int NUM_INIT = 100;
	const int NUM_ENQUEUES = 10;
	const int MAX_OBJ_ID = 10000;

	int possibleIDs[MAX_OBJ_ID];

	for (int i = 0; i < MAX_OBJ_ID; ++i) {
		possibleIDs[i] = i;
	}
	std::random_shuffle(possibleIDs, possibleIDs + MAX_OBJ_ID);

	// Create objects to add to queue
	Object objs[MAX_OBJ_ID];
	for (int i = 0; i < NUM_INIT; ++i) {
		objs[i] = Object(possibleIDs[i], i);
	}

	// Init queue
	PriorityQueue queue1(objs, NUM_INIT, MAX_OBJ_ID);

	// Print queue with priorities
	cout << "Initial queue is:\n";
	for (int i = 0; i < NUM_INIT; ++i) {
		cout << queue1.dequeue() << ", priority " << queue1.getSize() << "\n";
	}

	// Init same queue
	PriorityQueue queue(objs, NUM_INIT, MAX_OBJ_ID);

	// Test enqueue. High priorities.
	for (int i = NUM_INIT; i < NUM_INIT + NUM_ENQUEUES; ++i) {
		Object testObj(possibleIDs[i], i);
		queue.enqueue(testObj);
		cout << "Successfully enqueued object " << testObj << "\n";
	}

	// Test dequeue. Should dequeue just-added values.
	for (int i = 0; i <= NUM_ENQUEUES; ++i) {
		cout << "Dequeued object " << queue.dequeue() << ". Should have been priority " << queue.getSize() << "\n";
	}

	// Test changeWeight. Move to top of queue.
	for (int i = NUM_INIT - NUM_ENQUEUES; i > NUM_INIT - 2*NUM_ENQUEUES; --i) {
		cout << "Changing weight of object " << possibleIDs[i] << " from " << i << " to " << i + 2*NUM_ENQUEUES << "\n";
		queue.changeWeight(possibleIDs[i], i + NUM_ENQUEUES*2);
	}

	// Check result of changeWeight
	for (int i = NUM_INIT - NUM_ENQUEUES; i > NUM_INIT - 2*NUM_ENQUEUES; --i) {
		cout << "Should now be dequeueing object " << possibleIDs[i] << ": " << queue.dequeue() << "\n";
	}
}


