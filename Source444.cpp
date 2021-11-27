#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<c.math>

using namespace std;

int main() {
	double c, t;
	cin >> c >> t;

	double l = 1;
	double r = 2000000000;
	double eps = 1e-9;
	//n* n < 2 ^ (t / c)
	double tc = t / c;

	double limit = pow(2, (tc));
	while (l - r > r * eps) {
		double rlmid = (r - l) / 2;
			double temp = pow(rlmid, rlmid);


	}
	return 0;
}
