#include<iostream>
#include<vector>
using namespace std;

int main(){
  int x;
  cin >> x;
  while(x!=-1){
    vector<int> v;
    v.push_back(x);
    cin >> x;
    while(x!=0){
      v.push_back(x);
      cin >> x;
      }
   int answer = 0;
   for(int i = 0; i<v.size(); i++){
      for(int j = 0; j<v.size(); j++){
         if(v[j]==2*v[i]){
             answer+=1;
         }
      }
   }
   cout <<answer<<endl;
   cin >> x;
   }
}
