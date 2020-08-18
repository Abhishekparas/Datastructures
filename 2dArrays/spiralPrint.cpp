#include<bits/stdc++.h>
using namespace std;

void spiralPrint(int arr[][100], int m, int n) {
	int startRow = 0;
	int startCol = 0;
	int endRow = m - 1;
	int endCol = n - 1;

	while (startRow <= endRow and startCol <= endCol) {

		for (int i = startCol; i <= endCol ; ++i)
		{
			cout << arr[startRow][i] << " ";
		}
		startRow++;

		for (int i = startRow; i <= endRow ; ++i)
		{
			cout << arr[i][endCol] << " ";
		}
		endCol--;

		if (startRow < endRow) {
			for (int i = endCol; i >= startCol; i--)
			{
				cout << arr[endRow][i] << " ";
			}
			endRow--;
		}

		if (startCol < endCol) {
			for (int i = endRow; i >= startRow; i--)
			{
				cout << arr[i][startCol] << " ";
			}
			startCol++;
		}
	}
}

int main(int argc, char const *argv[])
{
	int arr[100][100] = {0};
	int m, n;
	cin >> m >> n;
	int val = 1;
	for (int i = 0; i <= m - 1; ++i)
	{
		for (int j = 0; j <= n - 1; ++j)
		{
			arr[i][j] = val;
			val++;
			cout << arr[i][j] << " ";
		}
		cout << endl;
	}

	spiralPrint(arr, m, n);

	return 0;
}