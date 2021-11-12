#pragma once
#include <iostream>
using namespace std;

template <typename E>
class GenericArray {
private:
	E* pArray;
	E defaultValue;
	int length;

public:
#pragma region Constructors, Initialization & Deletion
	GenericArray(int length, E defaultValue) {
		if (length <= 0)
			throw std::invalid_argument("Index length - must be greater than zero!");

		//set fields
		this->pArray = new E[length];
		this->length = length;
		this->defaultValue = defaultValue;

		//initialize array defaults
		initialize();
	}

	~GenericArray() {
		//release allocated memory
		delete[] pArray;

		//reset fields
		this->length = 0;

		//nullify any pointers
		pArray = nullptr;
	}

	void initialize() {
		for (int i = 0; i < this->length; i++) {
			pArray[i] = defaultValue;
		}
	}

#pragma endregion

#pragma region Core
	void print() const {
		for (int i = 0; i < this->length; i++) {
			cout << pArray[i] << endl;
		}
	}

	int size() const {
		return this->length;
	}

	void clear() {
		//TODO - do same thing as in destructor?
	}

	E get(int index) const {
		if (index >= 0 && index < this->length)
			return this->pArray[index];
		else
			throw std::invalid_argument("Index is invalid!");
		//return this->defaultValue; //TODO - better to throw an exception
	}

	bool add(E data, int index) {
		if (index >= 0 && index < this->length) {
			this->pArray[index] = data;
			return true;
		}
		return false;
	}

	bool remove(int index) {
		if (index >= 0 && index < this->length) {
			this->pArray[index] = defaultValue; //[1,2,3,4,5] and remove(2) then [1,2,-1,4,5]
			return true;
		}
		return false;
	}

#pragma endregion
};
