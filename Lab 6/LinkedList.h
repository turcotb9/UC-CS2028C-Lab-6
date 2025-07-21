#ifndef LINKEDLIST_H
#define LINKEDLIST_H

class Node {
private:
	int value;
	Node* next;
public:

	//Constructors
	Node();

	Node(int val);

	Node(int val, Node* n);

	//Member Functions
	void setVal(int val);

	void setNext(Node* n);

	int getValue();

	Node* getNext();
};

class LinkedList {
private:
	Node* start;
public:
	//Constructor
	LinkedList();

	//Member Functions
	void insert_front(int val);

	void insert_back(int val);

	void delete_front();

	void delete_back();

	void delete_val(int val);

	bool contains(int val);

	void display();

};

#endif
