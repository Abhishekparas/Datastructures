#include<bits/stdc++.h>
using namespace std;

vector<int> arr[10];
bool visited[10];

void dfs(int source){
	visited[source] = 1;
	for(int i=0 ;i<arr[source].size(); i++){
		if(visited[arr[source][i]] == 0){
			dfs(arr[source][i]);
		}
	}
}

int main(){
	memset(arr,0,sizeof(visited));
	int nodes;
	int edges;
	int connectedComponents = 0;
	cin>>nodes;
	cin>>edges;
	for(int i=0; i<edges; i++){
		int x,y;
		cin>>x>>y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}
	for(int i=1; i<= nodes; i++){
		if(visited[i] == 0){
			dfs(i);
			connectedComponents++;
		}
	}
	cout<<"Number Of Connected Components --->"<<connectedComponents;
	

	return 0;
}

