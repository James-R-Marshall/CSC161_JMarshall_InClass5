#pragma once
#include <algorithm>
#include "LinkedList.h"

using namespace std;
template <class T>
void bubbleSort(T list[], int size)
{
	int maxElement;
	int index;

	for (maxElement = size - 1; maxElement> 0; maxElement--)
	{
		for (index = 0; index < maxElement; index++)
		{
			if (list[index] > list[index + 1]) 
			{
				swap(list[index], list[index + 1]);
			}
		}
	}
}

template <class T>
void selectionSort(T list[], int size)
{
	int minIndex, minValue;


	for (int start = 0; start < (size-1); start++)
	{
		minIndex = start;
		minValue = list[start];

		for (int index = start + 1; index < size; index++)
		{
			if (list[index] < minValue)
			{
				minValue = list[index];
				minIndex = index;
			}
		}
		swap(list[minIndex], list[start]);
	}

}

template <class T>
node<T>* 