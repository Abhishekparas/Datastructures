#include<bits/stdc++.h>
using namespace std;

bool subarrayWithSumZero(int n, int* arr) {
    unordered_map<int, int> mp;
    int prefixSum = 0;

    for (int i = 0; i < n; i++)
    {
        prefixSum += arr[i];

        if (prefixSum == 0 or (mp.find(prefixSum) != mp.end() and mp[prefixSum] != i)) {
            cout << mp[prefixSum] + 1 << " " << i << endl;
            return true;
        }

        else {
            mp.insert({arr[i], i});
        }
    }
    return false;
}

int main() {
    int n = 6;
    int arr[n] = {5, 4, -3, -1, 2, 1};
    if (subarrayWithSumZero(n, arr)) {
        cout << "sum zero exists" << endl;
    }
    else {
        cout << "Sum zero doesn't exist" << endl;
    }

    return 0;
}