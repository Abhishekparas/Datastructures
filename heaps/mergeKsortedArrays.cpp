#include<bits/stdc++.h>
using namespace std;

typedef pair<int, pair<int, int> > node;
// pair<element,pair<arrayNumber,index> >

vector<int> mergeKsortedArrays(vector<vector<int> > v) {
	vector<int> result;
	priority_queue<node, vector<node>, greater<node> > pq;
	int k = v.size();

	int i = 0;
	while (i < k) {
		node ele = {v[i][0], {i, 0}};			//first elements of every array are pushed into the heap first
		pq.push(ele);
		i++;
	}

	while (!pq.empty()) {
		node topEle = pq.top();
		result.push_back(topEle.first);

		pq.pop();
		int arrayNumber = topEle.second.first;
		int index = topEle.second.second;

		if (index + 1 < v[arrayNumber].size()) {
			node ele = {v[arrayNumber][index + 1], {arrayNumber, index + 1}};
			pq.push(ele);
		}

	}
	return result;
}

int main(int argc, char const *argv[])
{
	vector<vector<int> > v{{1, 5, 8, 9, 10}, {11, 24, 36, 58, 223}, {2, 4, 6}};

	vector<int> result = mergeKsortedArrays(v);
	for (int i = 0; i < result.size(); ++i)
	{
		cout << result[i] << " ";
	}
	cout << endl;
	return 0;
}