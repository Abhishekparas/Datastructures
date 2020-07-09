#include <bits/stdc++.h>
using namespace std;

class graph {
	unordered_map<string, list<string> > mp;
public:

	void addEdge(string x, string y, bool bidirectional = true) {
		mp[x].push_back(y);
		if (bidirectional) {
			mp[y].push_back(x);
		}
	}

	void bfs(string source) {
		unordered_map<string, int> distance;
		// node,distance
		queue<string> q;

		q.push(source);
		distance[source] = 0;

		while (! q.empty()) {
			string frontnode = q.front();
			q.pop();
			cout << frontnode << ", ";

			for (auto nbr : mp[frontnode]) {
				if (distance.count(nbr) == 0) {
					q.push(nbr);
					distance[nbr] = distance[frontnode] + 1;
				}
			}
		}
		cout << endl;
		for (auto dis : distance) {
			string vertex = dis.first;

			cout << vertex << "----> " << dis.second << ",  ";
		}
		cout << endl;

	}

	void printlist() {
		for (auto pr : mp) {
			string vertex = pr.first;

			cout << vertex << "----> ";
			for (auto nbr : pr.second) {

				cout << nbr << ", ";
			}
			cout << endl;
		}
	}

};

int main(int argc, char const *argv[])
{
	graph g;

	g.addEdge("A", "B");
	g.addEdge("A", "C");
	g.addEdge("B", "D");
	g.addEdge("B", "C");
	g.addEdge("D", "E");
	g.addEdge("C", "E");

	g.bfs("A");

	g.printlist();

	return 0;
}
