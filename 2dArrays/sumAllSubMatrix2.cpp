#include<bits/stdc++.h>
using namespace std;

void prefixComputation(int arr[][10], int prefixMatrix[][10], int r, int c) {
	// initialize the first row fo the prefix matrix with the first row of the array

	for (int i = 0; i < c; ++i)
	{
		prefixMatrix[0][i] = arr[0][i];
	}

	// columnwise sum

	for (int i = 1; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			prefixMatrix[i][j] = prefixMatrix[i - 1][j] + arr[i][j];
		}
	}

	// rowwise sum
	for (int i = 0; i < r ; ++i)
	{
		for (int j = 1; j < c ; ++j)
		{
			prefixMatrix[i][j] += prefixMatrix[i][j - 1];
		}
	}
}

int sumAllSubmatrix(int arr[][10], int prefixMatrix[][10], int r, int c) {

	int sum = 0;

	for (int topleftI = 0; topleftI < r ; ++topleftI)
	{
		for (int topleftJ = 0; topleftJ < c ; ++topleftJ)
		{
			for (int bottomrightI = topleftI; bottomrightI < r ; ++bottomrightI)
			{
				for (int bottomrightJ = topleftJ; bottomrightJ < c ; ++bottomrightJ)
				{
					int subMatrixSum = prefixMatrix[bottomrightI][bottomrightJ];

					if (topleftI > 0) {
						subMatrixSum -= prefixMatrix[topleftI - 1][bottomrightJ];
					}

					if (topleftJ > 0) {
						subMatrixSum -= prefixMatrix[bottomrightI][topleftJ - 1];
					}

					if (topleftI > 0 and topleftJ > 0) {
						subMatrixSum += prefixMatrix[topleftI - 1][topleftJ - 1];
					}
					cout << subMatrixSum << endl;
					sum += subMatrixSum;
				}
			}
		}
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	int arr[][10] = {{1, 1}, {1, 1}};

	int prefixMatrix[10][10] = {0};

	int r = 2;
	int c = 2;
	prefixComputation(arr, prefixMatrix, r, c);

	for (int i = 0; i < r; ++i)
	{
		for (int j = 0; j < c; ++j)
		{
			cout << prefixMatrix[i][j] << " ";
		}
		cout << endl;
	}

	int result = sumAllSubmatrix(arr, prefixMatrix, r, c);
	cout << result << endl;

	return 0;
}