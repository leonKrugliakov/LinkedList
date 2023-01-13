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
//			2.	  LinkedList.h - Contains the linkedList class
//
//****************************************************************************************************

#ifndef NODE_H
#define NODE_H

//****************************************************************************************************

template <typename TYPE>
struct Node 
{
	TYPE data;
	Node<TYPE>* next;
	Node();
	Node(TYPE d, Node<TYPE>* n = nullptr);
};

//****************************************************************************************************

template <typename TYPE>
Node<TYPE>::Node() 
{
	data = 0;
	next = nullptr;
}

//****************************************************************************************************

template <typename TYPE>
Node<TYPE>::Node(TYPE d, Node<TYPE>* n) 
{
	data = d;
	next = n;
}

//****************************************************************************************************

#endif