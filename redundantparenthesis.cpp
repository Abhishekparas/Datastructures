#include<bits/stdc++.h>
using namespace std;
void solve(string str) {
	stack<char> st;
	int flag = 0;
	for (int i = 0; i < str.length(); i++) {
		if (str[i] == ')') {
			if (st.top() == '(') {
				flag = 1;
			}
			while (st.top() != '(') {
				st.pop();
			}
			st.pop();
		}

		else {
			st.push(str[i]);
		}
	}
	if (flag) {
		cout << "Duplicate" << endl;
	}
	else {
		cout << "Not Duplicates" << endl;
	}
}
int main() {
	int t;
	cin >> t;
	while (t--) {
		string str;
		cin >> str;
		solve(str);
	}
	return 0;
}