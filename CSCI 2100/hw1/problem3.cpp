#include <string>
#include <iostream>
using namespace std;

int main(){
  char val;
  cout<<"Enter a letter:"<<endl;
  cin>>val;
  cout<<endl;
  cout<<"Operation of pre and post increment and decrement:"<<endl;
  cout<<string(40,'-')<<endl;
  cout<<"The letter is: "<<val<<endl;
  cout<<"Using post increment (letter++) the number is now: "<<val++<<endl;
  cout<<"And the letter is now: "<<val<<endl;
  cout<<"Using pre increment (++letter) in cout I get "<<++val<<endl;
  cout<<"And the letter is now: "<<val<<endl;
  cout<<"Using post decrement (letter--) the number is now: "<<val--<<endl;
  cout<<"And now the letter is: "<<val<<endl;
  cout<<"Using pre decrement (--letter) in cout I get "<<--val<<endl;
  cout<<"And the letter is: "<<val<<endl;
}
