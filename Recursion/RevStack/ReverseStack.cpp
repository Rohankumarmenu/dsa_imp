
#include <bits/stdc++.h> 
void letinsert(int temp,stack<int> &stack){
if(stack.empty()||stack.top()<temp){
stack.push(temp);
return;
}
int tp=stack.top();
stack.pop();
letinsert(temp,stack);
stack.push(tp);
}

void recurse(stack<int> &stack){
if(stack.empty() ||stack.size()==1){
 return;
}
int temp=stack.top();
stack.pop();
recurse(stack);
letinsert(temp,stack);
}

void sortStack(stack<int> &stack)
{
	// Write your code here
	recurse(stack);
}