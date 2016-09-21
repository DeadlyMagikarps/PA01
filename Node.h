// Program Information ///////////////////////////
/**
 * @file Node.h
 *
 * @brief Header file for Node
 *
 * @details Node class that defines where and how the items are stored
 *          Classifies member functions to retrieve and modify data          
 *
 * @version 1.01
 *          Hadi Rumjahn (18 September 2016)
 *          Adapted code Frank M. Carrano and Timothy M. Henry
 *
 *          Original Code
 *          Frank M. Carrano and Timothy M. Henry
 *          Copyright (2017) Retrieved from Reference 4-2
 */

// Pre compiler directives ///////////////////////
#ifndef NODE_H
#define NODE_H

// Header Files

	// none

// Node class templated definition
template<class ItemType>
class Node {
public:
	Node();
	Node(const ItemType& data);
	Node(const ItemType& data, Node<ItemType>* nextNodePtr);
	void setItem(const ItemType& data);
	void setNext(Node<ItemType>* nextNodePtr);
	ItemType getItem() const;
	Node<ItemType>* getNext() const;

private:
	ItemType item;
	Node<ItemType>* next;
};

#include "Node.cpp"
#endif  // end NODE_H
