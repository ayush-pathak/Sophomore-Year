#include "SLinkedList.h"
#include <iostream>
#include <stdexcept>
using namespace std;

int main() {

  SLinkedList<int> mylist;

  if (mylist.empty())
   cout << "list is empty" << endl;
 

  mylist.addFront(10);
  mylist.addFront(15);
  cout << mylist.front() << endl; //should be 15
  cout <<"Length of list" <<endl;
  int a = mylist.size();//should be 2
  cout << a << endl;
  cout << endl;
  cout << "Test of maximum function"<<endl;
  int b = mylist.maximum();
  cout << b << endl;
  cout << endl;
  cout << "Test of GetLast" << endl;
  cout<< mylist.getLast() << endl; //should be 10

  cout << endl;
  cout << "Printlist" <<endl;
  mylist.printlist();//shows the list
 
  mylist.removeFront();//removes 15
  cout << mylist.front() << endl; //should be 10
  cout<< "Length of list"<<endl;
  a = mylist.size();//should 1
  cout << a <<endl;

  SLinkedList<int> list1;
  list1.addFront(10);
  list1.addFront(15);
  list1.addFront(2);
  cout<< "list 1" <<endl;
  list1.printlist();
  cout<<endl;
  SLinkedList<int> list2;
  list2.addFront(9);
  list2.addFront(13);
  cout << "list 2" << endl;
  list2.printlist();
  cout << endl;
  cout <<"list 1 = list 2" << endl;
  list1=list2;//list1 should be the same as list2
  list1.printlist();
  list2.printlist();

  SLinkedList<int> list3;
  list3.addFront(4);
  list3.addFront(5);
  list3.addFront(17);
  cout<<"list 3" << endl;
  list3.printlist();
  SLinkedList<int> list4(list3);
  cout<< "list 4" << endl;
  list4.printlist();

  list4.skip();
  list4.printlist();



}
