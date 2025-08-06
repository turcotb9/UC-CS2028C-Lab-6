#include "Dictonary.h"
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

int Dictonary::HashingFnc(int key){
	return (key % 10);
}

void Dictonary::put(int key, std::string value) {
	int index = HashingFnc(key);
	for (std::pair<int, std::string> element : array[index]) {
		//If an element already has the same key, the put in value will replace the previous value
		if (element.first == key) {
			element.second = value;
			return;
		}
	}
	//If key is not in any elements of vector, array will add new element.
	array[index].push_back({ key, value });
}

void Dictonary::remove(int key) {
	int index = HashingFnc(key);
	std::vector<std::pair<int, std::string>>& vector = array[index];
	std::string value;
	for (std::pair<int, std::string> element : array[index]) {
		if (element.first == key) {
			value = element.second;
		}
	}
	std::pair<int, std::string> pairToRemove = { key, value };
	vector.erase(std::remove(vector.begin(), vector.end(), pairToRemove), vector.end());
}

std::string Dictonary::get(int key) {
	int index = HashingFnc(key);
	std::string value = "";
	for (std::pair<int, std::string> element : array[index]) {
		if (element.first == key) {
			value = element.second;
		}
	}
	if (value == "") {
		return "-1";
	}
	else {
		return value;
	}
}

void Dictonary::display() {
	for (int i = 0; i < 10; i++) {
		std::cout << "Chain " << i << ":";
		for (auto element : array[i]) {
			std::cout << " {" << element.first << ", " << element.first << "},";
		}
		std::cout << "\n";
	}
}