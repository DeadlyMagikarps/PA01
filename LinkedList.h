// Program Information /////////////////////////////////////////////////////
/**
 * @file LinkedList.h
 * 
 * @brief Header file for Linked List
 *
 * @details Linked List header files that inherits a ListInterface publicly
 *          for its member functions
 *
 * @version 1.01
 *          Hadi Rumjahn (18 September 2016)
 *          Adapted code Frank M. Carrano and Timothy M. Henry
 *
 *          Frank M. Carrano and Timothy M. Henry
 *          Copyright (2017) Retrieved from Reference 9-2			
 */

// Pre compiler directives ////////////////////////////////////////////////
#ifndef LINKED_LIST_H
#define LINKED_LIST_H

// Header Files ///////////////////////////////////////////////////////////
#include <iostream>
#include "ListInterface.h"
#include "Node.h"
#include "PrecondViolatedExcep.h"

// Linked List Templated Class Definition /////////////////////////////////
template<class ItemType>
class LinkedList : public ListInterface<ItemType> {
public:
	LinkedList();
	LinkedList(const LinkedList<ItemType>& otherList);
	virtual ~LinkedList();

	// functions for the list
	bool isEmpty() const;
	int getLength() const;
	bool insert(int newPosition, const ItemType& newEntry);
	bool remove(int position);
	void clear();

	// ItemType functions
	ItemType getEntry(int position) const throw(PrecondViolatedExcept);
	ItemType replace(int position, const ItemType& newEntry) throw(PrecondViolatedExcept);

private:
	Node<ItemType>* headPtr;
	int itemCount;
	Node<ItemType>* getNodeAt(int position) const;
};

#include "LinkedList.cpp"
#endif // end LINKED_LIST_H
