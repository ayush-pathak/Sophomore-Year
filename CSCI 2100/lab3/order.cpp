#include<iostream>
#include<stack>
#include<sstream>
using namespace std;
int main(){
string inputs;
cin >> inputs;//inputs the string "7" not the int

stack<string> names;//initialize the stack 
int set = 1;//variable to keep track of the working set

while(inputs !="0"){
cout << "SET " << set << endl;
set++;
stringstream val(inputs); // change the first input in each case to a number
int numNames;             // i.e. the first cin is the string "7" so changes that an int
val >> numNames;          // by using a stringstream 
for (int i=0; i<numNames; i++){
	cin >> inputs;
	if(i%2==0){
	  cout << inputs <<endl;
	  }
	else{
	  names.push(inputs); // pushes the current inputed name to the stack 
	  }
	}
while(!names.empty()){
	cout << names.top()<<endl; // prints the current name at the top of the stack
	names.pop();               // removes the top of the stack 
	}
cin >> inputs;  // reads in the next number 
}
}
