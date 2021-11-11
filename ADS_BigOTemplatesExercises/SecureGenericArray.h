#pragma once
#include "GenericArray.h"

template <typename E>
class SecureGenericArray : public GenericArray<E>
{
private:
	static const int SECURE_DELETE_COUNT = 7;

	void secureOverwrite(int repeat) {
		srand(time(NULL));
		for (int j = 0; j < repeat; j++) {
			for (int i = 0; i < this->length; i++) {
				pArray[i] = rand();  //BUG - when we make type T?
			}
		}
	}

public:

	~SecureGenericArray() {
		//"securely" delete contents
		secureOverwrite(7);  //TODO - replace with static

		//release allocated memory
		delete[] pArray;

		//reset fields
		this->length = 0;

		//nullify any pointers
		pArray = nullptr;
	}
};
