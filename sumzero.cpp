#include <bits/stdc++.h>
using namespace std;
bool issumzero(int* arr, int n) {
	unordered_map<int, int> mp;
	for (int i = 0; i < n; ++i)
	{	int x = -1 * arr[i];
		if (mp.count(x)) {
			cout << arr[i] << " " << -1 * arr[i] << endl;
			return true;
		}
		else {
			mp[arr[i]] = i;
		}
	}
	return false;
}
int main(int argc, char const *argv[])
{
	int n;
	n = 6;
	int arr[10] = {3, 2, 4, -1, -2, -5};
	if (issumzero(arr, n)) {
		cout << "found";
	}
	else {
		cout << "not found";
	}
	return 0;
}