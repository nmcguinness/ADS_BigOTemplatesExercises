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
			if (pData[i] == this->defaultValue)
				cout << "empty" << endl;
			else
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

	bool remove(int index) {
		if (index >= 0 && index < this->length) {
			this->pData[index] = defaultValue; //[1,2,3,4,5] and remove(2) then [1,2,-1,4,5]
			return true;
		}
		return false;
	}

	//pushes new data onto the end of the array and grows the array by 50%
	//[1,2,3,4] and we add 5 then [1,2,3,4,5,6]

	//[1,-1,3,4,5]
	//[1,2,3,-1,-1]

	bool push(E data) {
		//what is the best method of implementation?

		return false;
	}
};
