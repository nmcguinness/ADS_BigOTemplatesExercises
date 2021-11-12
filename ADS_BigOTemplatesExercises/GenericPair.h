#pragma once
#include <iostream>

/// @brief A class to pair (or create a tuple with) two data types
/// @tparam F First data type
/// @tparam S Second data type
template <typename F, typename S>
class GenericPair
{
private:
	F first;
	S second;

public:
	GenericPair(F first, S  second) : first(first), second(second) {}
	~GenericPair() {}

	//remember that use of "friend" breaks encapsulation i.e. makes all fields public for this method
	friend std::ostream& operator<<(std::ostream& os, const GenericPair& other)
	{
		os << other.first << "," << other.second;
		return os;
	}
};
