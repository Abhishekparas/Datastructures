#include <bits/stdc++.h>
using namespace std;
#define node pair<int, pair<int, int> >
vector<int> mergeksortedarrays(vector<vector<int> >v) {
	priority_queue<node, vector<node>, greater<node> > pq;
	int k = v.size();
	vector<int> result;

	int i = 0;
	while (i < k) {
		//element,array number,element index
		node ele = make_pair(v[i][0], make_pair(i, 0));
		pq.push(ele);
		i++;
	}

	while (!pq.empty()) {
		node topele = pq.top();
		result.push_back(topele.first);
		pq.pop();
		int arraynumber  = topele.second.first;
		int index = topele.second.second;
		if (index + 1 < v[arraynumber].size()) {
			node ele =  make_pair(v[arraynumber][index + 1], make_pair(arraynumber, index + 1));
			pq.push(ele);
		}
	}
	return result;
}
int main(int argc, char const *argv[])
{	vector<vector<int> > v{{1, 5, 8, 9, 10},
		{11, 24, 36, 58, 223},
		{2, 4, 6}};
	vector<int> result = mergeksortedarrays(v);
	for (int i = 0; i < result.size(); ++i)
	{
		/* code */
		cout << result[i] << " ";
	}
	cout << endl;
	return 0;
}