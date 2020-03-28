#include<bits/stdc++.h>
using namespace std;
class node{
	
public:
	int data;
	node* next;
	
	node(int d){
		data =d;
		next = NULL;
	}
};
void insertathead(node* &head, int data){
	if(head == NULL){
		head = new node(data);
		return;
	}
	node* temp = new node(data);
	temp->next = head;
	head = temp;
	return;
}

void insertattail(node* &head, int data){
	if(head ==NULL){
		head = new node(data);
		return;
	}
	
	node* temp =head;
	while(temp->next != NULL){
		temp =temp->next;
	}
	temp->next = new node(data);
	return;
}

int length(node *head){
	int len=0 ;
	
	while(head!= NULL){
		head = head->next;
		len++;
	}
	return len;
}

void printlist(node* head){
	while(head!= NULL){
		cout<<head->data<<" ";
		head = head->next;
	}
}
int main(){
	node* head = NULL;
	
	insertathead(head,2);
	insertattail(head,10);
	insertattail(head,3);
	insertathead(head,4);
	
	cout<<length(head)<<endl;
	printlist(head);
	return 0;
}
