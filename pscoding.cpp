#include<bits/stdc++.h>
using namespace std;
int main() {
	int q;
	cin >> q;
	stack<int> st;
	while (q--) {
		int query, cost;
		cin >> query;
		if (query == 2) {
			cin >> cost;
			st.push(cost);
		}
		if (query == 1) {
			if (st.empty()) {
				cout << "No Code" << endl;
			}
			else {
				cout << st.top() << endl;
				st.pop();
			}
		}
	}
	return 0;
}