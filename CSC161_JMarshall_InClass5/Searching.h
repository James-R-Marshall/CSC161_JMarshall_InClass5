#pragma once


// sequential search (ordered and unordered lists)
template <class T>
int seqSearch(const T list[], int length, const T& item)
{
	int location = 0;
	bool found = false;

	while (location < length && !found)
	{
		if (list[location] == item)
		{
			found = true;
			break;
		}
		location++;
	}
	if (found)
	{
		return location;
	}
	else
		return -1;
}

// binary search (ordered list - divide and conquer)
template <class T>
int binarySearch(const T list[], int length, const T& item)
{
	int first	= 0;
	int last	= length - 1;
	int mid;
	bool found	= false;

	while (first <= last && !found)
	{
		mid = (first + last) / 2;
		if (list[mid] == item)
			found = true;
		else if (list[mid] > item)
			last = mid - 1;
		else
			first = mid + 1;
	}
	if (found)
		return mid;
	else
		return -1;
}