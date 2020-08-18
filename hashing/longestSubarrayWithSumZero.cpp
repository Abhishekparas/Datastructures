#include<bits/stdc++.h>
using namespace std;

int solve(int n, int arr[]) {
	unordered_map<int, int> mp;
	int prefixSum = 0;
	int maxLength = 0;

	for (int i = 0; i < n; ++i)
	{
		prefixSum += arr[i];

		if (arr[i] == 0 and maxLength == 0) {			//example : {3,4,0}
			maxLength = 1;
		}

		if (prefixSum == 0) {
			maxLength = max(i + 1, maxLength);			//if prefixSum comes out to be zero, it means from 0th index to that index,the array is having 0 sum,therefore we also have to include 0th index, so we add 1 to i
		}

		if (mp.find(prefixSum) != mp.end()) {
			int currLength = i - mp[prefixSum];
			maxLength = max(currLength, maxLength);
		}
		else {
			mp.insert({prefixSum, i});
		}
	}
	return maxLength;
}

int main(int argc, char const *argv[])
{
	int n;
	n = 8;
	int arr[n] = {3, 0, -1, 2, -1, 0, 1, -4};
	cout << solve(n, arr) << endl;
	return 0;
}