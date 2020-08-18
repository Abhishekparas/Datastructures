#include<bits/stdc++.h>
using namespace std;

bool sumZero(int n,int* arr){
    unordered_map<int,int> mp;

    for (int i = 0; i < n; i++)
    {
        if(mp.find(-1*arr[i]) != mp.end()){
            cout<<arr[i]<<" "<<-1*arr[i]<<endl;
            return true;
        }

        else{
            mp.insert({arr[i],i});
        }
    }
    return false;
}

int main(){
    int n = 6;
    int arr[n] = {3,2,4,-2,9,5};
    if(sumZero(n,arr)){
        cout<<"sum zero exists"<<endl;
    }
    else{
        cout<<"sum zero doesn't exist"<<endl;
    }
    
    return 0;
}