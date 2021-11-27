#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;

int main() {

	double c, t;
	cin >> c >> t;

	double l = 0;
	double r = 76374950.90348;
	double eps = 1e-14;
	double res = 1;

	while (r - l > r * eps) {

		double mid = (r + l) / 2;
		
		double temp = c * mid * log2(mid);
		
		if (temp > t) r = mid;
		else {
			l = mid;
			res = mid;
		}


	}
	cout << fixed << setprecision(9) << res;
	return 0;
}