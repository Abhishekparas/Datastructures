/*
 * Filename: c:\Users\Abhishek\Documents\graphs\dijkstra.cpp
 * Path: c:\Users\Abhishek\Documents\graphs
 * Created Date: Tuesday, July 14th 2020, 5:24:20 pm
 * Author: abhishek
 *
 * Copyright (c) 2020 Your Company
 */

#include <bits/stdc++.h>
using namespace std;
vector<pair<int, int> > arr[10];
bool visited[10];
int dist[10];

void dijkstra() {
	memset(visited, 0, sizeof(visited));
	for (int i = 0; i < 10; i++) {
		dist[i] = INT_MAX;
	}
	dist[1] = 0; 		//source vertex is assumed to be 1
	multiset<pair<int, int> > s;
	s.insert({0, 1}); 		//distance and node because we want the shortest distance on top of set

	while (!s.empty()) {
		pair<int, int> p = *(s.begin());
		s.erase(s.begin());

		int weight = p.first;
		int node = p.second;

		if (!visited[node]) {
			for (int nbr = 0; nbr < arr[node].size(); nbr++) {
				int edge = arr[node][nbr].first;
				int wt = arr[node][nbr].second;
				if (dist[node] + wt < dist[edge]) {
					dist[edge] = dist[node] + wt;
					s.insert({dist[edge], edge});
				}
			}
		}
	}
}

int main(int argc, char const *argv[])
{
	int nodes, edges;
	cin >> nodes >> edges;
	for (int i = 0; i < edges; i++)
	{
		int x, y, weight;
		cin >> x >> y >> weight;
		arr[x].push_back({y, weight});
		arr[y].push_back({x, weight});
	}
	dijkstra();
	for (int i = 1; i < 5; i++)
	{
		cout << dist[i] << " ";
	}



	return 0;
}