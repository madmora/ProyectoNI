#pragma once
#include <iostream>
#include <string>
#include <sstream>
#include "Nodo.h"
using namespace std;

template <class T>
class Iterador {
private:
    Nodo<T>* pNodo;

public:
    Iterador(Nodo<T>*);
    Iterador();
    bool existeSiguiente();
    void operator=(Nodo<T>*);
    T* siguiente();
};

template <class T>
Iterador<T>::Iterador(Nodo<T>* nodo) {
    pNodo = nodo;
}

template <class T>
Iterador<T>::Iterador() {}

template <class T>
void Iterador<T>::operator=(Nodo<T>* nodo) {
    pNodo = nodo;
}

template <class T>
bool Iterador<T>::existeSiguiente() {
    return pNodo != NULL;
}

template <class T>
T* Iterador<T>::siguiente() {
    T* info = pNodo->data;
    pNodo = pNodo->right;
    return info;
}
