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

void insertatk(node* &head, int data, int k){
	if(k==1){
		insertathead(head,data);
	}
	
	else if(k>length(head)){
		insertattail(head,data);
	}
	
	else{
		int pos= 1;
		node* temp = head;
		
		while(pos < k-1){
			pos++;
			temp = temp->next;
		}
		node* newnode = new node(data);
		newnode->next = temp->next;
		temp->next = newnode;
		return;
	}
}
void deletehead(node* &head){
	if(head == NULL){
		return;  //linked list is empty
	}
	
	node* temp = head;
	head = head->next;
	delete temp;
	return;
}

void deletetail(node* &head){
	if(head == NULL || head->next == NULL){
		deletehead(head);
	}
	node* temp =head;
	while(temp->next->next != NULL){
		temp = temp->next;
	}
	delete temp->next;
	temp->next = NULL;
	return;	
}
void deletekthnode(node* &head,int k){
	if(k==1 || head == NULL || head->next == NULL){
		deletehead(head);
		return;
	}
	else if(k>=length(head)){
		deletetail(head);
		return;
	}
	else{
		int pos =1;
		node * temp =head;
		while(pos<k-1){
			pos++;
			temp = temp->next;
		}
		node *tobedeleted = temp->next;
		temp->next = temp->next->next;
		delete tobedeleted;
		return;
	}
}

void buildlist(node* &head){
	int d;
	cin>>d;
	while(d != -1){
		insertattail(head,d);
		cin>>d;
	}
}

void printlist(node* head){
	while(head != NULL){
		cout<<head->data<<",";
		head = head->next;
	}
	cout<<endl;
}

istream& operator >>(istream& is, node* &head){
	buildlist(head);
	return is;
}

ostream& operator <<(ostream& os, node* &head){
	printlist(head);
	return os;
}

bool searchiterative(node* head, int key){
	
	while(head != NULL){
		if(head->data == key){
			return true;
		}
		head = head->next;
	}
}

bool searchrecursive(node* head, int key){
	if(head == NULL){
		return false;
	}
	
	if(head->data == key){
		return true;
	}
	else{
		searchrecursive(head->next,key);
	}
}

node* mid(node* head){
	if(head == NULL || head->next == NULL){
		return head;
	}
	node* slow = head;
	node* fast = head->next;
	while(fast != NULL && fast->next != NULL){
		slow = slow->next;
		fast = fast->next->next;
	}
	return slow;
	
}

int main(){
	node* head = NULL;
	node *head1 = NULL;
	/*insertathead(head,5);
	insertattail(head,10);
	insertattail(head,15);
	insertathead(head,2);*/
	
	
	/*cout<<length(head)<<endl;
	printlist(head);
	insertatk(head,20,3);
	printlist(head);
	deletehead(head);
	printlist(head);
	deletetail(head);
	printlist(head);
	deletekthnode(head,2);
	printlist(head);*/
	
	/*buildlist(head);
	printlist(head);*/
	
	cin>>head>>head1;
	cout<<head<<head1<<endl;
	
	cout<<searchiterative(head,2)<<endl;
	cout<<searchrecursive(head1,2)<<endl;
	
	cout<<mid(head)->data<<endl;
	return 0;
}
