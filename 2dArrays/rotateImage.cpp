#include<bits/stdc++.h>
using namespace std;

void rotate(int arr[][100], int n) {

	for (int row = 0; row < n; ++row)
	{
		int startCol = 0;
		int endCol = n - 1;
		while (startCol < endCol) {
			swap(arr[row][startCol], arr[row][endCol]);
			startCol++;
			endCol--;
		}
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i < j) {
				swap(arr[i][j], arr[j][i]);
			}
		}
	}
}

void rotateSTL(int arr[][100], int n) {
	for (int row = 0; row < n; ++row)
	{
		reverse(arr[row], arr[row] + n);
	}

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			if (i < j) {
				swap(arr[i][j], arr[j][i]);
			}
		}
	}
}

int main(int argc, char const *argv[])
{

	int arr[100][100];
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cin >> arr[i][j];
		}
	}

	rotateSTL(arr, n);

	for (int i = 0; i < n; ++i)
	{
		for (int j = 0; j < n; ++j)
		{
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}
	return 0;
}