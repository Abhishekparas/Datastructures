#include<bits/stdc++.h>
using namespace std;

bool staircaseSearch(int mat[][100], int m, int n, int key) {
	int i = 0;
	int j = n - 1;
	while (i < m and j >= 0) {
		if (mat[i][j] == key) {
			return true;
		}
		if (mat[i][j] < key) {
			i++;
		}
		else {
			j--;
		}
	}
	return false;
}

int main(int argc, char const *argv[])
{
	int arr[100][100];
	int m, n;
	cin >> m >> n;
	for (int i = 0; i < m; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> arr[i][j];
		}
	}
	int key = 17;
	if (staircaseSearch(arr, m, n, key)) {
		cout << key << " found" << endl;
	}
	else {
		cout << key << " not found" << endl;
	}
	return 0;
}