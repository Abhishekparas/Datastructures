#include<bits/stdc++.h>
using namespace std;

void removeDuplicates(char arr[]) {
	int len = strlen(arr);
	if (len == 0 or len == 1) {
		return;
	}

	int prev = 0;

	for (int current = 1; current < len ; ++current)
	{
		if (arr[current] != arr[prev]) {
			prev++;
			arr[prev] = arr[current];
		}
	}
	arr[prev + 1] = '\0';
	return;

}

int main(int argc, char const *argv[])
{
	char arr[1000];
	cin.getline(arr, 1000);
	removeDuplicates(arr);
	cout << arr << endl;
	return 0;
}