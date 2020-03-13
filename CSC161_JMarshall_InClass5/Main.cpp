#include "Searching.h"
#include <iostream>
#include "Sorting.h"

using namespace std;

int main()
{
	int searchTerm;
	int location;
	// Create an array of 100 sorted numbers 
	const int SIZE = 100;
	int numArray[SIZE];

	for (int i = 0; i < SIZE; i++)
	{
		numArray[i] = i + 1;
	}

	// Obtain number to search for in the array
	cout << "Enter the number to search for in the ordered array: ";
	cin >> searchTerm;

	// Search the arrray with a sequential search 
	cout << "\nSearch the array with a sequential search..." << endl;
	location = seqSearch(numArray, SIZE, searchTerm);

	// Evaluation of sequntial search
	if (location >= 0)
	{
		cout << numArray[location] << " was found in the array via a sequential search!" << endl;
	}
	else
	{
		cout << searchTerm << " was not found in the array via a sequential search!" << endl;
	}

	location = binarySearch(numArray, SIZE, searchTerm);

	// Evaluation of binary search
	if (location >= 0)
	{
		cout << numArray[location] << " was found in the array via a binary search!" << endl;
	}
	else
	{
		cout << searchTerm << " was not found in the array via a binary search!" << endl;
	}

	// Creating an unordered array
	int numArray2[] = { 12 , 13 , 44 , 54 , 65 , 78 , 12 , 135 , 13 , 144 , 667 , 65 };
	// sort the array with a bubble sort
	cout << "\nSorting the unordered array with a bubble sort..." << endl;
	bubbleSort(numArray2, 12);
	for (int i = 0; i < 12; i++)
	{
		cout << numArray2[i] <<" ";
	}
	cout << endl;


	// Creating an unordered array
	int numArray3[] = { 12 , 13 , 44 , 54 , 65 , 78 , 12 , 135 , 13 , 144 , 667 , 65 };
	// sort the array with a selection sort
	cout << "\nSorting the unordered array with a selection sort..." << endl;
	selectionSort(numArray3, 12);
	for (int i = 0; i < 12; i++)
	{
		cout << numArray2[i] << " ";
	}
	cout << endl;



	return 0;
}