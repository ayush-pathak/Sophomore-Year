#include<iostream>
#include<sstream>
#include<vector>
using namespace std;
int main(){
	string inputs;
	cin >> inputs; // inputs the string "7" so need that to change to an int
	
	vector<string> names; //initialize the vector
	int set =1; //variable to keep track of the working set

	while(inputs != "0"){
		cout << "SET "<<set<<endl;
		set++;
		stringstream val(inputs); //change the first input in each case to a number
		int numNames;		  //variable to hold the number of names
		val >> numNames;
		for (int i=0; i<numNames; i++){ //puts in the names as they come in ie the first name is zero, second name is one, and so on
			cin >> inputs;
			names.push_back(inputs);
			if(i%2==0)
				cout << names[i]<<endl;
		}
		for(int j=numNames-1; j!=0;j--){
			if(j%2==1)
				cout << names[j]<<endl;
		}
		cin >> inputs;
		names.clear();
	}
}

