#include<bits/stdc++.h>
using namespace std;

int main(){
	vector<int> adj[10];			//an array of vectors
	int x,y,nodes,edges;
	cin>>nodes>>edges;
	for(int i=0; i<edges; i++){
		cin>>x>>y;
		adj[x].push_back(y);
	}
	
	for(int i=1; i<= nodes; i++){
		cout<<"Node "<<i<<" :";
		for(int j=0;j <adj[i].size(); j++){
			cout<<adj[i][j]<<"-->";
		}
		cout<<endl;
	}
	
	return 0;
}
