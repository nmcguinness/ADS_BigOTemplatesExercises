#pragma once
class Pair
{
private:
	int first;
	int second;

public:
	Pair(int first, int second) : first(first), second(second) {}
	~Pair() {}

	friend std::ostream& operator<<(std::ostream& os, const Pair& other);
};

std::ostream& operator<<(std::ostream& os, const Pair& other)
{
	os << other.first << "," << other.second;
	return os;
}