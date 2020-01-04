#include <iostream>
#include <cassert>
#include <vector>

#include "Search.h"

using namespace std;

Search::Search()
{
	size = DEFAULT_ARRAY_SIZE;
	data = new int [size];
	location = size / 2;
	topVal = size;
	botVal = 0;
}

Search::Search(int initialArraySize)
{
	size = initialArraySize;
	data = new int [size];
	location = size / 2;
	topVal = size;
	botVal = 0;
}

Search::~Search()
{
	delete[] data;
}

void Search::SetSeed(unsigned int seed)
{
	//creates random set of integers in the seed specified
	srand(seed);
}


void Search::InitUnsortedArray()
{
	//for loop to create unsorted array of random ints
	for (int i = 0; i < size; i++)
	{
		//populate data array with random numbers of size to 3*size
		data[i] = (rand() % size) * 3;
	}
}

void Search::InitSortedArray()
{
	data[0] = rand() % 5;
	//for loop to create sorted array of random ints
	for (int i = 0; i < size; i++)
	{
		//Next int last int plus a random number to make each number bigger than the last.
		data[i + 1] = data[i] + rand() % 5;
	}
}

int Search::GetValue(int index)
{
	return data[index];
}


bool Search::SequentialSearch(int num)
{
	//for loop to search array one by one
	for (int i = 0; i < size; ++i)
	{
		//return true once it's found
		if (data[i] == num)
		{
			return true;
		}
	}
	//if it's not found return false
	return false;
}

bool Search::RecursiveBinarySearch(int num)
{

	if (data[location] == num)
	{
	/*	location = size / 2;
		topVal = size;
		botVal = 0;*/
		return true;
	}
	else if (data[location] < num)
	{
		location = location + 1;
		botVal = location;
		RecursiveBinarySearchHelper(num, botVal, topVal);
	}
	else if (botVal > topVal || botVal == topVal)
	{
		return false;
	}
	else
	{
		location = location - 1;
		topVal = location;
		RecursiveBinarySearchHelper(num, botVal, topVal);
	}
}

bool Search::RecursiveBinarySearchHelper(int num, int lowIndex, int highIndex)
{
	location = (highIndex + lowIndex) / 2;

	if (data[location] == num)
	{
		location = size / 2;
		topVal = size;
		botVal = 0;
		return true;
	}
	else
	{
		RecursiveBinarySearch(num);
	}
}

bool Search::IterativeBinarySearch(int num)
{
	while(location < size)
	{
		if (data[location] == num)
		{
			return true;
		}
		else if (data[location] < num)
		{
			location = location + 1;
			botVal = location;
			location = (botVal + topVal) / 2;
		}
		else if (botVal > topVal || botVal == topVal)
		{
			return false;
		}
		else 
		{
			location = location - 1;
			topVal = location;
			location = (topVal + botVal) / 2;
		}
	}	
}



int Search::GetSize()
{
	return size;
}

ostream & operator<<(ostream & out, const Search & s)
{
	// TODO: insert return statement here
	for (int i = 0; i < s.size; i++)
	{
		cout << s.data[i] << ", ";
	}
	return out;
}
