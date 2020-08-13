#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	char arr[][10] = {{'a', 'b', 'c', '\0'}, {'d', 'e', 'f', '\0'}};		//2 rows 10 columns
	cout << arr[0] << endl;
	cout << arr[1] << endl;

	char mat[][10] = {"abcd", "efgh", "ijkl", "mnop"};   //4 rows 10 columns
	cout << mat[1] << endl;
	cout << mat[3] << endl;
	return 0;
}