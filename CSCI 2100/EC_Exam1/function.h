#include<iostream>
#include<stack>
#include<queue>
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
