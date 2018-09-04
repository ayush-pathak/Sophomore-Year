#include "SLinkedList.h"
#include <iostream>
#include <stdexcept>
using namespace std;

  /*
   * Constructor
   */
  template <typename Object>
  SLinkedList<Object>::SLinkedList() : _head(NULL){}
  

  /* 
   * Function to test if the list is empty
   * Return: boolean value true if it is empty
   */
  template <typename Object>
  bool SLinkedList<Object>::empty() const {
	return (_head == NULL);
  }
  /*
   * Function to return the maximum of the list
   * Return: A constant reference to the maximum of the list
   */
  template <typename Object>
  Object& SLinkedList<Object>::maximum() const{
	if (empty())
	  throw domain_error("list is empty");
	// create a new variable to hold the maximum value  , called it static so that persists after while loop
	static Object val;
	SNode* temp= _head; 
	while (temp != NULL) {
	  // compare the values; if val is smaller make the data the val 
	  if (val < temp ->_elem){
	    val = temp -> _elem;
	    }
	  // move to the next node
	  temp = temp -> _next;
	}
  return val;
  }

	
  /* 
   * Function to return the front of the lists
   * Return: A constant reference to the front of the list
   */
  template <typename Object>
  const Object& SLinkedList<Object>::front() const {
        if (empty())
	  throw domain_error("list is empty");
 	return _head->_elem;
  }
 /*
  * Function to return the end of the lists
  * Return: A constant reference to the end of the list
  */
  template<typename Object>
  const Object& SLinkedList<Object>::getLast() const{
  	if (empty())
	  throw domain_error("list is empty");
	//need two nodes to keep track of the current and the last
	SNode* first = _head;
	SNode* prev;
	while (first != NULL){
	  //move each tracking node to its respective next node
	  prev =  first;
	  first = first -> _next;
	}
  //returns the last element
  return prev->_elem;
  }
  /*
   * Function to remove the front of the list
   */
  template <typename Object>
  void SLinkedList<Object>::removeFront() {
	if (empty())
	  throw domain_error("can't remove from empty list");

	//save old head location, and point to 2nd element in list
	SNode* oldhead = _head;
	_head = _head->_next;    

	//remove the unneeded node (old head)
	delete oldhead;
  }
  
  /*
   * Function to add a node to the front of the list
   * Input parameter: a variable of type Object to insert
   */
  
  template <typename Object>
  void SLinkedList<Object>::addFront(const Object& e) {
	//create new first node
	SNode* temp = new SNode;
        temp->_elem = e;
	//alternate: (*temp)._elem = e;

	//update pointers - head to new one, and new one to old head
	temp->_next = _head;
	_head = temp;

  }

   /* 
   * Destructor
   */  
  template <typename Object>
  SLinkedList<Object>::~SLinkedList() {
	while (!empty())
	  removeFront();
  }
  
  //operator=
  template <typename Object>
  SLinkedList<Object>& SLinkedList<Object>::operator=(const SLinkedList& other) {
   if (this != &other) {
	if (_head != NULL){
		removeFront();
	}
	SNode* current = other._head;
	SNode* previous = NULL;
	
	while (current!= NULL){
	  SNode* temp = new SNode;
	  temp -> _elem = current -> _elem;
	  if (previous ==NULL)
		_head = temp;
	  else
	  	previous -> _next = temp;
	  previous = temp;
	  current = current-> _next;
	}
   return *this;
   }
}


  /*
   * Function to return the size of the list
   * Return: An integer of the size
   */
  template <typename Object>
  int SLinkedList<Object>::size()const{
  // make a variable to hold the length
  int len = 0;
  SNode* temp = _head;
	while(temp !=NULL){
	  len++;
	  temp = temp -> _next;
	}
  return len;
  }


  //copy constructor
  template <typename Object>
  SLinkedList<Object>::SLinkedList(const SLinkedList& other) {
	//travel through other list, copying each node 
        SNode* current = other._head;
	SNode* previous = NULL;

	//if we have a node at current, copy it
	while (current != NULL) {
	  SNode* temp = new SNode;
	  temp -> _elem = current->_elem;

	  if (previous == NULL)
	    _head = temp;
	  else
	    previous->_next = temp;

	  previous = temp;
	  current = current->_next;
	}
	

  } //end of copy constructor 

  template <typename Object>
  void SLinkedList<Object>::printlist() {
    SNode* temp = _head;
    if (empty())
	cout << "empty list" << endl;
    else {
      while (temp != NULL) {

        cout << temp->_elem << " -> ";
        temp = temp->_next;
      }
      cout << "NULL" << endl;
   }
}

  template<typename Object>
  void SLinkedList<Object>::skip(){
    int i=0;
    SNode* prev;
    SNode* current = _head;
    while(current!=NULL){
	if(i%2==0){
	 prev=current;
	 current=current->_next;
	 i++;
	}
	else{
	 SNode* temp = current;
	 current = current->_next;
	 delete temp;
	 prev->_next=current;
	 i++;
	}
    }
 }
