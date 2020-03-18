#include<bits/stdc++.h>
using namespace std;
void insertatbottom(stack<int> &st,int x){
	if(st.empty()){
		st.push(x);
		return;
	}
	int y = st.top();
	st.pop();
	insertatbottom(st,x);
	st.push(y);
	
}
void reversestack(stack<int> &st){
	if(st.empty()){
		return;
	}
	int x = st.top();
	st.pop();
	reversestack(st);
	insertatbottom(st,x);
	
}
int main(){
	stack<int> st;
	for(int i =1 ;i<5; i++){
		st.push(i);
	}
	reversestack(st);
	while(!st.empty()){
		cout<<st.top()<<endl;
		st.pop();
	}
	
	return 0;
	
}
