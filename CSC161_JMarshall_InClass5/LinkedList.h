#pragma once
#include <string>
#include <iostream>
#include <fstream>


using std::cout;
using std::endl;
using std::ofstream;
using std::ifstream;


template<class T>
struct node {
	T Data;
	node* next;
};
template<class T>
class LinkedList
{
protected:
	node<T>* head;
	node<T>* current;

	int count;
public:
	LinkedList();//default
	LinkedList(LinkedList<T>& otherList); //constructor
	void appendNode(const T&);
	void insertNode(const T&);
	bool deleteNode(const T&);
	void destroyList();



	void const displayList(); // this is to display all elements in the node.
	bool search(const T&);// returns 
	T getTotal(); // adds up the total for the data in all the nodes
	int numNodes(); // returns the number of nodes in the list
	T getAverage(); // returns the average of all the nodes

	T getLargest();

	int getLargestPosition();
	T getSmallest();
	int getSmallestPosition();
	void SaveToFile(std::string);
	void readFromFile(std::string);
};




template<class T>
LinkedList<T>::LinkedList() // default constructor
{
	current = nullptr;
	head = nullptr;
	count = 0;
}
template<class T>
LinkedList<T>::LinkedList(LinkedList<T>& otherList) //  constructor
{
	// to be implemented
}
template<class T>
void LinkedList<T>::appendNode(const T& newItem)//  appending elements to the node
{

	node<T>* newNode;


	newNode = new node<T>;//creating new node
	newNode->Data = newItem;
	newNode->next = nullptr;
	if (current == nullptr)
	{
		head = newNode;
		current = newNode;
		count++;

	}
	else
	{
		current->next = newNode;
		current = newNode;
		count++;

	}

}





template<class T>
void LinkedList<T>::insertNode(const T& info)//  inserting  an element to the node
{
	node<T>* currentPtr;
	node<T>* trialPtr;
	node<T>* newNode;
	bool found;
	newNode = new node<T>;//creating new node
	newNode->Data = info;
	newNode->next = nullptr;
	if (head == nullptr)
	{
		head = newNode;
		current = newNode;

	}
	else
	{
		currentPtr = head;
		found = false;
		while (current != nullptr && found)
			if (currentPtr->Data >= info)
			{
				found = true;
			}
			else
			{
				trialPtr = currentPtr;
				currentPtr = currentPtr.next;


			}
		if (currentPtr == head)
		{
			newNode->next = head;
			head = newNode;
			count++;
		}
		else
		{
			trialPtr->next = newNode;
			newNode->next = currentPtr;
			count++;
			if (currentPtr == nullptr)
			{
				current = newNode;
			}
		}


	}
}


template<class T>
bool LinkedList<T>::deleteNode(const T& deleteItem) {
	node<T>* trailCurrent;
	bool found;

	if (head == nullptr)
	{
		cout << "Cannot delete from an empty list";
		return false;
	}
	else if (head->Data == deleteItem)
	{
		current = head;
		head = head->next;
		count--;
		delete current;
		return true;
	}
	else
	{
		current = head->next;
		node<T>* trailingCurrent = head;
		bool found = false;
		while (current != nullptr) {
			if (current->Data == deleteItem) {
				trailingCurrent = current->next;
				delete current;
				found = true;
				break;
			}
		}
		return found;
	}
}


template<class T>
void const LinkedList<T>::displayList() { // this is to display all elements in the node.
	current = head;
	if (current == nullptr)
	{
		cout << "You have no recorded rainfall!";
	}
	else {
		while (current != nullptr)
		{
			cout << current.Data << " ";
			current = current.next;
		}
	}
}

template<class T>
bool LinkedList<T>::search(const T& searchItem) {						// returns a bool depending on if Element is founr

	bool found = false;

	current = head;

	while (current != nullptr && !found)
		if (current->info >= searchItem)
			found = true;
		else
			current = current->next;
	if (found)
		found = (current->info == searchItem); // test for equality
	return found;
}



template<class T>
T LinkedList<T>::getTotal() {										// adds up the total for the data in all the nodes
	T sum = 0;
	current = head;
	while (current != nullptr)
	{
		sum += current->Data;
		current = current->next;
	}
	return sum;
}
template<class T>
int LinkedList<T>::numNodes() { // returns the number of nodes in the list
	return count;
}

template<class T>
T LinkedList<T>::getAverage() { // returns the average of all the nodes
	T average = getTotal() / count;
	return average;
}

template<class T>
T LinkedList<T>::getLargest() { // returns the largest node in the list
	T Largest = head->Data;
	current = head;
	while (current != nullptr)
	{
		if (Largest < current->Data)
		{
			Largest = current->Data;
		}
		current = current->next;
	}
	return Largest;
}

template<class T>
int LinkedList<T>::getLargestPosition() {// returns the largest position in the list of all the nodes
	int LargestPosition = 1;
	int position = 1;
	T Largest = head->Data;

	current = head;
	while (current != nullptr)
	{
		if (Largest < current->Data)
		{
			Largest = current->Data;
			LargestPosition = position;
		}
		current = current->next;
		position++;
	}
	return LargestPosition;
}


template<class T>
int LinkedList<T>::getSmallestPosition() {// returns the position of the smallest node
	int smallestPosition = 1;
	int position = 1;
	T smallest = head->Data;

	current = head;
	while (current != nullptr)
	{
		if (smallest > current->Data)
		{
			smallest = current->Data;
			smallestPosition = position;
		}
		current = current->next;
		position++;
	}
	return smallestPosition;
}


template<class T>
T LinkedList<T>::getSmallest() { // returns the smallest node
	T smallest = head->Data;
	current = head;
	while (current != nullptr)
	{
		if (smallest < current->Data)
		{
			smallest = current->Data;
		}
		current = current->next;
	}
	return smallest;
}

template<class T>
void LinkedList<T>::SaveToFile(std::string filePath) {
	ofstream outFile;
	outFile.open(std::string);
	current = head;
	while (current != nullptr)
	{
		outFile << current->Data << endl;
		current = current->next;
	}
	outFile.close();
}



template<class T>
void LinkedList<T>::readFromFile(std::string filePath) {
	destroyList();	// dont forget to create a destroylist 
	ifstream inFile;
	inFile.open(std::string);
	while (inFile)
	{
		T item;
		inFile >> item;
		inFile.ignore();
		insertNode(item);

	}
	displayList();
	inFile.close();
}

template<class T>
void LinkedList<T>::destroyList() {
	// pointer to delete the node
	node<T>* temp;
	while (head != nullptr)
	{
		temp = head;
		head = head->next;
		delete temp;
	}


	count = 0;
}




