#include <bits/stdc++.h>
using namespace std;

class graph {
	unordered_map<int, list<int> > mp;
public:

	void addEdge(int x, int y, bool bidirectional = true) {
		mp[x].push_back(y);
		if (bidirectional) {
			mp[y].push_back(x);
		}
	}

	void bfs(int source) {
		map<int, int> distance;
		// node,distance
		queue<int> q;

		q.push(source);
		distance[source] = 0;

		while (! q.empty()) {
			int frontnode = q.front();
			q.pop();
			//cout << frontnode << ", ";

			for (auto nbr : mp[frontnode]) {
				if (distance.count(nbr) == 0) {
					q.push(nbr);
					distance[nbr] = distance[frontnode] + 1;
				}
			}
		}
		//cout << endl;
		for (auto dis : distance) {
			int vertex = dis.first;

			if (dis.second != 0) {
				cout << dis.second * 6 << " ";
			}
		}
		cout << endl;

	}

};

int main(int argc, char const *argv[])
{
	graph g;
	int q;
	cin >> q;
	while (q--) {
		int n, m;
		cin >> n >> m;
		while (m--) {
			int u, v;
			cin >> u >> v;
			g.addEdge(u, v);
		}
		int source;
		cin >> source;
		g.bfs(source);
		//g.printlist();
	}

	return 0;
}
