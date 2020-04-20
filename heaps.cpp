#include<bits/stdc++.h>
using namespace std;
#define pb push_back
//max heap
void upheapify(vector<int> &v, int index) {
	if (index == 0) {
		return;
	}

	int parentindex = (index - 1) / 2;
	if (v[index] > v[parentindex]) {
		swap(v[index], v[parentindex]);
		upheapify(v, parentindex);
	}
	else {
		return;
	}
}
void insert(vector<int> &v, int num) {
	v.pb(num);
	upheapify(v, v.size() - 1) ;// this num element is pushed at the end of the vector
}
void print(vector<int> v) {
	for (int i = 0; i < v.size(); ++i)
	{
		cout << v[i] << " ";
	}
	cout << endl;

}
void downheapify(vector<int> &v, int index) {
	int leftchildindex = (2 * index) + 1;
	int rightchildindex = (2 * index) + 2;
	// index is leaf node
	if (leftchildindex >= v.size() and rightchildindex >= v.size()) {
		return;
	}
	int largechildindex = index;
	if (leftchildindex <v.size() and v[leftchildindex] > v[index]) {
		largechildindex = leftchildindex;
	}
	if (rightchildindex<v.size() and v[rightchildindex] >v[largechildindex]) {
		largechildindex = rightchildindex;
	}
	if (largechildindex == index) {
		return;
	}
	swap(v[index], v[largechildindex]);
	downheapify(v, largechildindex);

}
void deleteroot(vector<int> &v) {
	swap(v[0], v[v.size() - 1]);
	v.pop_back(); // the element at v[v.size() -1] will be deleted
	downheapify(v, 0);
}
void deletenode(vector<int> &v, int index) {
	v[index] = INT_MAX;
	upheapify(v, index);
	deleteroot(v);
}
void buildheap(vector<int> &v) {
	for (int i = 0; i < v.size(); ++i)
	{
		upheapify(v, i);
	}
}
void buildheapoptimised(vector<int> &v) {
	for (int i = v.size() - 1; i >= 0; i--)
	{
		downheapify(v, i);
	}
}
int main(int argc, char const *argv[])
{
	vector<int> v;
	/*insert(v, 10);
	insert(v, 5);
	insert(v, 1);
	insert(v, 12);
	insert(v, 190);
	insert(v, 18);
	print(v);
	deleteroot(v);
	print(v);
	deletenode(v, 2); // 1 will be deletd
	print(v);*/
	int n;
	cin >> n;
	for (int i = 0; i < n; ++i)
	{
		/* code */
		int element;
		cin >> element;
		v.pb(element);
	}
	print(v);
	/*buildheap(v);
	print(v);*/
	buildheapoptimised(v);
	print(v);
	return 0;
}