#include<bits/stdc++.h>
using namespace std;
class node
{
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

node* buildTree() {
	int d;
	cin >> d;

	if (d == -1) {
		return NULL;
	}

	node* root = new node(d);
	root->left = buildTree();
	root->right = buildTree();

	return root;

}

void print(node* root) { // pre order traversal
	if (root == NULL) {
		return;
	}

	cout << root->data << ", ";
	print(root->left);
	print(root->right);

}
void printkthlevel(node* root, int k) {
	if (k == 0) {
		cout << root->data << ", ";
		return;
	}

	if (root->left) {
		printkthlevel(root->left, k - 1);
	}
	if (root->right) {
		printkthlevel(root->right, k - 1);
	}
}

int height(node* root) {
	if (root  == NULL) {
		return -1;
	}

	int h = 1 + max(height(root->left), height(root->right));
	return h;
}

void printalllevels(node* root) {
	int levels = height(root);
	for (int i = 0; i <= levels; i++) {
		printkthlevel(root, i);
		cout << endl;
	}
}

void levelorder(node* root) {
	queue<node*> q;

	q.push(root);
	while (!q.empty()) {
		node* front = q.front();

		cout << front->data << ", ";

		if (front->left) {
			q.push(front->left);
		}
		if (front->right) {
			q.push(front->right);

		}
		q.pop();
	}
}

void levelorderwithnextline(node* root) {
	queue<node*>q;

	q.push(root);
	q.push(NULL);
	while (q.size() > 1) {
		node* front = q.front();
		if (front == NULL) {
			cout << endl;
			q.push(NULL);
		}
		else {
			cout << front->data << " ";
			if (front->left) {
				q.push(front->left);
			}
			if (front->right) {
				q.push(front->right);
			}
		}
		q.pop();
	}
}
int diameter(node* root) {
	if (root == NULL) {
		return 0;
	}

	int owndiameter = height(root->left) + height(root->right) + 2;
	int leftdiameter = diameter(root->left);
	int rightdiameter = diameter(root->right);
	return max(owndiameter, max(leftdiameter, rightdiameter));
}
class Pair {
public:
	int height;
	int diameter;
};

Pair diameteroptimized(node* root) {
	Pair P;
	if (root == NULL) {
		P.height = -1;
		P.diameter = 0;
		return P;
	}
	if (root->left == NULL and root->right == NULL) {
		P.height = 0;
		P.diameter = 0;
		return P;
	}

	Pair left = diameteroptimized(root->left);
	Pair right = diameteroptimized(root->right);

	P.height = max(left.height, right.height) + 1;
	int owndiameter = left.height + right.height + 2;
	P.diameter = max(owndiameter, max(left.diameter, right.diameter));
	return P;
}
int replacewithdescsum(node* root) {
	if (root == NULL) {
		return 0;
	}

	if (root->left == NULL and root->right == NULL) {
		return root->data;
	}

	int leftsum  = replacewithdescsum(root->left);
	int rightsum = replacewithdescsum(root->right);
	int temp = root->data;
	root->data = leftsum + rightsum;

	return temp + root->data;
}
int main() {
	/*#ifndef ONLINE_JUDGE
		freopen("input.txt", "r", stdin);
		freopen("output.txt", "w", stdout);
	#endif*/
	node* root = buildTree();
	print(root);
	cout << endl;
	printkthlevel(root, 2);
	cout << endl;
	cout << height(root);
	cout << endl;
	printalllevels(root);
	cout << endl;
	levelorder(root);
	cout << endl;
	levelorderwithnextline(root);
	cout << endl;
	cout << diameter(root) << endl;
	Pair ans = diameteroptimized(root);
	cout << ans.diameter << endl;
	replacewithdescsum(root);
	levelorderwithnextline(root);
	cout << endl;
	return 0;
}