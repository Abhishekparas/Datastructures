#include<bits/stdc++.h>
using namespace std;
vector<int> arr[10];
bool visited[10];

void dfs(int source){
	cout<<source<<" ";
	visited[source] = 1;
	for(int i=0; i<arr[source].size(); i++){
		if(visited[arr[source][i]] == 0)
		dfs(arr[source][i]);
	}
}

int main(){
	memset(visited,0,sizeof(visited));
	int nodes;
	int edges;
	cin>>nodes;
	cin>>edges;
	for(int i=0; i<edges; i++){
		int x,y;
		cin>>x>>y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}
	dfs(1);

	
	return 0;
}

