#pragma once

//templates - exercise 5
template <class E>
class ADS_Array {
private:
	E* pData = nullptr;
	int length = 0;
	E defaultValue;

	void initialize(E defaultValue) {
		for (int i = 0; i < this->length; i++)
			this->pData[i] = defaultValue;
	}

public:
	ADS_Array(int length, E defaultValue) {
		this->pData = new E[length];
		this->length = length;
		this->defaultValue = defaultValue;

		//sets the contents to the default
		initialize(defaultValue);
	}

	void print() const {
		for (int i = 0; i < this->length; i++) {
			cout << pData[i] << endl;
		}
	}

	int size() const { return this->length; }

	E get(int index) const {
		if (index >= 0 && index < this->length)
			return this->pData[index];
		else
			return this->defaultValue; //"", 0, false, default(E)
	}

	bool add(E data, int index) {
		if (index >= 0 && index < this->length) {
			this->pData[index] = data;
			return true;
		}
		return false;
	}

	//pushes new data onto the end of the array and grows the array by 50%
	//[1,2,3,4] and we add 5 then [1,2,3,4,5,0]
	bool push(E data) {
		return false;
	}
};