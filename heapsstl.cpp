#include <bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{	priority_queue<int, vector<int>, greater<int> > pq;
	//priority_queue<int> pq; //by default max heap
	pq.push(10);
	pq.push(20);
	pq.push(100);
	pq.push(110);
	pq.push(2310);
	while (! pq.empty()) {
		cout << pq.top() << endl;
		pq.pop();
	}

	return 0;
}