/*
* @Author: abhishek
* @Date:   2020-07-21 20:47:04
* @Last Modified by:   abhishek
* @Last Modified time: 2020-07-21 21:01:33
*/
#include<bits/stdc++.h>
using namespace std;
class node
{
public:
	char data;
	bool isTerminated;
	int visited;
	unordered_map<char, node*> children;

	node(char ch) {
		data = ch;
		isTerminated = false;
		visited = 0;
	}
};

class Trie {
public:
	node* root;
	Trie() {
		root = new node('\0');
	}

	void insert(string word) {
		node* temp = root;          //for traversing the trie
		for (int i = 0; i < word.length(); i++)
		{
			char ch = word[i];
			if (!temp->children.count(ch)) {       //if the node of this character is not already present ,then make a new node
				node* child = new node(ch);
				temp->children[ch] = child;
			}
			temp = temp->children[ch];
			temp->visited += 1;
		}
		temp->isTerminated = true;                 //we are present at the last node of the word , so mark isTerminated as true
	}

	void uniquePrefix(node* currNode, string prefix) {
		if (currNode == NULL) {
			return;
		}
		if (currNode->visited == 1) {
			cout << prefix << endl;
			return;
		}

		for (auto child : currNode->children) {		//child is a pair of char* and node i.e pair<char,node*>
			char ch = child.first;
			uniquePrefix(child.second, prefix + ch);
		}
	}

};

int main(int argc, char const *argv[])
{
	Trie t;
	int n;
	cin >> n;
	string arr[10] = {"abc", "app", "application", "mango", "applicant", "ape", "man"};
	for (int i = 0; i < n; ++i)
	{
		t.insert(arr[i]);
	}
	t.uniquePrefix(t.root, "");
	return 0;
}