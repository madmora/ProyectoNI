#pragma once

template<class T> 
class Nodo {
	public:
		T* data;
		Nodo<T>* left;
		Nodo<T>* right;
		Nodo<T>* parent;
		Nodo(T&);
		T* getData() const;
	};


	template<class T>
	Nodo<T>::Nodo(T& data) {
		this->data = &data;
		this->left = nullptr;
		this->right = nullptr;
		this->parent = nullptr;
	}


	template <class T>
	T* Nodo<T>::getData() const {
		return data;
	}
