#include<bits/stdc++.h>
using namespace std;

void printHeap(priority_queue<int, vector<int>, greater<int> > pq) {
	while (! pq.empty()) {
		cout << pq.top() << ", ";
		pq.pop();
	}
	cout << endl;
}

void topKElements(int k) {

	priority_queue<int, vector<int>, greater<int> > pq;

	int n;
	cin >> n;

	int currHeapSize = 0;
	while (n != -1000) {
		if (n != -1) {
			if (currHeapSize < k) {
				pq.push(n);
				currHeapSize++;
			}
			else if (n > pq.top()) {
				pq.pop();
				pq.push(n);
			}
		}
		else {
			printHeap(pq);
		}
		cin >> n;
	}
}

int main(int argc, char const *argv[])
{
	int k;
	cin >> k;
	topKElements(k);
	return 0;
}