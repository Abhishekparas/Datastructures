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
int length(node* head) {
    int len = 0;

    while (head != NULL) {
        len++;
        head = head -> next;
    }
    return len;
}
void buildLinkedList(node* &head, int N) {
    int d;
    for (int i = 1; i <= N; i++) {
        cin >> d;
        insertAtTail(head, d);
    }
}
void appendlist(node* &head, int k) {
    node* prev = head;
    node* curr = head;
    int leng = length(head);
    int pos = 0;
    while (pos < (leng - k)-1) {
        curr = curr->next;
        pos++;
        prev = prev->next;
    }
    curr = curr->next;
    node* temp = curr;
    prev->next = NULL;
    //int x = length(temp);
    while (curr->next != NULL) {
        curr = curr->next;
    }
    curr->next = head;
    head = temp;
}
int main() {
/*#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif*/
    node* head = NULL;
    int n, k;
    cin >> n;
    buildLinkedList(head, n);
    cin >> k;
    k=k%n;
    if(k>0)
    appendlist(head, k);
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }

}
