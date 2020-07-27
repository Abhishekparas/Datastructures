/*
* @Author: abhishek
* @Date:   2020-07-11 19:42:53
* @Last Modified by:   abhishek
* @Last Modified time: 2020-07-14 14:51:11
*/
#include<bits/stdc++.h>
using namespace std;

vector<int> arr[100];
bool visited[100];
int dist[100];

int bfs(int source, int destination) {
	queue<int> q;
	q.push(source);
	dist[source] = 0;
	visited[source] = true;

	while (!q.empty()) {
		int frontNode = q.front();
		q.pop();
		for (int i = 0 ; i < arr[frontNode].size(); i++) {
			if (visited[arr[frontNode][i]] == 0) {
				dist[arr[frontNode][i]] = dist[frontNode] + 1;
				q.push(arr[frontNode][i]);
				visited[arr[frontNode][i]] = 1;
			}
		}
	}
	return dist[destination];
}

int main() {
	memset(visited, 0, sizeof(visited));
	int t;
	cin >> t;
	while (t--) {
		int board[100] = {0};
		int n, l, s;
		cin >> n >> l >> s;
		while (l--) {
			int a, b;
			cin >> a >> b;
			board[a] = b - a;
		}

		while (s--) {
			int p, q;
			cin >> p >> q;
			board[p] = q - p;
		}

		for (int i = 1; i <= n; ++i)
		{
			for (int dice = 1; dice <= 6; ++dice)
			{
				int j = i + dice;
				j += board[j];

				if (j <= 100) {
					arr[i].push_back(j);
				}
			}
		}

		cout << bfs(1, n) << endl;

	}

	return 0;
}

