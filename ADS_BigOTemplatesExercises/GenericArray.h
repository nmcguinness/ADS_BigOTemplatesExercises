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
		//TODO - check length is valid?

		//set fields
		this->pArray = new E[length];
		this->length = length;
		this->defaultValue = defaultValue;

		//initialize array defaults
		initialize();
	}

	~GenericArray() {
		//"securely" delete contents
		secureOverwrite(7);  //TODO - replace with static

		//release allocated memory
		delete[] pArray;

		//reset fields
		this->length = 0;

		//nullify any pointers
		pArray = nullptr;
	}

	void secureOverwrite(int repeat) {
		srand(time(NULL));
		for (int j = 0; j < repeat; j++) {
			for (int i = 0; i < this->length; i++) {
				pArray[i] = rand();  //BUG - when we make type T?
			}
		}
	}

	void initialize() {
		for (int i = 0; i < this->length; i++) {
			pArray[i] = defaultValue;
		}
	}

#pragma endregion

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
		if (index >= 0 && index <= this->length)
			return this->pArray[index];
		else
			throw std::invalid_argument("Index is invalid!");
		//return this->defaultValue; //TODO - better to throw an exception
	}

	/*E get(int index);
	bool add(E data, int index);
	bool remove(int index);
	bool push(E data);
	void sort();
	*/
};
