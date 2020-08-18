#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	char arr[100][1000];
	int n;
	cin >> n;
	cin.get();

	for (int i = 0; i < n; ++i)
	{
		cin.getline(arr[i], 1000);				//on every row of array arr[][],insert a string of max length 1000
	}
	for (int i = 0; i < n; ++i)
	{
		cout << arr[i] << endl;
	}

	return 0;
}