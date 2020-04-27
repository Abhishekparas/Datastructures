#include <iostream>
#include <queue>
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
int height(node* root) {
	if (root == NULL) {
		return -1;
	}

	int h = 1 + max(height(root->left), height(root->right));
	return h;

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

bool aretreesidentical(node* A, node* B) {
	if (A == NULL and B == NULL) {
		return true;
	}

	if (A != NULL and B != NULL) {
		bool lefttree = aretreesidentical(A->left, B->left);
		bool righttree = aretreesidentical(A->right, B->right);

		if (A->data == B->data and  lefttree and righttree) {
			return true;
		}
		else {
			return false;
		}
	}
	return false;
}

bool aretreesstructurallyidentical(node* A, node* B) {
	if (A == NULL and B == NULL) {
		return true;
	}

	if (A != NULL and B != NULL) {
		bool lefttree = aretreesstructurallyidentical(A->left, B->left);
		bool righttree = aretreesstructurallyidentical(A->right, B -> right);

		return lefttree and righttree;
	}
	return false;

}

void printnodesatdistancekinsubtree(node* root, int k) {
	if (root == NULL or k < 0) {
		return;
	}

	if (k == 0) {
		cout << root->data << " ";
		return;
	}

	printnodesatdistancekinsubtree(root->left, k - 1);
	printnodesatdistancekinsubtree(root->right, k - 1);
}

int printnodesatdistancek(node* root, int target, int k) {
	if (root == NULL) {
		return -1; //target doesn't exist
	}

	if (root->data == target) {
		printnodesatdistancekinsubtree(root, k);
		return 0;
	}

	int dleft = printnodesatdistancek(root->left, target, k);

	if (dleft != -1) { // it means target exists int the left
		if (dleft + 1 == k) {
			cout << root->data << " ";
		}
		else {
			printnodesatdistancekinsubtree(root->right, k - dleft - 2);
		}
		return dleft + 1; //distance of current node from target node
	}
	int dright = printnodesatdistancek(root -> right, target, k);

	if (dright != -1) {
		if (dright + 1 == k) {
			cout << root->data << " ";
		}
		else {
			printnodesatdistancekinsubtree(root->left, k - dright - 2);
		}
		return dright + 1; //distance of current node from target node
	}
	return -1; //if dleft and dright both are -1

}
int mindepth(node* root) {
	if (root == NULL) {
		return 0;
	}
	if (root->left == NULL and root->right == NULL) {
		return 1;
	}
	int minleft = 0, minright = 0;
	if (root->left) {
		minleft = mindepth(root->left);
	}
	if (root->right) {
		minright = mindepth(root->right);
	}
	return min(minleft, minright) + 1;
}

node* lca(node*root, int A, int B) {
	if (root == NULL) {
		return NULL;
	}

	if (root->data == A or root->data == B) {
		return root;
	}

	node* leftlca = lca(root->left, A, B);
	node* rightlca = lca(root->right, A, B);

	if (leftlca != NULL and rightlca != NULL) {
		return root;
	}
	else if (leftlca != NULL) {
		return leftlca;
	}
	else {
		return rightlca;
	}
}

int main(int argc, char const *argv[])
{
	node* root1 = buildTree();
	//node* root2 = buildTree();
	levelOrderWithNextLine(root1);
	cout << endl;
	/*levelOrderWithNextLine(root2);
	cout << endl;
	if (aretreesidentical(root1, root2)) {
		cout << "trees are identical" << endl;
	}
	else {
		cout << "trees are not identical" << endl;
	}*/
	printnodesatdistancek(root1, 4, 2);
	cout << endl;
	cout << mindepth(root1) << endl;
	node *cla = lca(root1, 5, 6);
	cout << cla->data << endl;

	return 0;
}