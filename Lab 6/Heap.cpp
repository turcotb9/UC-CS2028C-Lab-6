#include "Heap.h"
#include "iostream"

int Heap::HashingFnc(int key) {
	return (key % 10);
}

void Heap::insert(int val) {
	int index = HashingFnc(val);
	Heap[index].insert_back(val);

}

void Heap::remove(int val) {
	int index = HashingFnc(val);
	Heap[index].delete_val(val); //Temporary, need to make new linked list function.
}

bool Heap::contains(int val) {
	int index = HashingFnc(val);
	if (Heap[index].contains(val)) {
		std::cout << "List contains " << val << ".\n";
		return true;
	}
	else {
		std::cout << "List does not contain " << val << ".\n";
		return false;
	}
}

void Heap::display() {
	for (int i = 0; i < 10; i++) {
		std::cout << i << " : ";
		Heap[i].display();
		std::cout << "\n";
	}
}