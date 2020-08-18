#include<bits/stdc++.h>
using namespace std;

bool sumK(int n, int* arr, int sum) {
    unordered_map<int, int> mp;

    for (int i = 0; i < n; i++)
    {
        if (mp.find(sum - arr[i]) != mp.end() and mp[sum - arr[i]] != i) {
            cout << arr[i] << " " << (sum - arr[i]) << endl;
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
    int sum = 7;
    int arr[n] = {3, 2, 4, -2, 9, 5};
    if (sumK(n, arr, sum)) {
        cout << "Numbers with sum " << sum<< " exists" << endl;
    }
    else {
        cout << "Numbers with sum " << sum << " doesn't exists" << endl;
    }
    return 0;
}