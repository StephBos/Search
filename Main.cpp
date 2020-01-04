/********************************************************************************************
**	Project: Search
**  Programmer: Stephen Bos
**  Course:		cs2420
**	Section:	002
**	Assignment: 4
**	Data:		February 1, 2018
**
**	I certify that I wrote all code in this project except that which was
**	provided by the instructor.
**
***********************************************************************************************/

#include <iostream>
#include "Search.h"
#include "Timer.h"

using namespace std;

int main()
{
	Timer ti;
	int searchValue;

	int beginning = 13;
	int middle = 128;
	int end = 188;

	Search* search = new Search(100);
	//Search* search = new Search(Search::);

	search->SetSeed(12345);
	//search->InitUnsortedArray();
	cout << "Creating a sorted array of " << search->GetSize() << endl;
	search->InitSortedArray();
	cout << "Finished creating a sorted array of " << search->GetSize() << endl << endl;

	// tests helper function
	//cout << *search << endl << endl;

	cout << "Searching for a number at the beginning of the list." << endl;
	// search for number at the begining of the list
	ti.Start();
	search->SequentialSearch(beginning);
	ti.End();
	cout << "search->SequentialSearch() returned " << search->SequentialSearch(beginning) << " in " << ti.DurationInNanoSeconds() << "ns" << endl;

	ti.Start();
	search->RecursiveBinarySearch(beginning);
	ti.End();
	cout << "search->RecursiveBinarySearch() returned " << search->RecursiveBinarySearch(beginning) << " in " << ti.DurationInNanoSeconds() << "ns" << endl;

	ti.Start();
	search->IterativeBinarySearch(beginning);
	ti.End();
	cout << "search->IterativeBinarySearch() returned " << search->IterativeBinarySearch(beginning) << " in " << ti.DurationInNanoSeconds() << "ns" << endl << endl;

	cout << "Searching for a number in the middle of the list" << endl;
	// search for number in the middle of the list
	ti.Start();
	search->SequentialSearch(middle);
	ti.End();
	cout << "search->SequentialSearch() returned " << search->SequentialSearch(middle) << " in " << ti.DurationInNanoSeconds() << "ns" << endl;

	ti.Start();
	search->RecursiveBinarySearch(middle);
	ti.End();
	cout << "search->RecursiveBinarySearch() returned " << search->RecursiveBinarySearch(middle) << " in " << ti.DurationInNanoSeconds() << "ns" << endl;

	ti.Start();
	search->IterativeBinarySearch(middle);
	ti.End();
	cout << "search->IterativeBinarySearch() returned " << search->IterativeBinarySearch(middle) << " in " << ti.DurationInNanoSeconds() << "ns" << endl << endl;

	cout << "Searching for a number at the end of the list" << endl;
	// search for number at the end of the list
	ti.Start();
	search->SequentialSearch(end);
	ti.End();
	cout << "search->SequentialSearch() returned " << search->SequentialSearch(end) << " in " << ti.DurationInNanoSeconds() << "ns" << endl;

	ti.Start();
	search->RecursiveBinarySearch(end);
	ti.End();
	cout << "search->RecursiveBinarySearch() returned " << search->RecursiveBinarySearch(end) << " in " << ti.DurationInNanoSeconds() << "ns" << endl;

	ti.Start();
	search->IterativeBinarySearch(end);
	ti.End();
	cout << "search->IterativeBinarySearch() returned " << search->IterativeBinarySearch(end) << " in " << ti.DurationInNanoSeconds() << "ns" << endl << endl;

	cout << "Searching for a number not in the list" << endl;
	// search for number not in the list
	ti.Start();
	search->SequentialSearch(-1);
	ti.End();
	cout << "search->SequentialSearch() returned " << search->SequentialSearch(-1) << " in " << ti.DurationInNanoSeconds() << "ns" << endl;

	ti.Start();
	search->RecursiveBinarySearch(-1);
	ti.End();
	cout << "search->RecursiveBinarySearch() returned " << search->RecursiveBinarySearch(-1) << " in " << ti.DurationInNanoSeconds() << "ns" << endl;

	ti.Start();
	search->IterativeBinarySearch(-1);
	ti.End();
	cout << "search->IterativeBinarySearch() returned " << search->IterativeBinarySearch(-1) << " in " << ti.DurationInNanoSeconds() << "ns" << endl;

	cout << "Press [Enter] key to terminate";
	getchar();
	return 0;
}