#include<iostream>
#include<string>
using namespace std;

int convertedDepth(string::iterator& i){
    if(*i == 'd'){
      //something
      //first i is going to be a d so this needs to recurse into the first possible child/subtree
      }
    else{
      //something else
      //i is pointing at a u, need to determine if the number of u's are the same the number of d's(sense of equality)
      //
      }

int main(){
  string str;
  int num = 0;
  while(cin>>str && str!="#"){
    string::iterator pos = str.begin();
    int d =0;
    int h =0;
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
    cout<<"Tree "<<num<<": "<<h<<" => ";
    str.insert(0,"d");
    str.push_back('u');
    str::iterator conv = str.begin();
    
    /*int d2 =0;
    int h2 =0;
    while(conv!=str.end()){
      cout<<"counter"<<' '<<d2<<' '<<"height"<<h2<<' '<<endl;
      if(*conv=='d'){
         d2++;
         }
      else{
        conv++;
        if(*conv=='u'||*conv==0){
          if(d2>h2){
            h2=d2;
            d2=0;
            }
        }
        conv--;
        }
      conv++;
     }
    cout<<h2<<endl;*/
   }
 }
