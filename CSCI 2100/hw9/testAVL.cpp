//#include "BinaryTree.h"
#include "AVLTree.h"
#include <iostream>
using namespace std;

int main() {

  AVLTree<int> mytree;
  
  mytree.insert(10);
  mytree.insert(5);
  mytree.insert(15);
  //cout << "past insert" << endl;

  //mytree.draw("AVLtree",0,true);
 
  //triggers no rotation
  mytree.insert(21);
  //mytree.draw("AVLtree",0,true);
  
  //triggers rotation in right side
  mytree.insert(35);
  //mytree.draw("AVLtree",0,true);
  
  //triggers rotation at root
  mytree.insert(42);  
  //mytree.draw("AVLtree", 0, true);

  //triggers no rotation on either side
  mytree.insert(20);
  mytree.insert(44);
  //mytree.draw("AVLtree",0,true);


  //triggers rotation at 15
  mytree.insert(18);
  //mytree.draw("AVLtree",0,true);

  //triggers rotation at 10
  mytree.insert(17);
  //mytree.draw("AVLtree",0,true);

  //trigger a rotation at 10 
  mytree.insert(3);
  //mytree.draw("AVLtree",0,true);

  //trigger rotation at root - 18 new root
  mytree.insert(16);
  //mytree.draw("AVLtree",0,true);

  //test functions
  if (mytree.find(11)) 
    cout << "Successfully found 11" << endl;
  else
    cout << "Successful 11 was not found" << endl;
  if (mytree.find(35))    
    cout << "Successfully found 35" << endl;
  else
    cout << "Error: 35 was not found" << endl;

  if (mytree.find(101)) 
    cout << "Error: found 101 in tree" << endl;
  else 
    cout << "Successful did not find 101 in tree" << endl;
  //need more nodes to be able to test
  mytree.insert(26);
  //causes rotation at 42
  mytree.insert(86);

  //no rotation
  mytree.insert(70);

  //causes rotation at 70
  mytree.insert(65);
  //causes rotation at 44
  mytree.insert(100);
  //no rotation
  mytree.insert(71);
  mytree.draw("AVLtree",0,true);
 
  //remove function tests
  //nothing should happen remove leaf
  cout<<"ten removed"<<endl;
  mytree.remove(10);
  mytree.draw("AVLtree",0,true); 

  //nothing should happen remove leaf
  cout<<"three removed"<<endl;
  mytree.remove(3);
  mytree.draw("AVLtree",0,true);

  //pivot at 15 and the root of 18, should become (16 root, 15&17 children) and 35 becomes root
  cout<<"five removed"<<endl;
  mytree.remove(5);
  mytree.draw("AVLtree",0,true);
  //remove 17,16 should do nothing
  cout <<"16 removed"<<endl;
  mytree.remove(16);
  mytree.draw("AVLtree",0,true);
  cout<<"17 removed"<<endl;
  mytree.remove(17);
  mytree.draw("AVLtree",0,true);
  //need a pivot test remove 15 and we should see a pivot
  cout<<"15 removed"<<endl;
  mytree.remove(15);
  mytree.draw("AVLtree",0,true);
  //test the remove of 44, should not trigger a pivot
  cout<<"44 removed"<<endl;
  mytree.remove(44);
  mytree.draw("AVLtree",0,true);
  //remove of 20 should not trigger a pivot in the left spine but reset heights
  cout<<"20 removed"<<endl;
  mytree.remove(20);
  mytree.draw("AVLtree",0,true);
  
}
