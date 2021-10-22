#pragma once
#include"Nodo.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <queue>
#include <algorithm>



template<class T>
class Heap {
    private:
        Nodo<T>* root;
    public:
        Heap();
        Nodo<T>* lastparent();
        void upHeapifyMax(Nodo<T>*);
        void upHeapifyMin(Nodo<T>*);
        void insertMin(T*);
        void insertMax(T*);
        void printPrettyAux(const std::string&, Nodo<T>*, bool);
        void printPretty();
        void donwHeapifyMax(Nodo<T>*);
        void donwHeapifyMin(Nodo<T>*);
        bool isEmpty();
        Nodo<T>* lastnode();
        void removeMin();
        void removeMax();
        bool compare(Nodo<T>*, Nodo<T>*);
        Nodo<T>* getRoot();
        T getData();
        
};

template <class T>
Heap<T>::Heap() {
    root = NULL;
}

template<class T>
Nodo<T>* Heap<T>::lastparent() {
    std::queue <Nodo<T>*> q;
    q.push(root);

    Nodo<T>* temp = NULL;

    while (!q.empty()) {
        temp = q.front();
        q.pop();
        if (temp->left && temp->right) {
            q.push(temp->left);
            q.push(temp->right);
        }
        else {
            break;
        }
    }
    return temp;
}


template<class T>
void Heap<T>::upHeapifyMax(Nodo<T>* temp) {
    if (temp->parent == NULL) {
        return;
    }

    if (!compare(temp->parent, temp)) {
        std::swap(temp->parent->data, temp->data);
        upHeapifyMax(temp->parent);
    }
}


template<class T>
void Heap<T>::upHeapifyMin(Nodo<T>* temp) {
    if (temp->parent == NULL) {
        return;
    }

    if (compare(temp->parent, temp)) {
        std::swap(temp->parent->data, temp->data);
        upHeapifyMin(temp->parent);
    }
}

template<class T>
void Heap<T>::insertMin(T* data) {
    Nodo<T>* newnode = new Nodo<T>(*data);

    if (root == NULL) {
        root = newnode;
        return;
    }

    Nodo<T>* lParent = lastparent();

    if (lParent->left == NULL) {
        lParent->left = newnode;
        newnode->parent = lParent;
    }
    else {
        lParent->right = newnode;
        newnode->parent = lParent;
    }
    upHeapifyMin(newnode);
}


template<class T>
void Heap<T>::insertMax(T* data) {
    Nodo<T>* newnode = new Nodo<T>(*data);

    if (root == NULL) {
        root = newnode;
        return;
    }

    Nodo<T>* lParent = lastparent();

    if (lParent->left == NULL) {
        lParent->left = newnode;
        newnode->parent = lParent;  
    }
    else {
        lParent->right = newnode;
        newnode->parent = lParent;
    }
    upHeapifyMax(newnode);
}

template<class T>
void Heap<T>::printPrettyAux(const std::string& prefix, Nodo<T>* current, bool isLeft) {
    if (current != nullptr) {
        std::cout << prefix;

        std::cout << (isLeft ? "|--" : "'--");

        T* element = new T(*(current->data));
        std::cout << element->priority << std::endl;


        printPrettyAux(prefix + (isLeft ? "|   " : "    "), current->left, true);
        printPrettyAux(prefix + (isLeft ? "|   " : "    "), current->right, false);
    }
}

template<class T>
void Heap<T>::printPretty() {
    Nodo<T>* temp = root;
    printPrettyAux("", temp, false);
}


template<class T>
void Heap<T>::donwHeapifyMin(Nodo<T>* he){
    Nodo<T>* largest = he;

    if (he->left && !compare(he->left, largest))
    {
        largest = he->left;
    }
   
    if (he->right && !compare(he->right, largest))
    {
        largest = he->right;
    }

    if (largest != he)
    {
        std::swap(largest->data, he->data);
        donwHeapifyMin(largest);
    }
}
 

template<class T>
void Heap<T>::donwHeapifyMax(Nodo<T>* he) {
    Nodo<T>* largest = he;

    if( he->left && compare(he->left, largest)) {
        largest = he->left;
    }

    if(he->right && compare(he->right, largest)) {
        largest = he->right;
    }

    if(largest != he) {
        std::swap(largest->data,he->data);
        donwHeapifyMax(largest);
    }
}

template<class T>
bool Heap<T>::isEmpty()
{
    if (root == NULL)
    {
        return true;
    }
    else
        return false;
}

template<class T>
Nodo<T>* Heap<T>::lastnode() {
    std::queue<Nodo<T>*> q;
    q.push(root);
    Nodo<T>* last = nullptr;
    while (!q.empty()) {
        last = q.front();
        q.pop();
        if (last->left) {
            q.push(last->left);
        }
        if (last->right) {
            q.push(last->right);
        }
    }

    return last;
   
}

template<class T>
void Heap<T>::removeMin() {
    if (isEmpty()) {
        return;
    }

    Nodo<T>* last = lastnode();
    if (last == root) {
        delete last;
        root = NULL;
        return;
    }

    std::swap(root->data, last->data);
    Nodo<T>* prent = last->parent;

    if (prent->left == last) {
        delete last;
        prent->left = NULL;
    }
    else {
        delete last;
        prent->right = NULL;
    }

    donwHeapifyMin(root);

}

template<class T>
void Heap<T>::removeMax() {
    if (isEmpty()) {
        return;
    }

    Nodo<T>* last = lastnode();
    if (last == root) {
        delete last;
        root = NULL;
        return;
    }

    std::swap(root->data, last->data);
    Nodo<T>* prent = last->parent;

    if (prent->left == last) {
        delete last;
        prent->left = NULL;
    }
    else {
        delete last;
        prent->right = NULL;
    }

    donwHeapifyMax(root);
}

template <class T>
bool Heap<T>::compare(Nodo<T>* obj1, Nodo<T>* obj2) {
    T elem1 = T(*(obj1->data));
    T elem2 = T(*(obj2->data));
    return elem1 > elem2;
}


template <class T>
Nodo<T>* Heap<T>::getRoot() {
    return root;
}

template <class T>
T Heap<T>::getData() {
    return root == NULL ? NULL : T(*(root->data));
}

//CrearHeap(LinkedList<T>* linkList) {
//    LinkedList<T>* ptr = linkList;
//    while (ptr != NULL) {
//        insertMax(ptr-data)
//        ptr = ptr->next;
//    }
//}