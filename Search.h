#pragma once
#include <iostream>
#include <cassert>

using namespace std;

class Search
{
public:
	Search();
	Search(int initialArraySize);
	~Search();

	// array stuff
	void InitUnsortedArray();
	void InitSortedArray();
	int GetSize();
	int GetValue(int index);
	void SetSeed(unsigned int seed);

	// searching stuff
	bool SequentialSearch(int num);
	bool RecursiveBinarySearch(int num);
	bool IterativeBinarySearch(int num);

	// debugging stuff
	friend ostream& operator<< (ostream& out, const Search& s);

	// useful stuff
	static const int TEN_MILLION = 10000000;
	static const int HUNDRED_MILLION = 100000000;



private:
	bool RecursiveBinarySearchHelper(int num, int lowIndex, int highIndex);
	const int DEFAULT_ARRAY_SIZE = 1000;
	int *data;
	int size;
	int location;
	int topVal;
	int botVal;
};

