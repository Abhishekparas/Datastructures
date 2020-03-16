#include <bits/stdc++.h>

using namespace std;
reversestack(stack<int> &st){
    stack<int> st1;
    stack<int> st2;
    while(!st.empty()){
        st1.push(st.top());
        st.pop();
    }
    while(!st1.empty()){
        st2.push(st1.top());
        st1.pop();
    }
    while(!st2.empty()){
        st.push(st2.top());
        st2.pop();
    }
}

int main()
{
    stack<int> st;
    for(int i=1; i<=5; i++){
        st.push(i);
    }
    reversestack(st);
    while(!st.empty()){
        cout<<st.top()<<endl;
        st.pop();
    }
    return 0;
}
