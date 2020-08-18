#include<bits/stdc++.h>
using namespace std;
int main(int argc, char const *argv[])
{
	int b[] = {1, 2, 3};
	cout << b << endl;			//gives address of first element of the array

	char ch[] = {'a', 'b', 'c', '\0'};
	cout << ch << endl;

	char s[10];
	cin >> s;
	cout << s << endl;

	char s1[] = {'h', 'e', 'l', 'l', 'o'};
	char s2[] = {"hello"};
	cout << s1 << " " << sizeof(s1) << endl;
	cout << s2 << " " << sizeof(s2) << endl;
	return 0;
}