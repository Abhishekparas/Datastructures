#include<bits/stdc++.h>
using namespace std;
class node{
public:
    int data;
    node* zero;
    node* one;
    int preXor;     //at the last node of each branch of trie, we will store the prefix xor till that number
                    // for example, if the array is {8,1,2,12,7,6} then we will store it like ---> 8->8; 8^1->xor of (8 and 1)
    node(int ch){
        data = ch;
        zero = NULL;
        one = NULL;
        preXor = 0;
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
        temp->preXor = num;
    }

    int xorQuery(int num){

        node* temp = root;

        for(int k=31; k>=0; k--){
            int currBit = (num>>k)&1;
            if(currBit){
                if(temp->zero){
                    temp =temp->zero;
                }
                else{
                    temp = temp->one;
                }
            }
            else{
                if(temp->one){
                    temp = temp->one;
                }
                else{
                    temp = temp->zero;
                }
            }
        }
        return num xor temp->preXor;
    }
};

int main(int argc, char const *argv[])
{
    Trie t;
    int n = 6;
    int arr[10] = {8,1,2,12,7,6};
    int prefixXor = 0;
    int maxSubArrayXor = INT_MIN;
    for (int i = 0; i < n; i++)
    {   
        prefixXor = prefixXor xor arr[i];
        t.insert(prefixXor);
        maxSubArrayXor = max(maxSubArrayXor,t.xorQuery(prefixXor));
    }
    cout<<maxSubArrayXor;
    return 0;
}
