#pragma once
#include "LinkedList.h"
class Heap {
private:
	LinkedList Heap[10];
	int HashingFnc(int key);

public:
	void insert(int val);
	void remove(int val);
	bool contains(int val);
	void display();
};

