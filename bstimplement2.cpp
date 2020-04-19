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

	if (root->data < key) {
		return search(root->right, key);
	}
	else {
		return search(root->left, key);
	}
}
void print(node* root) { // pre order traversal
	if (root == NULL) {
		return;
	}

	cout << root->data << ", ";
	print(root->left);
	print(root->right);

}
node* deleteinbst(node* root, int keydata) {
	if (root == NULL) {
		return  NULL;
	}

	if (keydata > root->data) {
		root->right = deleteinbst(root->right, keydata);
	}
	else if (keydata < root->data) {
		root->left = deleteinbst(root->left, keydata);
	}
	else {
		// node is leaf node
		if (root->left == NULL and root->right == NULL) {
			delete root;
			return NULL;
		}

		// only one child and that child is left
		else if (root->left != NULL and root->right == NULL) {
			node* temp  = root->left;
			delete root;
			return temp;
		}
		//node has only right child
		else if (root->left == NULL and root->right != NULL) {
			node* temp1 = root->right;
			delete root;
			return temp1;
		}
		//node has both child
		else {
			//replace node with left subtree;s max element
			node* temp2 = root->left;
			node* temp3 = root->left;
			while (temp2->right) {
				temp2 = temp2->right;
			}
			root->data = temp2->data; // temp2 = max of left subtree
			//root->left = deleteinbst(root->left, root->data);
			delete temp2;
			temp3->right = NULL;
			return root;
		}
	}
	return root;
}
node* min(node* root) {
	if (root == NULL) {
		return NULL;
	}

	if (root->left == NULL) {
		return root;
	}

	return min(root->left);
}
node* max(node* root) {
	if (root == NULL) {
		return NULL;
	}

	if (root->right == NULL) {
		return root;
	}

	return max(root->right);
}

bool isBST(node* root, int mini, int maxi) {
	if (root == NULL) {
		return true;
	}

	if (root->data >= mini  and root->data < maxi and isBST(root->left, mini, root->data) and isBST(root->right, root->data, maxi)) {
		return true;
	}
	return false;
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
class nodehelper
{
public:
	bool isBST;
	int maximum;
	int minimum;
	int size;
	nodehelper() {
		isBST = true;
		maximum = INT_MIN;
		minimum = INT_MAX;
		size = 0;
	}


};
nodehelper largestBSTinBT(node* root) {
	if (root == NULL) {
		return nodehelper();
	}
	nodehelper lefttree = largestBSTinBT(root->left);
	nodehelper righttree = largestBSTinBT(root->right);
	nodehelper curr;
	if (lefttree.maximum <= root->data && righttree.minimum > root->data && lefttree.isBST and righttree.isBST) {
		curr.isBST = true;
		curr.maximum = max(righttree.maximum, root->data); // max keyword is used because if leftree or right subtree becomes NULL then it will give wrong answer
		curr.minimum = min(lefttree.minimum, root->data);
		curr.size = lefttree.size + righttree.size + 1;
	}
	else {
		// when curr tree is not a bst
		curr.isBST = false;
		curr.size = max(lefttree.size, righttree.size);
		// max and min need not to be updated because the curr tree is not a bst
	}
	return curr;
}
int main() {
	/*node* root = buildBST();
	print(root);
	cout << endl;*/
	//int key;
	/*cin >> key;
	node* temp = search(root, key);
	if (temp) {
		cout << key << " found" << endl;
	}
	else {
		cout << key << " not found" << endl;
	}*/
	/*cout << endl;
	root = deleteinbst(root, 10);
	print(root);
	cout << endl;*/
	/*node* minimum = min(root);
	if (minimum) {
		cout << "minimum " << minimum->data << endl;
	}
	node* maximum = max(root);
	if (maximum) {
		cout << "maximum " << maximum->data << endl;
	}*/
	node* root2 = buildTree();
	/*bool bst = isBST(root2, INT_MIN, INT_MAX);

	if (bst) {
		cout << "it is bst" << endl;
	}
	else {
		cout << " it is not a bst" << endl;
	}*/
	nodehelper nh = largestBSTinBT(root2);
	cout << nh.size << endl;
	return 0;
}