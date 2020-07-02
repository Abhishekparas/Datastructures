#include <bits/stdc++.h>
using namespace std;
class graph1
{
	int V;
	list<int>* arr;
public:
	graph1(int v) {
		V = v;
		arr = new list<int>[V];
	}

	void addEdge(int x, int y) {
		arr[x].push_back(y);
		arr[y].push_back(x);
	}

	void printList() {
		for (int i = 0; i < V; ++i)
		{
			cout << i << "---->";
			for (auto nbr : arr[i]) {
				cout << nbr << " ";
			}
			cout << endl;
		}
	}

	void bfs(int source) {				//it is same as level order traversal of a tree
		bool* visited = new bool[V];
		queue<int> q;

		q.push(source);
		visited[source] = true;

		while (! q.empty()) {
			int frontnode = q.front();
			q.pop();
			cout << frontnode << ", ";

			for (int nbr : arr[frontnode]) {
				if (! visited[nbr]) {
					q.push(nbr);
					visited[nbr] = true;
				}
			}
		}
		cout << endl;
	}

};
int main(int argc, char const *argv[])
{
	graph1 g(5);

	g.addEdge(0, 1);
	g.addEdge(0, 3);

	g.addEdge(1, 3);

	g.addEdge(1, 2);

	g.addEdge(2, 3);
	g.addEdge(3, 4);

	g.bfs(0);

	g.printList();

	return 0;
}
