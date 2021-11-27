#include<iostream>
#include<vector>
#include<random>
#include <cstdlib> 

using namespace std;

//mt19937 gen32;

pair<int, int> partition(vector<int>& a, int l, int r, int p) {

	int i = l;
	int j = r;

	while (i <= j) {
		while (i <= r && a[i] < p) i++;
		while (a[j] > p && j >= l) j--;
		if (i <= j) 
			swap(a[i], a[j]);
	i++;
	j--;	
	}
	return make_pair(i, j);

}

void q_sort(vector<int>& a, int l, int r) {

	int p = a[(l + r) / 2];
	pair<int, int> ij = partition(a, l, r, p);
	int i = ij.first;
	int j = ij.second;
	if (l < j) q_sort(a, l, j);
	if (i < r) q_sort(a, i, r);

}


int main() {
	
	vector<int> myVec;
	int n;
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		myVec.push_back(rand());
		//int temp;
		//cin >> temp;
		//myVec.push_back(temp);
		cout << myVec[i] << " ";
	}
	cout << "\n";

	q_sort(myVec, 0, myVec.size() - 1);
	for (int i = 0; i < n; i++) {
		cout << myVec[i] << " ";
	}
	return 0;
}