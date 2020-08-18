#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int arr[10][10];
	for (int row = 0; row < 3; ++row)
	{
		for (int column = 0; column < 4; ++column)
		{
			cin >> arr[row][column];
		}
	}

	for (int column = 0; column < 4; ++column)
	{
		if (column % 2 == 0) {
			for (int row = 0; row < 3; ++row)
			{
				cout << arr[row][column] << " ";
			}
		}
		else {
			for (int row = 2; row >= 0; row--)
			{
				cout << arr[row][column] << " ";
			}
		}
	}

	return 0;
}