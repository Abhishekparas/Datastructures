#include<bits/stdc++.h>
using namespace std;
vector<int> arr[10];
bool visited[10];

void bfs(int source){
	queue<int> q;
	q.push(source);
	visited[source] = true;
	
	while(!q.empty()){
		int frontNode = q.front();
		q.pop();
		cout<<frontNode<<" ";
		for(int i=0 ;i<arr[frontNode].size(); i++){
			if(visited[arr[frontNode][i]] == 0){
				q.push(arr[frontNode][i]);
				visited[arr[frontNode][i]] = 1;
			}
		}
	}
}

int main(){
	memset(visited,0,sizeof(visited));
	int nodes;
	int edges;
	cin>>nodes;
	cin>>edges;
	for(int i=0 ;i<edges; i++){
		int x,y;
		cin>>x>>y;
		arr[x].push_back(y);
		arr[y].push_back(x);
	}
	bfs(0);

	return 0;
}

