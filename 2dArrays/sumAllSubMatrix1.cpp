#include<bits/stdc++.h>
using namespace std;

int sum(int arr[][10], int r, int c) {
	int sum = 0;
	for (int topLefti = 0; topLefti < r; ++topLefti)				//--
	{	//-- to compute top left
		for (int topLeftj = 0; topLeftj < c ; ++topLeftj)			//--
		{
			for (int bottomrighti = topLefti; bottomrighti < r; ++bottomrighti)					//--
			{	//-- to compute bottom right
				for (int bottomrightj = topLeftj; bottomrightj < c ; ++bottomrightj)			//--
				{
					for (int i = topLefti; i <= bottomrighti; ++i)			//--
					{	//-- to compute the sum of the sub matrix
						for (int j = topLeftj; j <= bottomrightj; ++j)		//--
						{
							sum += arr[i][j];
						}
					}
				}
			}
		}
	}
	return sum;
}

int main(int argc, char const *argv[])
{
	int arr[10][10] = {{1, 1}, {1, 1}};
	cout << sum(arr, 2, 2);
	return 0;
}