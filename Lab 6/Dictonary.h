#pragma once
#include <iostream>
#include <vector>
#include <utility>
class Dictonary {
private:
	std::vector<std::pair<int, std::string>> array[10];

	int HashingFnc(int key);
public:
	void put(int key, std::string value);

	void remove(int key);

	std::string get(int key);

	void display();

};

