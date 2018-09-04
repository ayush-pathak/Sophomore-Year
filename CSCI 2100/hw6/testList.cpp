#include <iostream>
#include "List.h"

int main() {
  
  /*List<int> mylist;
  List<int>::iterator it;
  
  mylist.push_front(5);
  mylist.push_front(11);
  mylist.push_front(21);
  cout<<"test of constructor and push_front"<<endl;
  for (it = mylist.begin(); it != mylist.end(); it++)
    cout << *it << " ";
  cout << endl;
  
  it = mylist.begin();
  *it = *it + 12;
  
  it++;
  mylist.insert(it,10);
  cout<<"test of iterator and adding to the element in node"<<endl;
  for (it = mylist.begin(); it != mylist.end(); it++)
    cout << *it << " ";
  cout << endl;  
  
  mylist.pop_back();
  mylist.pop_front();
  cout<<"test of pop_back and pop_front"<<endl;
  for (it = mylist.begin(); it != mylist.end(); it++)
    cout << *it << " ";
  cout << endl;

  cout<<"test of replace"<<endl;
  mylist.push_front(13);
  mylist.print_list();
  
  //test replace(val1,val2)
  mylist.replace(13,20);
  mylist.print_list();
  
  cout<<"test of copy constructor" <<endl;
  //test copy constructor
  List<int> otherlist(mylist);
  otherlist.print_list();
  mylist.push_front(-3);
  mylist.print_list();
  
  //test operator=
  mylist = otherlist;
  mylist.print_list();
  
  //test operator[]
  cout<<"test operator[]"<<endl;
  cout<<mylist[0]<<endl;
 
  //test reverse
  cout<<"test reverse"<<endl;
  mylist.reverse();
  mylist.print_list(); 
  //test sort
  mylist.push_back(4);
  mylist.push_back(17);
  mylist.push_back(23);
  mylist.push_back(16);
  mylist.push_back(16);
  mylist.print_list(); 
  cout<<"test sort"<<endl;
  mylist.sort();
  mylist.print_list();*/

  List<int> testList;
  testList.push_back(7);
  testList.push_back(7);
  testList.push_back(7);
  testList.push_back(6);
  testList.push_back(7);
 testList.push_back(2);
 testList.push_back(1);
 testList.push_back(40);
 testList.push_back(40);
 testList.push_back(1);
 testList.print_list();
 testList.unique();
 testList.print_list();

}
