#include<bits/stdc++.h>
using namespace std;
class node {
public:
	int data;
	node *next;

	node(int d) {
		data = d;
		next = NULL;
	}
};
bool checkpalindrome(node *head) {
	node* first = head;
	node* second = head;
	stack<int> st;
	while (first != NULL) {
		st.push(first->data);
		first = first ->next;
	}
	while (second != NULL) {
		if (second->data != st.top()) {
			return false;
			break;
		}

		second = second->next;
		st.pop();
	}
	return true;
}
void insertAtTail(node *&head, int data) {
	//if linked list is empty
	if (head == NULL) {
		head = new node(data);
		return;
	}
	//if linked list is not empty
	node* temp = head;
	while (temp ->next != NULL) {
		temp = temp->next;
	}

	temp -> next = new node(data);
	return;
}


void buildlist(node* &head, int N) {
	int d;
	cin >> d;

	for (int i = 0 ; i < N; i++) {
		insertAtTail(head, d);
		cin >> d;
	}
}
int main() {

	int n;
	cin >> n;
	node* head = NULL;
	buildlist(head, n);
	if (checkpalindrome(head)) {
		cout << "True";
	}
	else {
		cout << "False";
	}
	return 0;
}