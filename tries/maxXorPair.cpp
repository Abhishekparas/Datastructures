#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node* zero;
    node* one;

    node(int ch){
        data = ch;
        zero = NULL;
        one = NULL;
    }
};
class Trie{
public:
    node* root;
    Trie(){
        root = new node('\0');
    }

    void insert(int num){
        node* temp = root;
        for(int i=31; i>=0 ;i--){       //we are traversing from msb to lsb
            int currBit = (num>>i)&1;
            if(currBit){
                if(temp->one == NULL){
                    node * bit = new node(1);
                    temp->one= bit;
                }
                temp = temp->one;
            }
            else{
                if(temp->zero ==NULL){
                    node* bit = new node(0);
                    temp->zero = bit;
                }
                temp = temp->zero;
            }
        }
    }

    int maxXorPair(int* arr ,int n){
        int maxXor = 0;
        for (int i = 0; i < n; i++)
        {
            int num = arr[i];
            int currXor = 0;
            node* temp = root;

            for(int k=31; k>=0; k--){
                int currBit = (num>>k)&1;
                if(currBit){
                    if(temp->zero){
                        currXor += pow(2,k);
                        temp =temp->zero;
                    }
                    else{
                        temp = temp->one;
                    }
                }
                else{
                    if(temp->one){
                        currXor += pow(2,k);
                        temp = temp->one;
                    }
                    else{
                        temp = temp->zero;
                    }
                }
            }
            maxXor = max(maxXor,currXor);
        }
        return maxXor;
    }
};

int main(int argc, char const *argv[])
{
    Trie t;
    int n = 4;
    int arr[10] = {1,2,3,7};
    for (int i = 0; i < n; i++)
    {
        t.insert(arr[i]);
    }
    cout<<t.maxXorPair(arr,n);
    return 0;
}
