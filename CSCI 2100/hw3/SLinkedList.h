#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H

#include <iostream>
#include <stdexcept>
using namespace std;

/* Singly Linked List Class */

template <typename Object>
class SLinkedList {
  
private:
  
  /* Node struct for singly linked lists*/
  struct SNode {
    Object _elem;
    SNode * _next;
  };
  
  //private variable list for List class
  SNode * _head;
  
public:
  
  /*
   * Constructor
   */
  SLinkedList();
  
  /* 
   * Destructor
   */  
  ~SLinkedList();
  
  /* 
   * Function to test if the list is empty
   * Return: boolean value true if it is empty
   */
  bool empty() const;
  
  /* 
   * Function to return the front of the list
   * Return: A constant reference to the front of the list
   */
  const Object& front() const;
 
  
  /*
   * Function to remove the front of the list
   */
  void removeFront();
  
  /*
   * Function to add a node to the front of the list
   * Input parameter: a variable of type Object to insert
   */
  void addFront(const Object& e);
  
  //Copy constructor
  SLinkedList(const SLinkedList& other);
  
  //operator=
  SLinkedList& operator=(const SLinkedList& other);

  //extra print function for debugging
  void printlist();

  /*
   * Function to return the length of the list
   * Return: An integer of the size
   */
  int size()const;


 /*
  * Function to return the last element of the list
  * Return: A constant reference to the end of the list
  */
  const Object& getLast() const;  


 /*
  * Function to return the largest element in the list
  * Return: A reference to the largest element in the list
  * NEEDS TO BE WORKED ON
  */
  Object&  maximum() const;
  
  void skip(); 
};
#include "SLinkedList.cpp"  
#endif
