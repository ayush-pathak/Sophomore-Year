//#include "BinaryTree.h"
#include "BinarySearchTree.h"
#include <iostream>
using namespace std;

int main() {

  BinarySearchTree<int> mytree;
  
  mytree.insert(10);
  mytree.insert(5);
  mytree.insert(15);

  mytree.draw("BStree",0,true);
 
  mytree.insert(21);
  mytree.insert(35);
  mytree.insert(42);
  
  mytree.draw("BStree", 0, true);

  mytree.insert(11);
  mytree.insert(7);
  mytree.insert(29);
  
  mytree.draw("BStree", 0, true);  

  //test functions
  if (mytree.find(11)) 
    cout << "Successfully found 11" << endl;
  else
    cout << "Error: 11 was not found" << endl;
  if (mytree.find(35))    
    cout << "Successfully found 35" << endl;
  else
    cout << "Error: 35 was not found" << endl;

  if (mytree.find(101)) 
    cout << "Error: found 101 in tree" << endl;
  else 
    cout << "Successful did not find 101 in tree" << endl;
  
  cout<<"test of remove of one leaf"<<endl;
  mytree.remove(7);
  if (mytree.find(7))
    cout << "Error: 7 found in the tree after remove"<<endl;
  else
    cout << "Successful did not find 7 in the tree" <<endl;
  mytree.draw("BStree", 0, true);


  mytree.insert(12);
  mytree.insert(1);
  mytree.insert(28);
  mytree.insert(13);
  mytree.insert(23);
  mytree.draw("BStree", 0, true);

  cout<<"test of remove of the root"<<endl;
  mytree.remove(10);
  mytree.draw("BStree", 0, true);
  if (mytree.find(10))
   cout << "Error: 10 found in the tree after remove"<<endl;
  else
   cout << "Successful did not find 10 in the tree" <<endl; 
  

  cout<<"test of remove of a node with one child"<<endl;
  mytree.remove(29);
  mytree.draw("BStree", 0, true);
  if (mytree.find(29))
   cout <<"Error: found 29 in the tree after remove"<<endl;
  else
   cout <<"Successful did not find 29 in the tree"<<endl;
  

  cout<<"test of remove of a node with 2 children" <<endl;
  mytree.remove(35);
  mytree.draw("BStree", 0, true);
  if (mytree.find(35))
   cout <<"Error: found 35 in the tree after remove"<<endl;
  else
   cout <<"Successful did not find 35 in the tree" <<endl;
 
}
