//#pragma once
//
//#include<iostream>
//#include<queue>  // cola fifo de la stl
//
//
//struct Nodo {
//	int n;
//	struct Nodo* left;
//	struct Nodo* right;
//};
//
//struct Arbol{
//private:
//	struct Nodo* root;
//
//	void recorridoOrdenPorNivel() {  // hago un wrapper para ocultar mi funcion 
//		recorridoOrdenPorNivel();
//	}
//
//public:
//
//
//	void recorridoOrdenPorNivel() { // version iterativa
//		std::queue<Nodo*> cola; // instancia de la cola
//		struct Nodo* tmp; // creo un temporal 
//		cola.push(root); // inserto la raiz de primero
//		while (!cola.empty()) {
//			tmp = cola.front(); // saco el sig nodo de la lista
//			cola.pop(); //saco el frentre de la cola
//
//
//			// guardo hijos izq y der y los inserto en la cola
//
//			if (tmp->left != nullptr) {
//				cola.push(tmp->left); // los inserto en la cola
//			}
//
//			if (tmp->right != nullptr) {
//				cola.push(tmp->right); // los inserto en la cola
//			}
//
//			std::cout << tmp->n; // visitando el nodo
//		}
//	}
//
//
//	bool estaVacio() {
//		return root == nullptr;
//	}
//	
//	void insertar(char val) {  // en este no importa en orden, inserta por niveles del arbol
//
//			// Utilizamos una Cola para almacenar los nodos en cada nivel
//			std::queue<Nodo*> cola;
//			Nodo* tmp;
//			Nodo* nuevo = new Nodo;
//			nuevo->n = val;
//			nuevo->left = nullptr;
//			nuevo->right = nullptr;
//
//			// Si el árbol está vacío, se crea el nodo y se convierte en raíz
//			if (root == nullptr) {
//				root = nuevo;
//				return; 
//			}
//
//			// Avanzamos por el subárbol izquierdo y derecho almacenando cada elemento en la cola
//			// Luego se van recuperando en orden FIFO. De esa manera, la primer posición desocupada 
//			// en un dado nivel se usa para el Nodo nuevo
//			cola.push(root); // inserto la raiz en la cola
//			//mismo procedimiento que en orden por nivel
//			while (!cola.empty()) {
//				tmp = cola.front();
//				cola.pop();
//				if (tmp->left != nullptr)
//					cola.push(tmp->left);
//				else {
//					tmp->left = nuevo; // aqui inserto el nuevo elemneto si no tuviera izq
//					return;
//				}
//				if (tmp->right != nullptr)
//					cola.push(tmp->right);
//				else {
//					tmp->right = nuevo;
//					return;
//				}
//			}
//		}
//
//
//	std:: size_t Altura(Nodo* actual) {
//		if (actual == nullptr)
//			return -1;
//
//		// Obtenemos la altura del subárbol izquierdo y derecho
//		std::size_t maxizq = Altura(actual->left);
//		std::size_t maxder = Altura(actual->right);
//
//		// Comparamos la altura de ambos subárboles y retornamos la mayor
//		if (maxizq > maxder)
//			return maxizq + 1;
//		return maxder + 1;
//	}
//	
//};