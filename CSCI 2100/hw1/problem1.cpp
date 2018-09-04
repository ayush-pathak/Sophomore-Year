#include <iostream>
#include <string>
using namespace std;
//*make an array of drinks//

int main(){
  int x=0;
  int a;
  string drinks[5]={"tea","coffee","Coke","Sprite","water"};
  while (x<5){
	cout<<drinks[x]<<endl;
	x++;
  }
  cout<<"Choose a beverage by entering a number 1-5"<<endl;
  cin>>a;
  if(0<a&&a<6){
	cout<<drinks[a]<<endl;
  }
  else{
	cout<<"Error: Choice not valid"<<endl;
  }
}

