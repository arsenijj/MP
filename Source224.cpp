#include<iostream>
#include<vector>
#include<limits>
using namespace std;


#define MAXDOUBLE = 1.797693E+308

int main() {

	int n;
	double c, v;

	vector<pair<double, double>> plus;
	vector<pair<double, double>> minus;

	for (int i = 0; i < n; i++) {

		cin >> c >> v;
		if (v < 0) minus.push_back(make_pair(c, v));
		else plus.push_back(make_pair(c, v));

	}

	res = MAXDOUBLE;

	for (int i = 0; i < minus.size(); i++) {
		double cM = minus[i].first;
		double vM = minus[i].second;

		for (int j = 0; j < plus.size(); j++)
		{
			double cP = plus[j].first;
			double vP = plus[j].second;

			if (cM < cP) break;
			double temp = max(cM, cP) / (vP + abs(vM));
			if (temp < res) res = temp;
		}


	}
	return 0;
}