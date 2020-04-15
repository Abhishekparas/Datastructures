#include<bits/stdc++.h>
using namespace std;
class node {

public:
	int data;
	node* next;

	node(int d) {
		data = d;
		next = NULL;
	}
};

void insertattail(node* &head, int data) {
	if (head == NULL) {
		head = new node(data);
		return;
	}

	node* temp = head;
	while (temp->next != NULL) {
		temp = temp->next;
	}
	temp->next = new node(data);
	return;
}

void buildlist(node* &head, int n) {
	int d;
	for (int i = 1; i <= n; i++) {
		cin >> d;
		insertattail(head, d);
	}
}
void printlist(node* head) {
	while (head != NULL) {
		cout << head->data << " ";
		head = head->next;
	}
	//cout<<endl;
}
void reverseiterative(node* &head, node* ktemp) {
	node* previous = NULL;
	node* current = head;
	node* nextnode;

	while (current != ktemp) {
		nextnode = current->next;
		current->next = previous;

		previous = current;
		current = nextnode;

	}
	head = previous;
}
int main() {
	node* head = NULL;
	int n, k;
	cin >> n >> k;
	buildlist(head, n);
	node* ktemp = head;

	for (int i = 1; i <= n / k; i++) {
		head = ktemp;
		int pos = 1;
		while (pos <= k) {
			ktemp = ktemp->next;
			pos++;
		}
		reverseiterative(head, ktemp);
		printlist(head);
	}



	//printlist(ktemp);
	//ktemp = ktemp->next;

	return 0;
}