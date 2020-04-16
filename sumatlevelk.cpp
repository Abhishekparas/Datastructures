#include <bits/stdc++.h>
using namespace std;

vector<int> v;
class node
{
public:
	int data;
	int noc;
	node* left;
	node* right;

	node(int d, int n) {
		data = d;
		noc = n;
		left = NULL;
		right = NULL;
	}

};

node* buildTree(node* root) {
	int d, n;
	cin >> d >> n;
	root = new node(d, n);
	if (n == 0) {
		return root;
	}
	if (n == 1) {
		root->left = buildTree(root->left);
		return root;
	}
	if (n == 2) {
		root->left = buildTree(root->left);
		root->right = buildTree(root->right);
		return root;
	}

}

void print(node* root) { // pre order traversal
	if (root == NULL) {
		return;
	}

	cout << root->data << " ";
	print(root->left);
	print(root->right);

}
void printKthLevel(node* root, int k) {
	if (k == 0) {
		v.push_back(root->data);
		return;
	}

	if (root->left) {
		printKthLevel(root->left, k - 1);
	}
	if (root->right) {
		printKthLevel(root->right, k - 1);
	}
}
int main(int argc, char const *argv[])
{
	node* root = NULL;
	root = buildTree(root);
	int k;
	cin >> k;
	printKthLevel(root, k);
	//print(root);
	int sum = 0;
	for (int i = 0; i < v.size(); i++) {
		sum = sum + v[i];
	}
	cout << sum;
	return 0;
}