#include<bits/stdc++.h>
using namespace std;

int solve(int n, int arr[], int k) {
	unordered_map<int, int> mp;
	int prefixSum = 0;
	int maxLength = 0;

	for (int i = 0; i < n; ++i)
	{
		prefixSum += arr[i];

		if (prefixSum == k) {
			maxLength = max(i + 1, maxLength);
		}

		if (mp.find(prefixSum - k) != mp.end()) {
			int currLength = i - mp[prefixSum - k];
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
	n = 6;
	int k = 3;
	int arr[n] = {2, 1, 2, 0, -1, 2};
	cout << solve(n, arr, k) << endl;
	return 0;
}