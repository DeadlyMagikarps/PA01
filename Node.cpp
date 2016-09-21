// Program Information /////////////////////////////////////////////////////
/**
 * @file Node.cpp
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
 *          Copyright (2017) Retrieved from Reference 4-2
 */

// Pre compiler directives ///////////////////////////////////////////////////
#ifndef NODE_CPP
#define NODE_CPP

// Header Files //////////////////////////////////////////////////////////////
#include "Node.h"

/**
 * @brief Default node constructor with the next pointer set to null
 *
 * @details none
 *
 * @pre none
 *
 * @post Creates a node with the bare minimum defaults, sets next pointer
 *
 * @par Algorithm
 *      Sets the next private member function to nullptr
 *
 * @return none
 *
 */
template<class ItemType>
Node<ItemType> :: Node() : next(nullptr)
{
}

/**
 * @brief Parameterized constructor for a Node
 *
 * @details Constructs a node with some data given by user
 *
 * @pre none
 *
 * @post Creates a node with user given data
 *
 * @par Algorithm
 *      Initializes all private data members of the node class
 *
 * @param[in] data the data to be entered
 *
 * @return none
 *
 */
template<class ItemType>
Node<ItemType> :: Node(const ItemType& data)
	: item(data), next(nullptr)
{
}

/**
 * @brief Paramterized constructor for a node
 *
 * @details User given data and a pointer to the next node or end of list
 *
 * @pre none
 *
 * @post Constructs a node with user given data and a pointer to the next node
 *
 * @par Algorithm
 *      Initializes all private data members of the class
 * 
 * @param[in] data is the user given data to be contained in the node
 *
 * @param[in] nextNodePtr is the pointer to whatever node is next
 *            could be the next node or null
 *
 * @return none
 *
 */
template<class ItemType>
Node<ItemType> :: Node(const ItemType& data, Node<ItemType>* nextNodePtr)
	: item(data), next(nextNodePtr)
{
}

/**
 * @brief Sets data to item
 *
 * @details none
 *
 * @pre none
 *
 * @post data is assigned to item
 *
 * @par none
 *
 * @param[in] data is what is to be assigned to item
 *
 * @return none
 *
 */
template<class ItemType>
void Node<ItemType> :: setItem(const ItemType& data)
{
	item = data;
}

/**
 * @brief Sets the next node pointer
 *
 * @details none
 *
 * @pre none
 *
 * @post Assigns nextNodePtr to the next pointer
 *
 * @par none
 *
 * @param[in] nextNodePtr is the pointer to be assigned to next from the class
 *
 * @return none
 *
 */
template<class ItemType>
void Node<ItemType> :: setNext(Node<ItemType>* nextNodePtr)
{
	next = nextNodePtr;
}

/**
 * @brief Gets the items from the node
 *
 * @details none
 *
 * @pre none
 *
 * @post returns the item at the node
 *
 * @par none
 *
 * @return the item 
 *
 */
template<class ItemType>
ItemType Node<ItemType> :: getItem() const
{
	return item;
}

/**
  * @brief Gets the next node pointer
  *
  * @details none
  *
  * @pre none
  *
  * @post returns the pointer next
  *
  * @par none
  *
  * @return the private member next
  *
  */
template<class ItemType>
Node<ItemType>* Node<ItemType> :: getNext() const
{
	return next;
}

#endif // end NODE_CPP
