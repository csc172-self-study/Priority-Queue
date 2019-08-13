/*
 * MaxHeap.h
 *
 *  Created on: Jul 15, 2019
 *      Author: alex
 */

#ifndef MAXHEAP_H_
#define MAXHEAP_H_

#include "ArrayOperations.h"
#include <stddef.h>

template <typename E>
class MaxHeap {
private:
	E* heap;
	int maxSize;
	int size;

	void siftDown(int pos) {
		while (!isLeaf(pos)) {
			int greaterChild = leftChild(pos); int otherChild = rightChild(pos);
			if ((otherChild < size) && heap[otherChild] > heap[greaterChild]) {
				greaterChild = otherChild;
			}
			if (heap[pos] > heap[greaterChild]) {
				return;
			}
			swap(heap,pos,greaterChild);
			pos = greaterChild;
		}
	}

	void siftUp(int pos) {
		while (pos != 0 && heap[pos] > heap[parent(pos)]) {
			swap(heap, pos, parent(pos));
			pos = parent(pos);
		}
	}

public:
	MaxHeap(E* h = nullptr, int num = NULL, int max = NULL) {
		heap = h;
		size = num;
		maxSize = max;
		buildHeap();
	}

	~MaxHeap() {}

	int getSize() {
		return size;
	}

	bool isLeaf(int pos) {
		return (pos >= size/2) && (pos < size);
	}

	int leftChild(int pos) {
		return 2*pos + 1;
	}

	int rightChild(int pos) {
		return 2*pos + 2;
	}

	int parent(int pos) {
		return (pos-1)/2;
	}

	void buildHeap() {
		for (int i = size/2-1; i >= 0; --i) {
			siftDown(i);
		}
	}

	void insert(const E& element) {
		if (size >= maxSize) throw "Heap is full.";
		int curPos = size++;
		heap[curPos] = element;
		siftUp(curPos);
	}

	E removeFirst() {
		if (size <= 0) throw "Heap is empty.";
		swap(heap, 0, --size);
		if (size != 0) siftDown(0);
		return heap[size];
	}

	E remove(int pos) {
		if (pos < 0 || pos > size) throw "Position out of range.";
		if (pos == size-1) {
			size--;
		} else {
			swap(heap, pos, --size);
			siftUp(pos);
			if (size !=0) {
				siftDown(pos);
			}
		}
		return heap[size];
	}

	int find(const E& element) {
		for (int i = 0; i < size; ++i) {
			if (element == heap[i]) {
				return i;
			}
		}
		return -1;
	}
};

#endif /* MAXHEAP_H_ */
