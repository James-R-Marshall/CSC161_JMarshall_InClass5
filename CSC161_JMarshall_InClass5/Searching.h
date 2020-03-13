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
			found == true;
		}
		location++;
	}
	if (found)
	{
		return location
	}
	else
		return -1;
}