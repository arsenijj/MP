#include <vector>
#include <iostream>
#include <algorithm>
#include <iomanip>
using namespace std;

pair<double, vector<int>> f(vector<pair<double, double>>& vec, double& x, int& k) {
	vector<pair<double, int>> cur;
	for (int i = 0; i < vec.size(); i++) {
		cur.push_back({ vec[i].second * x - vec[i].first, i + 1 });
	}

	sort(cur.begin(), cur.end());
	double sum = 0;
	vector<int> res;
	for (int i = 0; i < k; i++) {
		sum += cur[i].first;
		res.push_back(cur[i].second);
	}
	return { sum,res };
}

int main() {

	int n, k;
	double x, y;
	cin >> n >> k;

	vector<pair<double, double>> vec(n);

	for (int i = 0; i < n; i++) {
		cin >> vec[i].first >> vec[i].second;
	}

	double left = 1e-10;
	double right = 1e10;
	double eps = 1e-8;
	double sum;

	vector<int> result;

	while (right - left > eps) {

		double mid = (left + right) / 2;
		pair<double, vector<int>> sumAndVec = f(vec, mid, k);
		double sum = sumAndVec.first;

		if (sum >= 0) {
			right = mid;
			result = sumAndVec.second;
		}
		else left = mid;

	}
	cout << fixed << setprecision(9) << (right + left) / 2 << "\n";
	for (int i = 0; i < k; i++)
	{
		cout << result[i] << " ";
	}
	return 0;
}