#pragma once

#include"Nodo.h"



template<class T>
class LinkedList {
private:
	Nodo<T>* head;

public:
	Nodo<T>* begin();
	void insert(T*);
	LinkedList();
};

template<class T>
LinkedList<T>::LinkedList() {
	head = NULL;
}


template<class T>
Nodo<T>* LinkedList<T>::begin() {
	return head;
}

template<class T>
void LinkedList<T>::insert(T* newData) {
	Nodo<T>* newNode = new Nodo<T>(*newData);
	
	newNode->left = NULL;
	newNode->right = head;
	if (head != NULL) {
		head->left = newNode;
	}
		
	head = newNode;
}
