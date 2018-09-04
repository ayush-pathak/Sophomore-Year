#ifndef SMART_STACK_H
#define SMART_STACK_H

#include <iostream>
#include <stdexcept>
#include <string>
#include <sstream>
using namespace std;


namespace csci180 {

  /** A stack implementation based upon use of a linked list.
   *  Elements are inserted and removed according to the last-in
   *  first-out principle.
   *
   *  This implementation is based  on that given pages 180-181
   *  of our text, but it has been adjusted to suit my tastes.
   */
  template <typename Object>
  class SmartStack {

  protected:					// this refers to the node structure
    struct Node {                               // a node in the stack
      Object element;                           // element
      Node*  next;                              // next pointer
      int ref;					// counter for each node in the stack

      Node(const Object& e = Object(), Node* n = NULL, int r =1) : element(e), next(n), ref(r) {
	SmartStack::total++;   // please leave this command here
      }              

      ~Node() {
	SmartStack::total--;   // please leave this command here
      }
      
    };

  private:					// this refers to the whole stack structure
    Node* tp;                                   // pointer to stack top
    int sz;                                     // number of items in stack

  public:
    /** Standard constructor creates an empty stack. */
    SmartStack() : tp(NULL), sz(0) { }

    /** Returns the number of objects in the stack.
     *  @return number of elements
     */
    int size() const {
      return sz;
    }

    /** Determines if the stack is currently empty.
     *  @return true if empty, false otherwise.
     */
    bool empty() const {
      return sz == 0;
    }

    /** Returns a const reference to the top object in the stack.
     * @return reference to top element
     */
    const Object& top() const {
      if (empty())
        throw std::runtime_error("Access to empty stack");
      return tp->element;
    }

    /** Inserts an object at the top of the stack.
     *  @param the new element
     */
    void push(const Object& elem) {
      tp = new Node(elem, tp, 1);                 // new node points to old top, added the int 1 to make sure the ref is 1 for a new node
      sz++;
    }

    /** Removes the top object from the stack. */
    void pop()  {
      if (empty())
        throw std::runtime_error("Access to empty stack");
      
      if((tp->ref)>1){
	int val = tp->ref;			// this is for the first tp found
	val--;
	tp->ref = val;
	tp = tp->next;					// this moves the tp pointer to the next node 
	sz--;
	if (tp !=NULL){					// this if statment is to catch the edge case where the tp is pointing to the last node and its ref is greater than 1
	  int newVal = tp -> ref;			// this for the next node for tp 
          newVal++;
	  tp->ref=newVal;
	 }
	}
      else{
      	Node* old = tp;                           // node to remove
      	tp = tp->next;
      	sz--;
      	delete old;	
     	}  
    }
  protected:                                    // protected utilities
    void removeAll() {                          // remove entire stack contents
      while(!empty()){
	pop();
      }
    }

    void copyFrom(const SmartStack& other) {   // copy from other
      sz = other.sz;
      tp = other.tp;
      int val = other.tp -> ref;
      val++;
      other.tp->ref = val;
      
    }

  public:
    /** Copy constructor */
    SmartStack(const SmartStack& other) {
      copyFrom(other);
    }

    /** Assignment operator */
    SmartStack& operator=(const SmartStack& other) {
      if (this != &other) {                     // avoid self copy (x = x)
        while(tp->ref ==1){
	  pop();
	}
        int val = tp->ref;
	val--;
	tp->ref=val;
	tp = other.tp;
	sz = other.sz;
	int newVal = other.tp -> ref;
	newVal++;
	other.tp->ref=newVal;
      }
      return *this;
    }

    /** Destructor */
    ~SmartStack() {
	while(!empty()){
	  removeAll();
	  }
	}


  public:
    //-----------------------------------------------------------
    // used for diagnostic purposes to count number of live nodes
    static int total;

    static int getTotalNumNodes() {
      return total;
    }

    std::string dump() const {
      std::stringstream temp;
      for (Node* walk=tp; walk!=NULL; walk=walk->next)
	temp << walk->element <<"("<<walk->ref<<")"<<" ";
      return temp.str();
    }
    //-----------------------------------------------------------

  };  // end of SmartStack class

} // end of csci180 namespace

#endif
