#include <bits/stdc++.h>
using namespace std;
#include <bits/stdc++.h>
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


node* insert(node* root, int d) {
	if (root == NULL) {
		root = new node(d);
		return root;
	}
	if (d <= root->data) {
		root->left = insert(root->left, d);
	}
	else {
		root->right = insert(root->right, d);
	}
	return root;
}

node* buildBST() {
	node* root = NULL;
	int d;
	cin >> d;

	while (d != -1) {
		root = insert(root, d);
		cin >> d;
	}
	return root;
}

node* search(node* root, int key) {
	if (root == NULL) {
		return NULL;
	}

	if (root->data == key) {
		return root;
	}

	else if (root->data > key) {
		return search(root->left, key);
	}
	else {
		return search(root->right, key);
	}

}

node* deleteInBST(node* root, int key) {
	if (root == NULL) {
		return NULL;
	}
	if (key > root->data) {
		root->right = deleteInBST(root->right, key);
	}
	else if (key < root->data) {
		root->left = deleteInBST(root->left, key);
	}
	else { //node found
		//node is leaf node
		if (root->left == NULL and root->right == NULL) {
			delete root;
			return NULL;
		}
		//node has only left child
		else if (root->left != NULL and root->right == NULL) {
			node* temp = root->left;
			delete root;
			return temp;
		}
		//node has only right child
		else if (root->left == NULL and root->right != NULL) {
			node* temp = root->right;
			delete root;
			return temp;
		}
		//node has both child
		else {
			//replacing node with left subtree's max

			node* temp = root->left;
			while (temp->right) {
				temp = temp->right;
			}
			root->data = temp->data; //temp = max of left subtree
			root->left = deleteInBST(root->left, root->data);
			return root;
		}
	}
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



void levelOrderWithNextLine(node* root) {
	queue<node*> q;

	q.push(root);
	q.push(NULL);
	while (q.size() > 1) {
		node* front = q.front();
		if (front == NULL) {
			cout << endl;
			q.push(NULL);
		}
		else {
			cout << front->data << ", ";

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
class linkedlist {
public:
	node* head;
	node* tail;
};

linkedlist flatbst(node* root) {
	linkedlist ans;
	if (root == NULL) {
		ans.head = ans.tail = NULL;
		return ans;
	}
	else if (root->left == NULL and root->right == NULL) {
		ans.head = ans.tail = root;
		return ans;
	}

	else if (root->left != NULL and root->right == NULL) {
		linkedlist leftll = flatbst(root->left);
		leftll.tail->right = root;
		ans.head = leftll.head;
		ans.tail = root;
		return ans;
	}
	else if (root->left == NULL and root->right != NULL) {
		linkedlist rightll = flatbst(root->right);
		root->right = rightll.head;
		ans.head = root;
		ans.tail = rightll.tail;
		return ans;
	}
	else if (root->left != NULL and root->right != NULL) {
		linkedlist leftll = flatbst(root->left);
		linkedlist rightll = flatbst(root->right);

		leftll.tail->right = root;
		root->right = rightll.head;
		ans.head = leftll.head;
		ans.tail = rightll.tail;
		return ans;
	}
}
void swap(node* a, node* b) {
	node* temp = new node(a->data);
	a->data = b->data;
	b->data = temp->data;
}
node* pred = NULL;
node* A = NULL;
node* B = NULL;
void swappedtree(node* root) {
	if (root == NULL) {
		return;
	}

	swappedtree(root->left);
	if (pred != NULL and pred->data > root->data) {
		B = root;
		if (A == NULL) {
			A = pred;
		}
		else {
			return;
		}
	}
	pred = root;
	swappedtree(root->right);

}

void recoverActualBST(node* root) {
	if (root == NULL) {
		return;
	}
	swappedtree(root);
	swap(A, B);
}
int main(int argc, char const *argv[])
{
	node* root = buildTree();
	levelOrderWithNextLine(root);
	cout << endl;
	/*linkedlist list = flatbst(root);
	node* l = list.head;
	while (l) {
		cout << l->data << " ";
		l = l->right;
	}
	cout << endl;*/
	recoverActualBST(root);
	levelOrderWithNextLine(root);
	cout << endl;

	return 0;
}