#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int n;
	cin >> n;

	char arr[1000];
	char largest[1000];

	cin.get();
	int l = 0;
	int maxL = 0;
	while (n--) {
		cin.getline(arr, 1000);
		l = strlen(arr);
		if (l > maxL) {
			maxL = l;
			strcpy(largest, arr);
		}
	}
	cout << largest << " " << maxL << endl;
	return 0;
}

//read n strings and find the largest among them