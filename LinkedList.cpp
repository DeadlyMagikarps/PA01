// Program Information //////////////////////////////////////////////////////////
/**
 * @file LinkedList.cpp
 *
 * @brief Implementation file for Linked List
 *
 * @details Implements all functions and methods defined by the Linked List class
 *
 * @version 1.01
 *          Hadi Rumjahn (18 September 2016)
 *          Adapted code Frank M. Carrano and Timothy M. Henry
 *
 *          Frank M. Carrano and Timothy M. Henry
 *          Copyright (2017) Retrieved from Reference 9-2
 */

// Pre compiler directives /////////////////////////////////////////////////////
#ifndef LINKED_LIST_CPP
#define LINKED_LIST_CPP

// Header Files ////////////////////////////////////////////////////////////////
#include "PrecondViolatedExcep.h"
#include "LinkedList.h"
#include <cassert>

// Class/Data Structure member implementations /////////////////////////////////
/**
  * @brief Linked List default constructor
  *
  * @details Creates and initializes a headptr and a default item count
  *
  * @pre Unintialized LinkedList
  *
  * @post Initialized LinkedList with a null headptr and 0 itemcount
  *
  * @par Algorithm
  *     Initializes node with the initializers
  *
  * @return none
  *
  */
template<class ItemType>
LinkedList<ItemType> :: LinkedList()
	: headPtr(nullptr), itemCount(0)
{
}

/**
 * @brief Linked list copy constructor
 *
 * @details Copies and existing list object
 *
 * @pre Assumes an object of some sort has already been created
 *
 * @post Creates a copy of the list object
 *
 * @par Algorithm
 *      Checks if the original list is empty. Otherwise,
 *      it copies the head ptr and starts traversing the list until all
 *      items in the list is copied.
 *
 * @exception if the list is empty, it just copies the nullptr
 *
 * @param[in] otherList is the list to be copied from
 *
 * @return none
 *
 */
template<class ItemType>
LinkedList<ItemType> :: LinkedList(const LinkedList<ItemType>& otherList)
   //: headPtr(otherList.headPtr), itemCount(otherList.itemCount)
{
	//itemCount = otherList.itemCount;
	Node<ItemType>* origChainPtr = otherList.headPtr;

	if( origChainPtr == nullptr )
	{
		headPtr = nullptr; // original list is empty
	}

	else
	{
		// copy first node
		headPtr = new Node<ItemType>();
		headPtr->setItem(origChainPtr->getItem());

		// copy remaining nodes
		Node<ItemType>* newChainPtr = headPtr;
		origChainPtr = origChainPtr->getNext();

		while (origChainPtr != nullptr)
		{
			// get next item
			ItemType nextItem = origChainPtr->getItem();

			// create new node with that data
			Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);

			// link the nodes
			newChainPtr->setNext(newNodePtr);

			// move pointers
			newChainPtr = newChainPtr->getNext();
			origChainPtr = origChainPtr->getNext();

		} // end while

		// end of list
		newChainPtr->setNext(nullptr);
	}
}

/**
 * @brief Checks if the list is empty
 *
 * @details Uses the itemCount to determine if the list is empty
 *
 * @pre assumes some kind of size
 *
 * @post determines if the itemCount is 0 or not
 *
 * @par none
 *
 * @return a boolean for successful operation
 *
 */
// functions for the list
template<class ItemType>
bool LinkedList<ItemType> :: isEmpty() const
{
	return itemCount == 0;
}

/**
 * @brief Gets the length of the List using its item count
 *
 * @details none
 *
 * @pre assumes some length
 *
 * @post determines the number of items in the list
 *
 * @par none
 *
 * @return itemCount as an int; the number of items in the list
 *
 */
template<class ItemType>
int LinkedList<ItemType> :: getLength() const
{
	return itemCount;
}

/**
 * @brief Inserts a new node at some position with some data in the linked list
 *
 * @details Determines the location of where an item will be inserted within the bounds
 *          of the defined boolean ableToInsert
 *
 * @pre Assumes no nodes have been created or existing nodes exist
 *
 * @post Creates a new node of such data to be inserted at x position
 *
 * @par Algorithm
 *      Checks if the list is empty; will insert at the head of the list; 
 *      Checks for position to place node in and keeps track of any previous
 *      nodes in the list to insert that data correctly
 *
 * @exception none
 *
 * @param[in] newPosition is where the node will be inserted in this list
 *
 * @param[in] newEntry of type ItemType which is templated. Defines whatever
 *            item to be inserted into the list
 *
 * @param[out] newEntry is also pass by reference so the data can be passed
 *             to other functions as needed
 *
 * @return a boolean logic if the insertion could be done or not
 *
 * @note Uses other member functions from the LinkedList header to complete the task
 *
 */
template<class ItemType>
bool LinkedList<ItemType> :: insert(int newPosition, const ItemType& newEntry)
{
	bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);

	if (ableToInsert)
	{
		//cout << "Inserting node to store data..." << endl;
		// create new node and store new data in it
		Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);
		//cout << "Node created with the data: " << newEntry << endl;

		// attach new node
		if (newPosition == 1)
		{
			// insert node at beginning
			newNodePtr->setNext(headPtr);
			headPtr = newNodePtr;
			//cout << "Inserted at beginning of list!" << endl;
		}

		else
		{
			// find the node that will be before the new node
			Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);
			//cout << "Finding node previous at position..." << endl;

			// insert new node after not to which previous pointer pointed to
			newNodePtr->setNext(prevPtr->getNext());
			prevPtr->setNext(newNodePtr);
			//cout << "Data inserted at position: " << newPosition << " with data: " << newEntry << endl;
		}

		// increase size
		itemCount++;
	}

	return ableToInsert;
}

/**
 * @brief Removes a node from the list and deletes it
 *
 * @details This method will reconnect nodes if a node was deleted in 
 *          some x position given by the user.
 *
 * @pre Assumes some data can be removed with given position
 *
 * @post deletes the pointer and the data at the given position. Reconnects nodes if needed
 *
 * @par Algorithm
 *      Removes the data starting at the head which is position 1
 *      Otherwise, checks what position to remove and reconnects nods as needed
 *
 * @exception none
 *
 * @param[in] position is where the node will be deleted from in the "Array"
 *
 * @return A booleon for successful removal or not
 *
 * @note none
 *
 */
template<class ItemType>
bool LinkedList<ItemType> :: remove(int position)
{
	bool ableToRemove = (position >= 1) && (position <= itemCount);
	
	if (ableToRemove)
	{
		Node<ItemType>* currentPtr = nullptr;

		if (position == 1)
		{
			// remove the first node
			currentPtr = headPtr;
			headPtr = headPtr->getNext();
			//cout << "Removed data at head!" << endl;
		}

		else
		{
			// find node that is before the one to remove
			Node<ItemType>* prevPtr = getNodeAt(position - 1);

			// point at the node to remove
			currentPtr = prevPtr->getNext();

			// Disconnect and reconnect the prior node with the one after
			prevPtr->setNext(currentPtr->getNext());

			//cout << "Removed data somewhere..." << endl;
		}

		// Return node
		//currentPtr->setNext(nullptr);
		delete currentPtr;
		currentPtr = nullptr;
      //headPtr->setNext(headPtr->getNext());

		// decrease item count
		itemCount--;
		//cout << itemCount << endl;
	}

	return ableToRemove;
}

/**
 * @brief Clears the list by deleting the node
 *
 * @details none
 *
 * @pre Assumes a non empty list
 *
 * @post resets the list to zero
 *
 * @par Algorithm
 *      While the list is not empty, remove from the head of the list
 *
 * @return none
 *
 */
template<class ItemType>
void LinkedList<ItemType> ::clear()
{
	while (!isEmpty())
	{
		remove(1);
	}
	//cout << "List has been cleared!" << endl;
}

/**
 * @brief Gets the entry at some position entered by user
 *
 * @details uses an exception if the position is not in the list
 *
 * @pre A given position from the user is entered and attempts to retrieve data
 *
 * @post Returns the data back to the user or throws and exception for logic_error
 *
 * @par Algorithm
 *      If the items is within bounds, return that node
 *      otherwise, throw an exception for invalid position
 *
 * @exception PrecondViolatedExcep handles logic error provided by its class
 *            This exception will execute if the entered position is outside the list
 *
 * @param[in] position is where the method will attempt to retrieve the data
 *
 * @return uses the method getItem() to retrieve the data from where the pointer 
 *         is pointing to.
 *
 * @note uses exception handling from the class PrecondViolatedExcep.h
 *
 */
template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const throw(PrecondViolatedExcept)
{
	bool ableToGet = (position >= 1) && (position <= itemCount);
	if (ableToGet)
	{
		Node<ItemType>* nodePtr = getNodeAt(position);
		return nodePtr->getItem();
	}

	else
	{
		std::string message = "getEntry() called with an empty list or ";
		message = message + "invalid position.";
		throw(PrecondViolatedExcept(message));

	}
}

/**
 * @brief Replaces old data with new data at the given position and given new data
 *
 * @details May throw an exception error if out of bounds
 *
 * @pre Assumes some data exists in the list
 *
 * @post Indicate a successful replacement at the given position with some new item
 *
 * @par Algorithm
 *      Gets the node at the position and replaces that entry with the new entry
 *      If that fails, this method will throw an exception for invalid position
 *
 * @exception PrecondViolatedExcep will hand logic errors if the position given
 *            is out of bounds
 *
 * @param[in] position is the location in the list for where the item is to be replaced
 *
 * @param[in] newEntry is the item to be replaced
 *
 * @param[out] newEntry is pass by referranced so the data can be used later such as
 *             outputting to console or terminal
 *
 * @return the item that was replaced (templated)
 *
 * @note uses the the class PrecondViolatedExcep.h for logic errors
 *
 */
template<class ItemType>
ItemType LinkedList<ItemType> :: replace(int position, const ItemType& newEntry) throw(PrecondViolatedExcept)
{
	// precondition
	bool ableToSet = (position >= 1) && (position <= itemCount);
	if (ableToSet)
	{
		// Acquire node at the position given, set the item with new entry, and return the old entry out (the new entry now)
		Node<ItemType>* oldEntry = getNodeAt(position);
		oldEntry->setItem(newEntry);
		return oldEntry->getItem();

		//cout << "Data replace with: " << newEntry << " at position: " << position << endl;
	}

	else
	{
		std::string message = "replace() called with an empty list or ";
		message = message + "invalid position.";
		throw(PrecondViolatedExcept(message));
	}
}

/**
 * @brief Gets the node at the given position
 *
 * @details none
 *
 * @pre Assumes that such position exists
 *
 * @post retrieves the pointer to where that node is
 *
 * @par Algorithm
 *      Loops to where the position is and returns a pointer to 
 *      that node at that position
 *
 * @exception none
 *
 * @param[in] position is where the node is at
 *
 * @return a pointer to the node
 *
 * @note uses the header cassert for debugging purposes
 *
 */
template<class ItemType>
Node<ItemType>* LinkedList<ItemType> :: getNodeAt(int position) const
{
	int count;

	// Debuggin check of precondition
	assert((position >= 1) && (position <= itemCount));

	// Loop from beginning of chain
	Node<ItemType>* current = headPtr;

	for (count = 1; count < position; count++)
	{
		current = current->getNext();
	}

	return current;
}

/**
 * @brief Destructor for the Linked List class
 *
 * @details Deletes all data when it is out of scope
 *
 * @pre Assumes some data exists
 *
 * @post All objects are deallocated and reset
 *
 * @par Algorithm
 *      Uses the function clear() to delete data
 *
 * @return none
 *
 */
template<class ItemType>
LinkedList<ItemType> :: ~LinkedList()
{
	clear();
}

#endif // end LINKED_LIST_CPP
