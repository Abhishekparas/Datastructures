#include<bits/stdc++.h>
using namespace std;

void readLine(char arr[], int maxLen,char delim = '\n') {
	int i = 0;
	char c = cin.get();

	while (c != delim) {
		arr[i] = c;
		i++;
		if (i == maxLen - 1) {
			break;
		}
		c = cin.get();
	}
	arr[i] = '\0';
	return;
}

int main(int argc, char const *argv[])
{
	char ch[1000];
	//readLine(ch, 1000,'$');
	cin.getline(ch,1000,'%');
	cout << ch << endl;
	return 0;
}