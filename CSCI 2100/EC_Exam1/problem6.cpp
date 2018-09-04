#include<iostream>
#include<queue>
#include<stack>
using namespace std;


void halves(queue<int>& Q){
  int temp1, temp2, temp3, temp4;
  int half=(Q.size())/2;
  queue<int> holder;
  for(temp1=0;temp1<half;temp1++){
	holder.push(Q.front());
	Q.pop();
  }
  stack<int> holder2;
  for(temp2=0;temp2<half;temp2++){
	holder2.push(Q.front());
	Q.pop();
  }
  for(temp3=0;temp3<half;temp3++){
	Q.push(holder2.top());
	holder2.pop();
  }
  for(temp4=0;temp4<half;temp4++){
	Q.push(holder.front());
	holder.pop();
  }
} 




int main(){

  queue<int> test;
  test.push(10);
  test.push(-2);
  test.push(0);
  test.push(5);
  test.push(7);
  test.push(2);
  test.push(-8);
  test.push(3);
  test.push(4);
  test.push(14);

  queue<int> testcopy(test);
  cout<<"before halves"<<endl;

  while(!test.empty()){
     cout<<test.front()<<" ";
     test.pop();
     }
  cout<<endl;
 

  halves(testcopy);
  cout<<"after halves"<<endl;
  while(!testcopy.empty()){
     cout<<testcopy.front()<<" ";
     testcopy.pop();
    }
  cout<<endl;
}
