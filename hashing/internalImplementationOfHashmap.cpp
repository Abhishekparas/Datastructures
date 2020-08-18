#include<bits/stdc++.h>
using namespace std;
template<typename T>
class Node{

public:
    string key;
    T value;
    Node<T>* next;

    Node(string k,T val){
        key = k;
        value= val;
        next = NULL;
    }
    ~Node(){                        //we have to implement this destructor because we have an array to which every index a linked list is connected, so if we want to delete entire linked list just by 'delete' keyword we have to use this destructor
        if(next != NULL){
            delete next;
        }
    }
};

template<typename T>
class hashMap{
    Node<T>** arr;            //pointer to an array of pointers (** is used because we are storing address),address of address
    int currSize;
    int totalSize;              //these are private, so that no one can manipulate our array, only functionalities that we provide should be used

    int hashFunction(string k){
        int idx = 0;
        int len = k.length();
        int multiplicationFactor = 1;

        for (int i = 0; i < len; i++)
        {
            int res = ((k[len-i-1] % totalSize) * (multiplicationFactor % totalSize)) % totalSize;                  /* if the string is "abc", then c*1 + b*47 + a*47*47 */                                                                                        
            idx = ((idx % totalSize) + (res % totalSize)) % totalSize;
            multiplicationFactor = ((multiplicationFactor % totalSize) * (47 % totalSize)) % totalSize;
        }
        return idx;
    }

    void rehash(){
        cout<<"Rehashing"<<endl;
        Node<T>** oldArray = arr;
        int oldSize = totalSize;

        totalSize = 2*totalSize;
        arr = new Node<T>*[totalSize]; 
        currSize = 0;                       //for new array currSize will again be '0'
        for (int i = 0; i < totalSize; i++)
        {
            arr[i] = NULL;
        }

        for (int i = 0; i < oldSize; i++)       //copying the old elements in the new array, we a;lso have to copy the linked list at each index in new array
        {
            if(oldArray != NULL){
                Node<T>* temp = oldArray[i];
                while(temp != NULL){
                    insert(temp->key,temp->value);
                    temp = temp->next;
                }
            }
        }
        for (int i = 0; i < oldSize; i++)
        {
            delete oldArray[i];
        }
        
        delete[] oldArray;
    }

public:
    hashMap(int defaultSize = 7){
        totalSize = defaultSize;
        arr = new Node<T>* [totalSize];

        for (int i = 0; i < totalSize; i++)
        {
            arr[i] = NULL;
        }
        currSize = 0;
    }

    void insert(string k,T val){
        int idx = hashFunction(k);

        // insert at head of linked list
        Node<T>* newNode = new Node<T>(k,val);
        newNode->next = arr[idx];
        arr[idx] = newNode;
        currSize++;

        float loadFactor = (float)currSize/(float)totalSize;           //currsize is the size of array

        if(loadFactor > 0.7){
            rehash();                                           //as soon as the loadfactor surpass the value 0.7 (basically if the size of the array is 10 and if we try to inert the 8th element then the size of the array will be doubled , so as to reduce the collisions)
        }
    }

    void print(){
        for (int i = 0; i < totalSize; i++)
        {   
            cout<<i<<"----->";
            
            Node<T>* temp = arr[i];
            while(temp != NULL){
                cout<<"( "<<temp->key<<" "<<temp->value<<" )"<<", ";
                temp = temp->next;
            }
            
            cout<<endl;
        }
    }

    T* search(string k){
        int idx = hashFunction(k);
        Node<T>* temp = arr[idx];

        while(temp != NULL){
            if(temp->key == k){
                return &(temp->value);
            }
            temp = temp->next;
        }
        return NULL;
    }

    T& operator[](string k){                //here we are returning the value by reference, because if we want to overwrite some value then it should be overwritten at the same address
        T* valueAdd = NULL;

        if(search(k) != NULL){                  //if the key is found we just need to overwrite it
            valueAdd = search(k);
        }
        else{                                   //else if the key is not found, then we have to first make a key and then insert it into the hashmap
            T garbageValue;
            insert(k,garbageValue);
            valueAdd = search(k);
        }
        /*valueAdd is the address of the value*/
        return *valueAdd;               //here we are returning the value only
    }

};

int main(){
    hashMap<int> hm(11);
    hm.insert("ABC",10);
    hm.insert("DEF",20);
    hm.insert("ghi",90);
    hm.insert("OPQ",30);
    hm.insert("uio",89);

    hm.print();

    // hm.insert("AsC",100);
    // hm.insert("DhF",200);
    // hm.insert("gki",900);
    // hm.insert("OiQ",300);
    // hm.insert("upo",890);

    // hm.print();

    if(hm.search("ABC") != NULL){
        cout<<"key found"<<endl;
    }
    else{
        cout<<"Key not found"<<endl;
    }

    if(hm.search("mno") != NULL){
        cout<<"key found"<<endl;
    }
    else{
        cout<<"Key not found"<<endl;
    }

    hm["ABC"] = 90;
    hm["AFKC"] = 1000;
    hm.print(); 

    return 0;
}