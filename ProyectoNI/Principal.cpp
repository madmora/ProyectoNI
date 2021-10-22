#include"Heap.h"
#include"PriorityQueue.h"
#include"LinkedList.h"
#include"Iterator.h"


class Test {
public:
	int priority;
	int value;
	Test(int priority) {
		this->priority = priority;
		this->value = priority;
	}

	bool operator > (const Test& test) {
		return this->priority > test.priority;
	}
};


int main() {

	Heap<Test> heap;
	//PriorityQueue<Test> pQueue;
	PriorityQueue<Test> pQueue(false);


	Test* test = new Test(100);
	Test* test1 = new Test(50);
	Test* test2 = new Test(10);
	Test* test3 = new Test(90);
	Test* test4 = new Test(8);
	Test* test5 = new Test(20);
	Test* test6 = new Test(34);
	Test* test7 = new Test(2);
	Test* test8 = new Test(20);
	Test* test9 = new Test(56);
	Test* test10 = new Test(98);
	Test* test11 = new Test(41);
	Test* test12 = new Test(134);
	Test* test13 = new Test(1);

	pQueue.enqueue(test);
	/*pQueue.enqueue(test1);
	pQueue.enqueue(test2);
	pQueue.enqueue(test3);
	pQueue.enqueue(test4);
	pQueue.enqueue(test5);
	pQueue.enqueue(test6);
	pQueue.enqueue(test7);
	pQueue.enqueue(test8);
	pQueue.enqueue(test9);
	pQueue.enqueue(test10);
	pQueue.enqueue(test11);
	pQueue.enqueue(test12);
	pQueue.enqueue(test13);
	pQueue.imprimir();*/

	Test a = pQueue.dequeue();
	pQueue.imprimir();
	std::cout << a.value << std::endl;
	
	/*heap.insertMin(test);
	heap.insertMin(test1);
	heap.insertMin(test2);
	heap.insertMin(test3);
	heap.insertMin(test4);
	heap.insertMin(test5);
	heap.insertMin(test6);
	heap.insertMin(test7);
	heap.insertMin(test8);
	heap.insertMin(test9);
	heap.insertMin(test10);
	heap.insertMin(test11);
	heap.insertMin(test12);
	heap.insertMin(test13);

	heap.printPretty();
	heap.removeMin();
	heap.removeMin();
	heap.printPretty();*/

	LinkedList<Test> linkList;
	linkList.insert(test);
	linkList.insert(test1);
	linkList.insert(test2);
	linkList.insert(test3);
	linkList.insert(test4);
	linkList.insert(test5);
	linkList.insert(test6);
	Iterador<Test> ite = linkList.begin();
	while (ite.existeSiguiente())
	{
		Test* info = ite.siguiente();
		std::cout << info->value << std::endl;
	}
	return 0;
}