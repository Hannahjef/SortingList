// Sorted List header file
// Created by Hannah Jeffi Leo Paul -Student No:2279688 [10/28/2022]
#pragma once
#include <iostream>

using namespace std;

/// @brief
class SortedList
{
private:
   struct Node
   {
      int data;
      Node *next = nullptr;
      Node *prev = nullptr;
      /// Constructor for Node
      /// Initialises the data to 0 and next and prev to nullptr.
      Node() : data(0){};

      /// @brief Parameterized Constructor for the node
      /// @post Sets the value of the data to newEntry and next and prev to nullptr
      /// @param newEntry The entry to be added in the new node. */
      Node(const int newEntry) : data(newEntry){};
   };

private:
   Node *head;
   Node *tail;
   int sizeOfList;

public:
   /// @brief constructor creates an instance of the class
   /// by initializing the value of the head and tail to Null pointer.
   ///@return void
   SortedList();

   /// @post The destructor calls the clear() method
   /// to clear the SortedList and free the dynamically allocated memory
   ~SortedList();

   /// @brief The copy constructor performs a deep copy of the object passed by creating new Nodes
   /// @param rhs the object to be copied
   /// @post Two independent SortedList with same data but different memory location is created
   SortedList(const SortedList &rhs);

   /// @brief The move constructor destroys the rhs object and makes the new List pointed to the rhs node
   /// @param rhs The list to be moved
   /// @post rhs is destroyed
   SortedList(SortedList &&rhs);

   /// @brief The copy assignment constructor clears this list if any and performs a
   /// deep copy of the object passed by creating new Nodes.
   /// @param rhs The list to be copied
   /// @post Two independent SortedList with same data but different memory location is created
   /// @return Copied SortedList
   SortedList &operator=(const SortedList &rhs);

   /// @brief The move assignment constructor clears the this list if any and destroys the rhs object
   /// and makes the new List pointed to the rhs node
   /// @param rhs The list to be moved
   /// @post rhs is destroyed
   /// @return Moved SortedList
   SortedList &operator=(SortedList &&rhs);

   /// @brief The method inserts the item in the doubly linked list in sorted order. It performs a sorted insert.
   /// It increments the sizeOfInt variable
   /// @param item the data to be inserted
   /// @return True if successfull else False
   bool insert(int item);

   /// @brief This methods remove the item from the sortedList if the item is found
   /// @param item the Node containing the item should be removed
   /// @return True if successfull else False
   bool remove(int item);

   /// @brief The operator [] overloaded function returns the location of the item in that list
   /// @param item An entry to be found
   /// @return Returns the position of the item in the list. Returns -1 if element not found in the list.
   int operator[](int item) const;

   /// @brief The unary plus operator + overloaded function merges the two sorted list into one sorted list
   /// @param lhs object of the First List
   /// @param rhs object of the Second List
   /// @return A Merged sorted List
   friend SortedList operator+(const SortedList &lhs, const SortedList &rhs);

   /// @brief The insertion operator << overloaded function prints the SortedList in order with each element separated by a space
   /// @param os Object of the output stream
   /// @param sl Address of the sortedList
   /// @return  Object of the output stream which prints the SortedList
   friend ostream &operator<<(ostream &os, const SortedList &sl);

   /// @brief The function returns the sizeOfList variable
   /// @return sizeOfList
   int size() const;

   /// @brief The function checks if the Sorted List is empty.
   /// @return True if list is empty else false
   bool empty() const;

   /// @brief The function clears the list by deallocating the memory in the heap
   void clear();

   /// @brief This operator overloaded function checks if the two SortedList contains exactly the same value
   /// @param sl The list to be compared with
   /// @return True if two list are equal else False
   bool operator==(const SortedList &sl) const;

   /// @brief The operator overloaded function checks whether the two sorted list are not equal.
   /// @param sl The list to be compared with
   /// @return True if two list are not equal else False
   bool operator!=(const SortedList &sl) const;

   /// @brief A method to perform a deep Copy.
private:
   void copyList(const SortedList &rhs);
};
