#include <bits/stdc++.h>
using namespace std;

bool arr[10][10];


int main(int argc, char const *argv[])
{	

	memset(arr,0,sizeof(arr));

	int x,y,nodes,edges;

	cin>>nodes>>edges;

	for (int i = 0; i < edges; ++i)
	{
		cin>>x>>y;			//there is edge between x and y
		arr[x][y] = 1;
	}
	if(arr[3][4] == 1){
		cout<<"There is an edge between 3 and 4"<<endl;
	}

	if(arr[2][3] == 1){
		cout<<"There is an edge between 2 and 3"<<endl;
	}
	else{
		cout<<"There is no edge between 2 and 3"<<endl;
	}

	return 0;
}
