// Sorted List implementation
// Created by Hannah Jeffi Leo Paul -Student No:2279688 [10/28/2022]
#include <iostream>
#include "SortedList.h"

using namespace std;

/// @brief constructor creates an instance of the class
/// by initializing the value of the head and tail to Null pointer.
///@return void
SortedList::SortedList()
{
   head = nullptr;
   tail = nullptr;
   sizeOfList = 0;
}

/// @post The destructor calls the clear() method
/// to clear the SortedList and free the dynamically allocated memory
SortedList::~SortedList()
{
   clear();
}

/// @brief The copy constructor performs a deep copy of the object passed by creating new Nodes
/// @param rhs the object to be copied
/// @post Two independent SortedList with same data but different memory location is created
SortedList::SortedList(const SortedList &rhs)
{
   sizeOfList = 0;
   head = nullptr;
   tail = nullptr;
   if (rhs.head == nullptr)
   {
      return;
   }
   copyList(rhs);
}

/// @brief The move constructor destroys the rhs object and makes the new List pointed to the rhs node
/// @param rhs The list to be moved
/// @post rhs is destroyed
SortedList ::SortedList(SortedList &&rhs)
{
   sizeOfList = rhs.sizeOfList;
   head = rhs.head;
   tail = rhs.tail;
   rhs.head = nullptr;
   rhs.tail = nullptr;
   rhs.sizeOfList = 0;
}

/// @brief The move assignment constructor clears the this list if any and destroys the rhs object
/// and makes the new List pointed to the rhs node
/// @param rhs The list to be moved
/// @post rhs is destroyed
/// @return Moved SortedList
SortedList &SortedList::operator=(SortedList &&rhs)
{
   if (this != &rhs)
   {
      clear();
      sizeOfList = rhs.sizeOfList;
      head = rhs.head;
      tail = rhs.tail;
      rhs.head = nullptr;
      rhs.tail = nullptr;
      rhs.sizeOfList = 0;
   }
   return *this;
}
/// @brief The copy assignment constructor clears this list if any and performs a
/// deep copy of the object passed by creating new Nodes.
/// @param rhs The list to be copied
/// @post Two independent SortedList with same data but different memory location is created
/// @return Copied SortedList
SortedList &SortedList::operator=(const SortedList &rhs)
{
   if (this != &rhs)
   {
      clear();
      copyList(rhs);
   }
   return *this;
}
/// @brief A method to perform a deep Copy. Invoked by copy constructor and copy assignment operator
void SortedList::copyList(const SortedList &rhs)
{
   Node *rhsPointer = rhs.head;
   Node *targetPointer = nullptr;
   // Creating the head node
   targetPointer = head = new SortedList::Node(rhsPointer->data);
   rhsPointer = rhsPointer->next;
   // Inserting the other Nodes
   while (rhsPointer != nullptr)
   {
      Node *newNode = new Node(rhsPointer->data);
      newNode->prev = targetPointer;
      targetPointer->next = newNode;
      targetPointer = targetPointer->next;
      rhsPointer = rhsPointer->next;
   }
   // Assigning tail Node to last node and copying the size;
   tail = targetPointer;
   sizeOfList = rhs.sizeOfList;
}

/// @brief The method inserts the item in the doubly linked list in sorted order. It performs a sorted insert.
/// It increments the sizeOfInt variable
/// @param item the data to be inserted
/// @return True if successfull else False
bool SortedList::insert(int item)
{
   Node *currentNode = head;
   Node *newNode = new Node(item);
   Node *lastNode = tail;
   // Inserting First Node, assigning head and tail to new node.
   if (empty())
   {
      tail = head = newNode;
      sizeOfList++;
      return true;
   }
   // Inserting the node in first position
   else if (item <= currentNode->data)
   {
      currentNode->prev = newNode;
      newNode->next = currentNode;
      head = newNode;
      sizeOfList++;
      return true;
   }
   // Insert At last
   else if (item >= lastNode->data)
   {
      newNode->prev = lastNode;
      lastNode->next = newNode;
      tail = newNode;
      sizeOfList++;
      return true;
   }
   else
   {
      // Remaining Nodes.Traverse until the node after which it has to be inserted
      while (currentNode->next != nullptr && item >= currentNode->next->data)
      {
         currentNode = currentNode->next;
      }
      newNode->next = currentNode->next;
      newNode->prev = currentNode;
      currentNode->next = newNode;
      newNode->next->prev = newNode;
      sizeOfList++;
      return true;
   }
}

/// @brief This methods remove the item from the sortedList if the item is found
/// @param item the Node containing the item should be removed
/// @return True if successfull else False
bool SortedList::remove(int item)
{
   Node *currentNode = head;
   Node *prevNode = nullptr;
   // Checking empty list
   if (empty())
   {
      return false;
   }
   // If it is the only element
   else if (head == tail && head->data == item)
   {
      currentNode = head;
      delete currentNode;
      head = tail = nullptr;
      sizeOfList--;
      return true;
   }
   // Remove last Node
   else if (tail->data == item)
   {
      currentNode = tail;
      currentNode->prev->next = nullptr;
      tail = tail->prev;
      delete currentNode;
      sizeOfList--;
      return true;
   }
   // Remove First node
   else if (head->data == item)
   {
      head = currentNode->next;
      currentNode->next->prev = nullptr;
      delete currentNode;
      sizeOfList--;
      return true;
   }
   else
   {
      // Remaning Nodes
      currentNode = currentNode->next;
      while (currentNode != nullptr && currentNode->data != item)
      {
         currentNode = currentNode->next;
      }
      if (currentNode != nullptr && currentNode->data)
      {
         currentNode->prev->next = currentNode->next;
         currentNode->next->prev = currentNode->prev;
         delete currentNode;
         sizeOfList--;
         return true;
      }
      // Item not found
      return false;
   }
}

/// @brief The function clears the list by deallocating the memory in the heap
void SortedList::clear()
{
   Node *currentNode = head;
   while (currentNode != nullptr)
   {
      head = currentNode->next;
      delete currentNode;
      currentNode = head;
   }
   // delete head;
   sizeOfList = 0;
   head = nullptr;
   tail = nullptr;
}

/// @brief The function checks if the Sorted List is empty.
/// @return True if list is empty else false
bool SortedList::empty() const
{
   if (head == nullptr)
   {
      return true;
   }
   return false;
}

/// @brief The function returns the sizeOfList variable
/// @return sizeOfList
int SortedList::size() const
{
   return sizeOfList;
}

/// @brief The insertion operator << overloaded function prints the SortedList in order with each element separated by a space
/// @param os Object of the output stream
/// @param sl Address of the sortedList
/// @return  Object of the output stream which prints the SortedList
ostream &operator<<(ostream &os, const SortedList &sl)
{
   SortedList::Node *currentNode = sl.head;
   while (currentNode != nullptr)
   {
      os << currentNode->data;
      os << " ";
      currentNode = currentNode->next;
   }
   return os;
}

/// @brief The operator [] overloaded function returns the location of the item in that list
/// @param item An entry to be found
/// @return Returns the position of the item in the list. Returns -1 if element not found in the list.
int SortedList::operator[](int item) const
{
   if (empty())
   {
      return -1;
   }
   Node *currentNode = head;
   Node *lastNode = tail;
   int Position = 0;
   // Checking last entry
   if (lastNode->data == item)
   {
      return sizeOfList - 1;
   }
   // If the item is greater than the last node or lesser than first node it is not possible to be present in the list
   else if (item > lastNode->data || item < currentNode->data)
   {
      return -1;
   }
   // Traversing through the node for remaning cases
   while (currentNode != nullptr && currentNode->data != item)
   {
      currentNode = currentNode->next;
      Position++;
   }
   if (currentNode != nullptr && currentNode->data == item)
   {
      return Position++;
   }
   // Item Not Found
   return -1;
}

/// @brief The unary plus operator + overloaded function merges the two sorted list into one sorted list
/// @param lhs object of the First List
/// @param rhs object of the Second List
/// @return A Merged sorted List
SortedList operator+(const SortedList &lhs, const SortedList &rhs)
{
   SortedList sl;
   SortedList::Node *leftListHead = lhs.head;
   SortedList::Node *rightListHead = rhs.head;
   SortedList::Node *currentNode = nullptr;
   // If both list are not empty
   while (leftListHead != nullptr && rightListHead != nullptr)
   {
      SortedList::Node *newNode = new SortedList::Node();
      // Inserting First Node
      if (currentNode == nullptr)
      {
         currentNode = newNode;
         sl.tail = sl.head = newNode;
      }
      // Comparing Values to insert the data to the node
      if (leftListHead->data >= rightListHead->data)
      {
         newNode->data = rightListHead->data;
         rightListHead = rightListHead->next;
      }
      else
      {
         newNode->data = leftListHead->data;
         leftListHead = leftListHead->next;
      }
      // Creating connection to the new node For other cases
      if (newNode != sl.head)
      {
         currentNode->next = newNode;
         newNode->prev = currentNode;
         currentNode = currentNode->next;
      }
   }
   // If any list is exhaused the remaining current pointer is assigned to leftListHead
   if (leftListHead == nullptr)
   {
      leftListHead = rightListHead;
   }
   // Adding the remaining nodes of the non exhaused list to the merged list
   while (leftListHead != nullptr)
   {  
      SortedList::Node *newNode = new SortedList::Node(leftListHead->data);
      //Inserting first node in case where one List is empty
      if (sl.head == nullptr)
      {
         currentNode = newNode;
         sl.head = newNode;
      }
      //Inserting other nodes
      else
      {
         currentNode->next = newNode;
         newNode->prev = currentNode;
         currentNode = currentNode->next;
      }
      leftListHead = leftListHead->next;
   }
   sl.sizeOfList = lhs.sizeOfList + rhs.sizeOfList;
   sl.tail = currentNode;
   return sl;
}

/// @brief This operator overloaded function checks if the two SortedList contains exactly the same value
/// @param sl The list to be compared with
/// @return True if two list are equal else False
bool SortedList ::operator==(const SortedList &sl) const

{
   Node *LeftList = head;
   Node *RightList = sl.head;
   while (LeftList != nullptr && RightList != nullptr)
   {
      if (LeftList->data != RightList->data)
      {
         return false;
      }
      LeftList = LeftList->next;
      RightList = RightList->next;
   }
   if (LeftList == nullptr && RightList == nullptr)
      return true;
   return false;
}

/// @brief The operator overloaded function checks whether the two sorted list are not equal.
/// @param sl The list to be compared with
/// @return True if two list are not equal else False
bool SortedList ::operator!=(const SortedList &sl) const

{
   Node *LeftList = head;
   Node *RightList = sl.head;
   while (LeftList != nullptr && RightList != nullptr)
   {
      if (LeftList->data != RightList->data)
      {
         return true;
      }
      LeftList = LeftList->next;
      RightList = RightList->next;
   }
   if (LeftList == nullptr && RightList == nullptr)
      return false;
   return true;
}