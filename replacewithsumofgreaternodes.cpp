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

node* buildBST(int arr[], int start, int end) {
	if (start > end) {
		return NULL;
	}

	int mid = (start + end) / 2;

	node* root = new node(arr[mid]);

	root->left = buildBST(arr, start, mid - 1);
	root->right = buildBST(arr, mid + 1, end);
	return root;

}

void replacesum(int *arr, int n) {
	int x = arr[n - 1];
	for (int i = n - 2; i >= 0; i--)
	{
		arr[i] = arr[i] + arr[i + 1];
	}
}

void preorder(node* root) {
	if (root == NULL) {
		return;
	}

	cout << root->data << " ";
	preorder(root->left);
	preorder(root->right);
}

int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	int arr[n];
	for (int i = 0; i < n; ++i)
	{
		cin >> arr[i];
	}

	//
	replacesum(arr, n);
	node* root = buildBST(arr, 0, n - 1);
	preorder(root);

	return 0;
}