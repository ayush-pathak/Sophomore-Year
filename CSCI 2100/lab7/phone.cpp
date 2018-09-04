#include<iostream>
#include<algorithm>
#include<string>
using namespace std;

int main(){
  int cases;
  cin>>cases;
  int i=0;
  while(i<cases){
    int numPhones;
    cin >> numPhones;
    string phoneNumbers[numPhones];
    for(int j =0; j<numPhones;j++){
       string number;
       cin >> number;
       phoneNumbers[j]=number;
       }
    sort(phoneNumbers,phoneNumbers+numPhones);
    bool isValid(true);
    for(int z =0; z<numPhones; z++){
        int len = phoneNumbers[z].size();
        
	if(phoneNumbers[z]==phoneNumbers[z+1].substr(0,len)){
	  isValid=false;
          break;
        }
    }
    if(isValid==true){
      cout<<"YES"<<endl;}
    else{
      cout<<"NO"<<endl;}
    i++;
    }
}
