#include <bits/stdc++.h>
using namespace std;
priority_queue<int, vector<int>, greater<int> > minheap;
priority_queue<int> maxheap;
void add(int num) {
	if (!minheap.empty() and num > minheap.top()) {
		minheap.push(num);
	}
	else {
		maxheap.push(num);
	}

	if (fabs(minheap.size() - maxheap.size()) > 1) {
		if (maxheap.size() > minheap.size()) {
			minheap.push(maxheap.top());
			maxheap.pop();
		}
		else {
			maxheap.push(minheap.top());
			minheap.pop();
		}
	}
}
float getmedian() {
	if (minheap.size() > maxheap.size()) {
		return minheap.top();
	}
	else if (maxheap.size() > minheap.size()) {
		return maxheap.top();
	}
	else {
		return (minheap.top() + maxheap.top()) / 2;
	}
}
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;
	while (n != 0) {		// 0 is end character
		if (n != -1) {
			add(n); // we have tom add n in the heap
		}
		else {
			//print median
			cout << getmedian() << endl;
		}
		cin >> n;
	}
	return 0;
}