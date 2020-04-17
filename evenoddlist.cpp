#include <bits/stdc++.h>
using namespace std;
class node {

public:
	int data;
	node* next;

	//constructor
	node(int d) {
		data = d;
		next = NULL;
	}
};
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
void buildLinkedList(node* &head, int n) {
	int d;

	for (int i = 1; i <= n; i++) {
		cin >> d;
		insertAtTail(head, d);
	}
}
void evenafterodd(node* &head) {
	node* temp = head;
	node* var = head;
	queue<int> st;
	vector<int> v;
	while (temp != NULL) {
		if (temp->data % 2 == 0 ) {
			st.push(temp->data);
		}
		else if (temp->data & 1) {
			v.push_back(temp->data);
		}

		temp = temp ->next;
	}
	while (!st.empty()) {
		v.push_back(st.front());
		st.pop();
	}
	for (int i = 0 ; i < v.size(); i++) {
		var->data = v[i];
		var = var->next;
	}

}
int main() {
	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/
	node* head = NULL;
	int n;
	cin >> n;
	buildLinkedList(head, n);
	evenafterodd(head);
	while (head) {
		cout << head->data << " ";
		head = head -> next;
	}
	return 0;
}