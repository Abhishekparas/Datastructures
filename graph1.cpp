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

};
int main(int argc, char const *argv[])
{
	graph1 g(5);

	g.addEdge(0, 1);
	g.addEdge(0, 2);

	g.addEdge(3, 1);

	g.addEdge(3, 2);

	g.addEdge(2, 4);
	g.printList();

	return 0;
}
