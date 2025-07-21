#include <iostream>
#include "LinkedList.h"


Node::Node() : value(0), next(nullptr) {}

Node::Node(int val) : value(val), next(nullptr) {}

Node::Node(int val, Node* n) : value(val), next(n) {}

void Node::setVal(int val) {
	value = val;
}

void Node::setNext(Node* n) {
	next = n;
}

int Node::getValue() {
	return value;
}

Node* Node::getNext() {
	return next;
}


LinkedList::LinkedList() : start(nullptr) {}

void LinkedList::insert_front(int val) {
	Node* newNode = new Node(val, start);
	start = newNode;
}
void LinkedList::insert_back(int val) {
	Node* newNode = new Node(val);
	if (!start) {
		start = newNode;
		return;
	}
	Node* current = start;
	while (current->getNext() != nullptr) {
		current = current->getNext();
	}
	current->setNext(newNode);
}
void LinkedList::delete_front() {
	if (!start) {
		std::cout << "Object is empty\n";
		return;
	}
	Node* temp = start;
	start = start->getNext();
	delete temp;
}

void LinkedList::delete_back() {
	if (!start) {
		std::cout << "Object is empty\n";
		return;
	}
	Node* current = start;
	Node* temp = start->getNext();

	while (temp->getNext()) {
		current = temp;
		temp = temp->getNext();
	}
	current->setNext(nullptr);
	delete temp;
}

void LinkedList::delete_val(int val) {
	if (!start) {
		std::cout << "Object is empty\n";
		return;
	}
	Node* current = start;
	Node* temp = start->getNext();

	while (temp->getNext()) {
		if (temp->getValue() == val) {
			current->setNext(temp->getNext());
			delete temp;
			return;
		}
		current = temp; 
		temp = temp->getNext();
		
	}
	
}

bool LinkedList::contains(int val) {
	if (!start) {
		std::cout << "Object is empty\n";
		return;
	}
	Node* current = start;
	Node* next = start->getNext();

	while (next->getNext()) {
		if (current->getValue() == val || next->getValue() == val) {
			return true;
		}
		current = next;
		next = next->getNext();
	}
	return false;
}

void LinkedList::display() {
	Node* current = start;
	while (current) {
		std::cout << current->getValue() << " ";
		current = current->getNext();
	}
	std::cout << "\n";
}

