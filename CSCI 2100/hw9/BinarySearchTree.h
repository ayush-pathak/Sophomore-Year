#include "BinaryTree.h"
#include<iostream>
using namespace std;

template <typename ItemType>
class BinarySearchTree : public BinaryTree<ItemType> {
  
public:
  
  /**
   * Function to insert an element into the BST
   * Input Parameter: the element to insert
   * Return value: the position of the new node
   */
  typename BinaryTree<ItemType>::Iterator insert(const ItemType& element) {
    
    //check if tree is empty and put new element as root, if so
    if (BinaryTree<ItemType>::empty()) {
      BinaryTree<ItemType>::createRoot(element);
      return BinaryTree<ItemType>::root();
    }
    else {
      //Find position where the new value should go in current tree
      typename BinaryTree<ItemType>::Iterator position = BinaryTree<ItemType>::root(); 
      while (true) {
	if (*position < element) {
	  if (position.hasRightChild()) 
	    position = position.right();
	  else
	    break;
	}
	else {
	 if (position.hasLeftChild()) 
	   position = position.left();
	 else 
	   break;
	}
      }

      //Insert the new node - just below position
      if (element <= *position) {
	BinaryTree<ItemType>::insertAsLeftChild(element, position);
	position = position.left();
      }
      else {
	BinaryTree<ItemType>::insertAsRightChild(element, position);
	position = position.right();
      }
      return position;

    }
    
  } //end of insert
  
  /** 
   * Function to find if an element is in the tree
   * Input Parameter: the element to search for
   * Return value: a boolean which is true if the element is in the tree
   */
  bool find(const ItemType& value) {
    
    //make an iterator for root
    typename BinaryTree<ItemType>::Iterator position = BinaryTree<ItemType>::root();
    
    while (!position.isNULL()) {
      if (*position == value) {
	return true;
      }
      else {
	if (*position > value)
	  position = position.left();
	else
	  position = position.right();
      }
    } //ends while
    
    return false;
  } //end of find
  
  /** 
   * Function to remove an element from the tree
   */
  void remove(const ItemType& element) {
    if(!find(element)){
	throw domain_error("Element was not in the tree");}
    //make an iterator to the node with that element
    typename BinaryTree<ItemType>::Iterator location = BinaryTree<ItemType>::root();
    //move to the proper node that has the element
    while(!location.isNULL()){
      if(*location==element){
         break;}
      else{
	 if(*location > element){
	    location = location.left();}
	 else{
            location = location.right();}
          }
       }
    if(location.isRoot()){
      //find the next node in the inorder traversal which means go right then all the way left
      typename BinaryTree<ItemType>::Iterator leftmost = location;
      leftmost = leftmost.right();
      while(leftmost.hasLeftChild()){
        leftmost = leftmost.left();
      }
      //swap the data from the leftmost to the location
      *location=*leftmost;
      if(leftmost.hasRightChild()){//if there is a right subtree
        BinaryTree<ItemType>::deleteAndMoveRightChildUp(leftmost);
        }
      else{
        BinaryTree<ItemType>::deleteAndMoveLeftChildUp(leftmost);
        }
      }
    else{
      //case 1 will it is a leaf
      if(location.isLeaf()){
        BinaryTree<ItemType>::deleteAndMoveLeftChildUp(location);
        }
      //case 2 will be the node has a single child
      if(location.hasLeftChild() && !location.hasRightChild()){//it has a left child but not a right child
        BinaryTree<ItemType>::deleteAndMoveLeftChildUp(location);
        }
      if(location.hasRightChild() && !location.hasLeftChild()){ //it has a right child but not a left child
        BinaryTree<ItemType>::deleteAndMoveRightChildUp(location);
        }
      //case 3 is if the node to delete has 2 children
      if(location.hasRightChild() && location.hasLeftChild()){
        //create another iterator to hold the left most child
        typename BinaryTree<ItemType>::Iterator leftmost = location;
        leftmost = leftmost.right();
        while(leftmost.hasLeftChild()){
          leftmost = leftmost.left();
          }
        //swap data
        *location = *leftmost;
        if(leftmost.isLeaf()){
           BinaryTree<ItemType>::deleteAndMoveLeftChildUp(leftmost);
           }
        else{//if the leftmost has a right subtree
           BinaryTree<ItemType>::deleteAndMoveRightChildUp(leftmost);
           }
        }
     }

  } //end of remove
  
  
}; // end BinarySearchTree.h
