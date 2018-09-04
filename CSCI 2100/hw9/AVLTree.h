#include "BinarySearchTree.h"
#include <cmath>
#include <iostream>
using namespace std;

template <typename ItemType>
class AVLTree : public BinarySearchTree<ItemType> {
  
protected:
  
  /** function to set the height correctly **/
  void _setHeight(typename BinaryTree<ItemType>::Iterator position) {
    //get left child's height
    int leftheight = -1;
    if (position.hasLeftChild())
      leftheight = BinaryTree<ItemType>::getAux(position.left());
    //get left child's height
    int rightheight = -1;
    if (position.hasRightChild())
      rightheight = BinaryTree<ItemType>::getAux(position.right()); 
    //update position's height
    BinaryTree<ItemType>::setAux(max(leftheight,rightheight)+1, position);
  }//end of _setHeight
  
  bool _isBalanced(typename BinaryTree<ItemType>::Iterator position) {
    //get left child's height
    int leftheight = -1;
    if (position.hasLeftChild())
      leftheight = BinaryTree<ItemType>::getAux(position.left());
    //get left child's height
    int rightheight = -1;
    if (position.hasRightChild())
      rightheight = BinaryTree<ItemType>::getAux(position.right()); 
    
    if (abs(leftheight-rightheight) <= 1)
      return true;
    else
      return false;
    
  }
  
  typename BinaryTree<ItemType>::Iterator _getHigherChild(typename BinaryTree<ItemType>::Iterator position) {
    //get left child's height
    int leftheight = -1;
    if (position.hasLeftChild())
      leftheight = BinaryTree<ItemType>::getAux(position.left());
    //get left child's height
    int rightheight = -1;
    if (position.hasRightChild())
      rightheight = BinaryTree<ItemType>::getAux(position.right()); 
    
    if (leftheight > rightheight)
      return position.left();
    else
      return position.right();
  }
  
public:
  
  void insert(const ItemType& value) {
    //call BinarySearchTree insert to put new node in first
    typename BinaryTree<ItemType>::Iterator it = BinarySearchTree<ItemType>::insert(value);
    
    
    //fix heights and check if unbalanced
    it = it.up();
    while (!it.isNULL()) {
      //cout << "set height" << endl;
      //fix this node's height
      _setHeight(it);
      
      if (!_isBalanced(it)) {
	typename BinaryTree<ItemType>::Iterator z = it;
	typename BinaryTree<ItemType>::Iterator y = _getHigherChild(z);
	typename BinaryTree<ItemType>::Iterator x = _getHigherChild(y);
	
	//detect which pivots to do
	if (((z.left() == y) && (y.left() == x)) || ((z.right() == y) && (y.right() == x))) {
	  //need to pivot y once
	  BinaryTree<ItemType>::pivot(y);
	  _setHeight(x);
	  _setHeight(z);
	  _setHeight(y);
	  it = y.up();
	}
	else {
	  BinaryTree<ItemType>::pivot(x);
	  BinaryTree<ItemType>::pivot(x);
	  _setHeight(z);
	  _setHeight(y);
	  _setHeight(x);
	  it = x.up();
	}
      } //end if not balanced
      else 
	it = it.up();
    } //end of while
    
  } //end insert

  void remove(const ItemType& value) {
  //need an iterator to the parent of the node that will be removed
  typename BinaryTree<ItemType>::Iterator it = BinaryTree<ItemType>::root();
  typename BinaryTree<ItemType>::Iterator parent;
  typename BinaryTree<ItemType>::Iterator removed;
  //it points to the node with the value to be removed
  while(*it != value){
    if(*it>value){
      it = it.left();}
    else{
      it = it.right();}
    }
  //get iterators to the parent of the removed node
  //removed node will depend on cases
  //case 1: the root case and 2 children case
  if(it.isRoot()|| (it.hasLeftChild() && it.hasRightChild())){
    //if it is pointing to the root, the node that gets removed is the next node in the inorder traversal
    removed = it;
    removed++;
    parent = removed.up();
    }
  else{//
    parent = it.up();}
  BinarySearchTree<ItemType>::remove(value);
  //fix heights and check if unbalanced
  //point up to the parent of the removed node. 
  while(!parent.isNULL()){
    _setHeight(parent);
    if (!_isBalanced(parent)){
      typename BinaryTree<ItemType>::Iterator z = parent;
      typename BinaryTree<ItemType>::Iterator y = _getHigherChild(parent);
      typename BinaryTree<ItemType>::Iterator x = _getHigherChild(y);
      //find which pivot to do 
      if (((z.left() == y) && (y.left() == x)) || ((z.right() == y) && (y.right() == x))) {
       //need to pivot y once
       //basically its the all left left or right right case
       BinaryTree<ItemType>::pivot(y);
       _setHeight(x);
       _setHeight(z);
       _setHeight(y);
       parent = y.up();
       }
      else{
       BinaryTree<ItemType>::pivot(x);
       BinaryTree<ItemType>::pivot(x);
       _setHeight(z);
       _setHeight(y);
       _setHeight(x);
       parent = x.up();
       }
     //end if not balanced if statment
     }
    else
      parent = parent.up();
    //end of while
    }

  } //end remove
  
}; //end AVLTree class
