#include <iostream>
#include <string>
using namespace std;

void printSquare(int size,char fillChar){
  int x=0;
  while(x<size){
	cout<<string(size,fillChar)<<endl;
	x++;
  }
}

int main(){
  printSquare(4,'@');
  printSquare(3,'a');
}
