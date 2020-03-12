#include <bits/stdc++.h>
using namespace std;
int main() {
    stack<char> st;
    string s = "((a+b)(c+d))";
    for(int i=0; i<s.length(); i++){
        if(s[i]  == '('){
            st.push(s[i]);
        }
        if(!st.empty() && s[i] == ')'){
            st.pop();
        }
    }
    if(st.empty()){
        cout<<"true";
    }
    else{
        cout<<"false";
    }

    return 0;

}
