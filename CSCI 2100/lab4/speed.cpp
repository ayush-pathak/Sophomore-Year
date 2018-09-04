#include<iostream>
using namespace std;

int main(){
  int input;
  while( input != -1){
	cin >> input;
  	int distance =0;
	int oldtime = 0;
	for (int i =0 ; i < input ; i++){
	  int speed, elapsed;
	  cin >> speed >> elapsed;
	  distance += speed * (elapsed -oldtime);
	  oldtime = elapsed;
	}
	if (input != -1){
	cout << distance <<" miles" << endl;}
	}
  return 0;
}
