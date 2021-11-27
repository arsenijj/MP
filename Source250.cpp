#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


bool cmp(pair<int, int> p1, pair<int, int> p2) {
	if (p1.first == p2.first) return p1.second > p2.second;
	if (p1.first > p2.first) return false;
	if (p1.first < p2.first) return true;

}

int main() {

	int n;
	vector<pair<int, int>> myVec;

	cin >> n;
	for (int i = 0; i < n; i++) {
		int tempX, tempY;
		cin >> tempX >> tempY;
		myVec.push_back(make_pair(tempX, 1));
		myVec.push_back(make_pair(tempY, 0));
	}
	sort(myVec.begin(), myVec.end(), cmp);

	int counter = 0;
	int max = 0;

	for (int i = 0; i < 2 * n; i++) {
		if (myVec[i].second == 1) {
			++counter;
			if (counter > max) {
				max = counter;
			}
		}
		else --counter;
	}

	counter = 0;
	int goodDots = 0;
	int currStart = 0;

	for (int i = 0; i < 2 * n; i++) {

		if (myVec[i].second == 1) {
			++counter;
			if (counter == max) {
				currStart = myVec[i].first;
			}
		}
		else if (counter == max && myVec[i].second == 0) {
			--counter;
			goodDots = goodDots + abs(myVec[i].first - currStart) + 1;

		}
		else
			--counter;
	}

	cout << goodDots;

	return 0;
}



