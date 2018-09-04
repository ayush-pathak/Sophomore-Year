#include<iostream>
#include<string>
using namespace std;

int main(){
  string str;
  int num = 0;
  while(cin>>str && str!="#"){
   string::iterator pos=str.begin();
   int d = 0;
   int h = 0;
   num++;
   while(pos!=str.end()){
    if(*pos=='d'){
      d++; 
    }
    else{
      if(h<=d){
        h = d;
        }
      d--;
    }
    pos++;
   }
  cout<<"Tree "<<num<<": "<<h<< endl;;
  }
}

