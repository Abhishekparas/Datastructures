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
			node* temp2 = root->left;
			while (temp2->right) {
				temp2 = temp2->right;
			}
			root->data = temp2->data; // temp2 = max of left subtree
			root->left = deleteinbst(root->left, temp2->data);
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

node* inordersuccessor(node* root, int d) {
	node *target = search(root, d);

	if (target == NULL) {
		return NULL;
	}
	else {
		if (target->right != NULL) {
			node* rightsubtree = target->right;
			while (rightsubtree->left) {
				rightsubtree = rightsubtree->left;
			}
			return rightsubtree;
		}
		else {
			//right child of target node doesn't exist
			node* ancestor = NULL;
			node* successor = root;
			while (successor != target) {
				if (target->data < successor->data) {
					ancestor = successor;
					/*ancestor is only updated in this case because the answer will be the lowest ancestor having target in its left subtree
					for example:
																20
														11						25
												7				15			23		27
											6		8		13		17
											the inorder successor of 8 is 11 i.e the lowest ancestor haveing 8 in its left subtree,however
											ancestor of 8 is 20 also but we want the lowest.
					*/
					successor = successor->left;
				}
				else {
					successor = successor->right;
				}
			}
			return ancestor;
		}
	}

}
int totalnumberofbst(int N) {
	if (N == 0) {
		return 1; // 1 BST is possible in whuch root node is NULL
	}
	int totalBST = 0;
	for (int i = 1; i <= N; ++i)
	{
		totalBST += totalnumberofbst(i - 1) * totalnumberofbst(N - i);
	}
	return totalBST;
}
int main(int argc, char const *argv[])
{
	//node* root = buildTree();
	node* root = buildBST();
	levelOrderWithNextLine(root);
	cout << endl;
	/*linkedlist list = flatbst(root);
	node* l = list.head;
	while (l) {
		cout << l->data << " ";
		l = l->right;
	}
	cout << endl;*/
	/*recoverActualBST(root);
	levelOrderWithNextLine(root);
	cout << endl;*/
	node * inos = inordersuccessor(root, 6);
	cout << "inorder successor -------->" << inos->data << endl;

	cout << totalnumberofbst(3) << endl;

	return 0;
}
