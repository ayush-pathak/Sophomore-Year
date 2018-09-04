#include<iostream>
#include<string>
using namespace std;

void solve(string goal, string I, string S, string O, string moves){
	if( goal == O ){
		cout<<moves<<endl;

	}
	else{
		//cout << string(3*moves.size(),' ') << "solve(" << goal << ", " << I << ", " << S << ", " << O << ", " << moves << ")" << endl;
		if(!I.empty()){
			char c = I[0];
			string I2 = I.substr(1,I.size()-1);
			string moves2 = moves;
			moves2.push_back('+');
			string S2 = S;
			S2.push_back(c);
			solve(goal,I2,S2,O,moves2);
			}
		if(!S.empty()){
			string moves2 = moves;
			moves2.push_back('-');
			char c = S[S.size()-1];
			O.push_back(c);
			string S2 = S.substr(0,S.size()-1);
			solve(goal,I,S2,O,moves2);
			}
	}

}

int main(){
  string goal;
  string I;
  string S;
  string O;
  string moves;
  int i =0;
  int cases;
  cin >> cases;
  while(i!=cases){
    cin >> I;
    cin >> goal;
    cout<<"Output for "<<I<<" "<<goal<<endl;
    cout<<"["<<endl;
    solve(goal,I,S,O,moves);
    cout<<"]"<<endl;
    i++;
  }
}
