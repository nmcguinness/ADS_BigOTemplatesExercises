#pragma once
#include "GenericArray.h"

/// @brief A "secure" version of the GenericArray that performs an overwrite of data in the desctructor
/// @tparam E
/// This is outside the scope of your examples and only included for the interested reader.
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
