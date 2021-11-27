#include<iostream>
#include<vector>
#include <iomanip> 

using namespace std;

int main() {

	float s, p;
	int m;

	cin >> s >> m >> p;

	double temphehe = (100 + p) / 100;
	double accum = (100 + p) / 100;

	double currentSum = 1;

	for (int i = 1; i < m; i++)
	{
		currentSum = currentSum + accum;
		accum *= temphehe;

	}


	double x = accum * s / currentSum;

	cout << fixed << setprecision(5) << x;
}
