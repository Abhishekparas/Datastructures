#include<bits/stdc++.h>
using namespace std;

vector<int> primes;
void sieve(int p[10005]) {

    for (int i = 3; i <= 10005; i += 2) {
        p[i] = 1;
    }
    for (int i = 3; i <= 10005; i += 2) {
        if (p[i] == 1) {
            for (int j = i * i; j <= 10005; j = j + i) {
                p[j] = 0;
            }
        }
    }
    p[2] = 1;
    p[1] = p[0] = 0;
    for (int i = 2; i < 10005; i++) {
        if (p[i] == 1) {
            primes.push_back(i);
        }
    }
    return;
}

int main() {
    int n, q;
    cin >> n >> q;
    int arr[10005] = {0};
    sieve(arr);
    stack<int> st;
    for (int i = 1; i <= n; i++) {
        int num;
        cin >> num;
        st.push(num);
    }

    for (int i = 1; i <= q; i++) {
        stack<int> A;
        stack<int> B;
        while (!st.empty()) {
            if (st.top() % primes[i - 1] == 0) {
                B.push(st.top());
            }
            else {
                A.push(st.top());
            }
            st.pop();
        }


        while (!B.empty()) {
            cout << B.top() << endl;
            B.pop();
        }
        st = A;

    }
    while (!st.empty()) {
        cout << st.top() << endl;
        st.pop();
    }
    return 0;
}