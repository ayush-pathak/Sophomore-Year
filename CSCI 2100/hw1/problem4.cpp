#include <iostream>
using namespace std;

int isPerfect(int n){
	int i=1,sum=0;
	while(i<n){
	  if(n%i==0){
		sum = sum + i;
		}
	  i++;
	}
	if(sum == n){
	  cout << n << endl;}
}

int main(){
	int k;
	for(k=1;k<=9999;k++){
	  isPerfect(k);
	}
return 0;}

