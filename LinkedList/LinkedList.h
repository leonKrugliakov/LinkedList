//****************************************************************************************************
//
//      File:                Node.h
//
//      Student:             Leon Krugliakov
//
//      Assignment:          Program #3
//
//      Course Name:         Data Structures I
//
//      Course Number:       COSC 3050 - 10
//
//      Due:                 September 13, 2020
//
//
//      This program creates a linked list and implements a few functions. This program will allow
//		for the insertion, deletion, and retrieval of any value as well as the front and last
//		values in the linked list. This program also allows for the destruction and creation of 
//		new linked lists.
//
//      Other files required:
//		    1.    LLDriver.cpp - This is the driver program containing the main function
//			2.	  Node.h - Contains the Node structure
//
//****************************************************************************************************

#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include <new>
#include <string>
#include "Node.h"

//****************************************************************************************************

using namespace std;

//****************************************************************************************************

template <typename TYPE>
class LinkedList 
{
private:
	Node<TYPE>* front;
public:
	LinkedList();
	~LinkedList();
	bool insert(const TYPE& dataIn);
	bool remove(TYPE& dataOut);
	bool retrieve(TYPE& data) const;
	bool viewFront(TYPE& dataOut) const;
	bool viewBack(TYPE& dataOut) const;
	bool isEmpty() const;
	bool isFull() const;
	bool clearList();
	bool display() const;
	int getSize() const;
	bool insertBack(const TYPE& dataIn);
};
 
//****************************************************************************************************

template <typename TYPE>
LinkedList<TYPE>::LinkedList() 
{
	front = nullptr;
}

//****************************************************************************************************

template <typename TYPE>
LinkedList<TYPE>::~LinkedList() 
{
	Node<TYPE>* pTemp = front;
	while (pTemp != nullptr) 
	{
		pTemp = pTemp->next;
		delete pTemp;
	}
}

//****************************************************************************************************

template <typename TYPE>
bool LinkedList<TYPE>::insert(const TYPE& dataIn) 
{
	bool successful = false;
	Node <TYPE>* pPrev = nullptr;
	Node <TYPE>* pAfter = front;

	while (pAfter != nullptr && pAfter->data < dataIn) 
	{
		pPrev = pAfter;
		pAfter = pAfter->next;
	}

	Node<TYPE>* pNew = new(nothrow) Node<TYPE>(dataIn, pAfter);

	if (pNew != nullptr) 
	{
		if (pPrev != nullptr) 
		{
			pPrev->next = pNew;
		}
		else 
		{
			front = pNew;
		}
		successful = true;
	}

	return successful;
}

//****************************************************************************************************

template <typename TYPE>
bool LinkedList<TYPE>::insertBack(const TYPE& dataIn)
{
	bool successful = false;
	Node <TYPE>* pPrev = nullptr;
	Node <TYPE>* pAfter = front;

	while (pAfter != nullptr)
	{
		pPrev = pAfter;
		pAfter = pAfter->next;
	}

	Node<TYPE>* pNew = new(nothrow) Node<TYPE>(dataIn, nullptr);

	if (pNew != nullptr)
	{
		if (pPrev != nullptr)
		{
			pPrev->next = pNew;
		}
		else
		{
			front = pNew;
		}
		successful = true;
	}

	return successful;
}

//****************************************************************************************************

template <typename TYPE>
bool LinkedList<TYPE>::remove(TYPE& dataOut) 
{
	bool successful = false;
	Node<TYPE>* pTemp = front;
	Node<TYPE>* pPrev = nullptr;

	while (pTemp != nullptr && pTemp->data < dataOut) 
	{
		pPrev = pTemp;
		pTemp = pTemp->next;
	}

	if (pTemp != nullptr && pTemp->data == dataOut) 
	{
		dataOut = pTemp->data;

		if (pPrev != nullptr) 
		{
			pPrev->next = pTemp->next;
		}
		else 
		{
			front = pTemp->next;
		}

		delete pTemp;
		successful = true;
	}

	return successful;
}

//****************************************************************************************************

template <typename TYPE>
bool LinkedList<TYPE>::retrieve(TYPE& data) const 
{
	bool successful = false;
	Node<TYPE>* pTemp = front;
	
	while (pTemp != nullptr && pTemp->data < data) 
	{
		pTemp = pTemp->next;
	}

	if (pTemp != nullptr && pTemp->data == data) 
	{
		successful = true;
		data = pTemp->data;
	}

	return successful;
}

//****************************************************************************************************

template <typename TYPE>
bool LinkedList<TYPE>::viewFront(TYPE& dataOut) const 
{
	bool successful = false;
	Node<TYPE>* pTemp = front;

	if (pTemp != nullptr) {
		successful = true;
		dataOut = pTemp->data;
	}

	return successful;
}

//****************************************************************************************************

template <typename TYPE>
bool LinkedList<TYPE>::viewBack(TYPE& dataOut) const 
{
	bool successful = false;
	Node<TYPE>* pTemp = front;

	while (pTemp != nullptr && pTemp->next != nullptr) 
	{
		pTemp = pTemp->next;
	}

	if (pTemp != nullptr) 
	{
		dataOut = pTemp->data;
		successful = true;
	}

	return successful;
}

//****************************************************************************************************

template <typename TYPE>
bool LinkedList<TYPE>::isEmpty() const 
{
	bool empty = true;

	if (front != nullptr) 
	{
		empty = false;
	}

	return empty;
}

//****************************************************************************************************

template <typename TYPE>
bool LinkedList<TYPE>::isFull() const 
{
	bool full = true;
	Node<TYPE>* pTemp = new (nothrow) Node<TYPE>;

	if (pTemp != nullptr) 
	{
		full = false;
		delete pTemp;
	}

	return full;
}

//****************************************************************************************************

template <typename TYPE>
bool LinkedList<TYPE>::clearList()
{
	bool successful = false;
	Node<TYPE>* pTemp;

	while (front != nullptr) 
	{
		pTemp = front;
		front = front->next;
		delete pTemp;
	}

	if (front == nullptr) 
	{
		successful = true;
	}

	return successful;
}

//****************************************************************************************************

template <typename TYPE>
bool LinkedList<TYPE>::display() const 
{
	bool successful = false;
	Node<TYPE>* pTemp = front;
	string output = "";

	while (pTemp != nullptr)
	{
		output += to_string(pTemp->data) + " ";
		pTemp = pTemp->next;
	}

	if (output != "") {
		successful = true;
		cout << output << endl;
	}

	return successful;
}

//****************************************************************************************************

template <typename TYPE>
int LinkedList<TYPE>::getSize() const
{
	int size = 0;
	Node<TYPE>* pTemp = front;

	if (pTemp != nullptr) 
	{
		while (pTemp != nullptr) 
		{
			size++;
			pTemp = pTemp->next;
		}
	}

	return size;

}

//****************************************************************************************************

#endif