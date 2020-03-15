#include<bits/stdc++.h>
using namespace std;
class Stack{
private:
    vector<int> v;
public:

    bool isempty(){
        return v.size() == 0;
    }

    void push(int value){
        v.push_back(value);
    }
    void pop(){
        if(!isempty()){
            v.pop_back();
        }

    }
    int top(){
        return v[v.size()-1];
    }
};
int main(){
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    cout<<st.top()<<endl;
    st.pop();
    cout<<st.top()<<endl;


















    return 0;
}
