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
	array[index].push_back({ key, value });
}

void Dictonary::remove(int key) {
	int index = HashingFnc(key);
	std::vector<std::pair<int, std::string>> vector = array[index];



	vector.erase(std::remove(vector.begin(), vector.end(), ), vector.end());
}

std::string Dictonary::get(int key) {
	int index = HashingFnc(key);
	std::string value;
	for (std::pair<int, std::string> element : array[index]) {
		if (element.first == key) {
			value = element.second;
		}
	}
}

void Dictonary::display() {

}