//****************************************************************************************************
//
//      File:                LLDriver.cpp
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
//		    1.    Node.h - Contains the Node structure
//			2.	  LinkedList.h - Contains the linkedList class
//
//****************************************************************************************************

#include <iostream>
#include "Node.h"
#include "LinkedList.h"

//****************************************************************************************************

using namespace std;

//****************************************************************************************************

int main()
{
	LinkedList<int> myList;
	bool successful;
	int temp;

	myList.insert(1);
	myList.insert(1);
	myList.insert(1);
	myList.insert(2);
	myList.insert(3);
	myList.insert(4);
	myList.insert(5);
	myList.insert(6);
	myList.insert(7);

	if (!(myList.display())) 
	{
		cout << "There has been an error displaying the list!" << endl;
	}

	if (myList.insert(3)) 
	{
		cout << "After inserting 3: ";

		if (!(myList.display()))
		{
			cout << "There has been an error displaying the list!" << endl;
		}
	}
	else 
	{
		cout << endl << "There has been an error in inserting the item." << endl;
	}

	temp = 4;

	if (myList.remove(temp)) {
		cout << "After removing 4: ";

		if (!(myList.display()))
		{
			cout << "There has been an error displaying the list!" << endl;
		}
	}
	else 
	{
		cout << "There has been an error in removing the item." << endl;
	}

	if (myList.viewFront(temp)) 
	{
		cout << "Front value: " << temp << endl;
	}
	else 
	{
		cout << "There has been an error in removing the item." << endl;
	}

	if (myList.viewBack(temp)) 
	{
		cout << "Last value: " << temp << endl;
	}
	else 
	{
		cout << "There has been an error in removing the item." << endl;
	}

	cout << "Currently has " << myList.getSize() << " nodes" << endl;
	cout << "Attempting to retrieve 10: " << endl;


	if (myList.insertBack(4)) 
	{
		cout << "Insertion successful" << endl;
	}
	else 
	{
		cout << "There has been an error" << endl;
	}

	if (!(myList.display()))
	{
		cout << "There has been an error displaying the list!" << endl;
	}











	temp = 10;

	if (myList.retrieve(temp)) 
	{
		cout << "Found: " << temp << endl;
	}
	else 
	{
		cout << "Not found." << endl;
	}

	cout << "Attempting to retrieve 3: " << endl;
	temp = 3;

	if (myList.retrieve(temp)) 
	{
		cout << "Found: " << temp << endl;
	}
	else 
	{
		cout << "Not found." << endl;
	}

	if (myList.clearList()) 
	{
		cout << "After calling clearList() " << myList.getSize() << " items remaining." << endl;
	}
	else 
	{
		cout << "There was an error clearning the list." << endl;
	}



}

//****************************************************************************************************

/*
1 1 1 2 3 4 5 6 7
After inserting 3: 1 1 1 2 3 3 4 5 6 7
After removing 4: 1 1 1 2 3 3 5 6 7
Front value: 1
Last value: 7
Currently has 9 nodes
Attempting to retrieve 10:
Not found.
Attempting to retrieve 3:
Found: 3
After calling clearList() 0 items remaining.
*/