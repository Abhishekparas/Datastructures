/*
* @Author: abhishek
* @Date:   2020-07-21 19:04:40
* @Last Modified by:   abhishek
* @Last Modified time: 2020-07-21 19:18:59
*/
#include<bits/stdc++.h>
using namespace std;
class node
{
public:
	int data;
	bool isTerminated;
	string userName;
	unordered_map<int, node*> children;

	node(int ch) {
		data = ch;
		isTerminated = false;
		userName = "";
	}
};

class Trie {
public:
	node* root;
	Trie() {
		root = new node('\0');
	}

	void insert(string word, string name) {
		node* temp = root;          //for traversing the trie
		for (int i = 0; i < word.length(); i++)
		{
			int ch = word[i] - '0';
			if (!temp->children.count(ch)) {       //if the node of this character is not already present ,then make a new node
				node* child = new node(ch);
				temp->children[ch] = child;
			}
			temp = temp->children[ch];
		}
		temp->userName = name;					   //on last node name of the whole number , the name of the user is marked
		temp->isTerminated = true;                 //we are present at the last node of the word , so mark isTerminated as true
	}

	string search(string word) {
		node* temp = root;
		string ans = "";
		for (int i = 0; i < word.length(); i++)
		{
			int ch = word[i] - '0';
			if (!temp->children.count(ch)) {
				return ans;
			}
			temp = temp->children[ch];
		}
		return temp->userName;
	}

};


int main(int argc, char const *argv[])
{
	Trie t;
	int n;
	cin >> n;
	while (n--) {
		string number;
		string userName;
		cin >> number >> userName;
		t.insert(number, userName);
	}
	int q;
	cin >> q;
	while (q--) {
		string number;
		cin >> number;
		if (t.search(number) != "") {
			cout << number << " is registered for " << t.search(number) << endl;
		}
		else {
			cout << number << " not registered ";
		}
	}
	return 0;
}
