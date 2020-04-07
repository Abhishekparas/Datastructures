#include<bits/stdc++.h>
using namespace std;
class node {
public:
	int data;
	node* left;
	node* right;

	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};
node* buildtree() {
	int d;
	cin >> d;
	if (d == -1) {
		return NULL;
	}

	node* root = new node(d);
	root->left = buildtree();
	root->right = buildtree();
	return root;
}
void printinorder(node* root) {
	if (root == NULL) {
		return;
	}
	printinorder(root->left);
	cout << root->data << " ";
	printinorder(root->right);
}
void printpostorder(node* root) {
	if (root == NULL) {
		return;
	}
	printpostorder(root->left);
	printpostorder(root->right);
	cout << root->data << " ";
}
void printpreorder(node* root) {
	if (root == NULL) {
		return;
	}
	cout << root->data << " ";
	printpreorder(root->left);
	printpreorder(root->right);
}
int countnodes(node* root) {
	if (root == NULL) {
		return 0;
	}
	int nodes = 1 + countnodes(root->left) + countnodes(root->right);
	return nodes;
}
int sumnodes(node* root) {
	if (root == NULL) {
		return 0;
	}
	int sum = root->data + sumnodes(root->left) + sumnodes(root->right);
	return sum;
}
int main() {
#ifndef ONLINE_JUDGE
	freopen("input.txt", "r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	node* root = buildtree();
	printpreorder(root);
	cout << endl;
	printpostorder(root);
	cout << endl;
	printinorder(root);
	cout << endl;
	cout << "the total number of nodes are -------->" << countnodes(root) << endl;
	cout << "the sum of all the nodes of the tree is------->" << sumnodes(root) << endl;

	return 0;
}
