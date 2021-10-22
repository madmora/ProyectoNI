#pragma once
#include"Heap.h"

template<class T>
class PriorityQueue {
private:
	Heap<T>* heap;
	bool isMax;
public:

	PriorityQueue();
	PriorityQueue(bool);
	void enqueue(T*);
	T dequeue();
	T* top();
	void imprimir();
};

template<class T>
PriorityQueue<T>::PriorityQueue() {
	this->isMax = true;
	heap = new Heap<T>;
}

template<class T>
PriorityQueue<T>::PriorityQueue(bool isMax) {
	this->isMax = isMax;
	heap = new Heap<T>;
}
template<class T>
void PriorityQueue<T>::enqueue(T* element) {
	isMax ? heap->insertMax(element) : heap->insertMin(element);
}

template<class T>
T PriorityQueue<T>::dequeue() {
	if (heap->getRoot()) {
		T element = heap->getData();
		isMax ? heap->removeMax() : heap->removeMin();
		return element;
	}
	
	return NULL;
}

template<class T>
T* PriorityQueue<T>::top() {

}

template<class T>
void PriorityQueue<T>::imprimir() {
	heap->printPretty();
}
