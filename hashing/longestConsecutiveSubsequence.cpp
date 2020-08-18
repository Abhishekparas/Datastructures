#include<bits/stdc++.h>
using namespace std;

int longestConSub(int n, int arr[]) {
	unordered_map<int, bool> mp;
	for (int i = 0; i < n; ++i)
	{
		mp[arr[i]] = true;
	}

	for (int i = 0; i < n; ++i)
	{
		if (mp.count(arr[i] - 1)) {
			mp[arr[i]] = false;
		}
	}

	int maxLength = INT_MIN;
	int maxStartPoint = 0;


	for (int i = 0; i < n; ++i)
	{
		if (mp[arr[i]] == true) {
			int tempLength = 1;
			int tempStartPoint = arr[i];
			while (mp.count(tempStartPoint + tempLength)) {								//suppose if i get 5 as true, then i have to consider templen as 1 beacus of single element 5,if if find templen +5 i.e 6 then i will update templent to 2, the i will search for templen + 5 i.e 7 and continue for values that are true
				tempLength++;
			}
			if (tempLength > maxLength) {
				maxStartPoint = tempStartPoint;
				maxLength = tempLength;
			}
		}
	}
	for (int i = 0; i < maxLength; ++i)
	{
		cout << maxStartPoint + i << endl;
	}
	return maxLength;
}

int main(int argc, char const *argv[])
{
	int n = 11;
	int arr[] = {10, 5, 9, 1, 11, 8, 6, 15, 3, 12, 2};
	cout << longestConSub(n, arr) << endl;
	return 0;
}

/*
Subsequences possible:
1,2,3
5,6
8,9,10,11,12 -->maxLength
15
*/