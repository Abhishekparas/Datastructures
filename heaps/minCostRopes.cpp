#include<bits/stdc++.h>
using namespace std;

int costToConnectRopes(int* ropes, int n) {
	priority_queue<int, vector<int>, greater<int> > pq(ropes, ropes + n);		//we have initialized the priority queue like this because if we pass an array to the pq,then pq is formed by the array in O(n) rather than O(n*log(n)) by downheapify operation

	int totalCost = 0;
	while (pq.size() > 1) {
		int firstRope = pq.top();
		pq.pop();
		int secondRope = pq.top();
		pq.pop();

		int currCost = firstRope + secondRope;
		totalCost += currCost;
		pq.push(currCost);
		cout << firstRope << " " << secondRope << " " << currCost << endl;
	}
	return totalCost;
}

int main(int argc, char const *argv[])
{
	int n = 5;
	int ropes[5] = {2, 3, 4, 6, 7};
	cout << costToConnectRopes(ropes, n) << endl;
	return 0;
}