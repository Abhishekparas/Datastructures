/*
* @Author: abhishek
* @Date:   2020-07-21 11:14:22
* @Last Modified by:   abhishek
* @Last Modified time: 2020-07-21 21:03:48
*/
#include<bits/stdc++.h>
using namespace std;
class node
{
public:
	char data;
	bool isTerminated;
	unordered_map<char, node*> children;

	node(char ch) {
		data = ch;
		isTerminated = false;
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
		}
		temp->isTerminated = true;                 //we are present at the last node of the word , so mark isTerminated as true
	}

	bool search(string word) {
		node* temp = root;
		for (int i = 0; i < word.length(); i++)
		{
			char ch = word[i];
			if (!temp->children.count(ch)) {
				return false;
			}
			temp = temp->children[ch];
		}
		return temp->isTerminated;
	}

};


int main(int argc, char const *argv[])
{
	Trie t;
	int n;
	cin >> n;
	while (n--) {
		string word;
		cin >> word;
		t.insert(word);
	}
	int q;
	cin >> q;
	while (q--) {
		string word;
		cin >> word;
		if (t.search(word)) {
			cout << word << " found ";
		}
		else {
			cout << word << " not found ";
		}
	}
	return 0;
}
