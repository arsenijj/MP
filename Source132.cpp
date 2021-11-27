#include<vector>
#include<iostream>
#include<algorithm>
#include<string>

using namespace std;

void heapify(vector<string>& a, int i, vector<int>& res) {

	int size = a.size();
	int largest = i;

	int l = 2 * i + 1;
	int r = 2 * i + 2;

	if (l < size && a[l] > a[largest]) {
		largest = l;
	
	}

	if (r < size && a[r] > a[largest]) {
		largest = r;
	}

	

	if (largest != i) {
		
		swap(a[i], a[largest]);
		swap(res[i], res[largest]);
		heapify(a, largest,res);
	}

}

int main() {

	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);

	int n;
	cin >> n;

	vector<string> heap(n);
	
	string temp;

	vector<int> res1(n);

	for (int i = 0; i < n; i++) {
		cin >> temp;
		heap[i] = temp;
		res1[i] = i + 1;

	}


	vector<int> res(n);

	for (int i = n / 2 - 1; i >= 0; i--) {
		heapify(heap, i, res1);
	}

	for (int i = 0; i < n; i++) {
		res[res1[i] - 1] = i + 1;
	}

	for (int i = 0; i < n; i++) {

		cout <<res[i] << "\n";
		
	}


	return 0;
}