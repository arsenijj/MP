#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<iomanip>
#include<math.h>

using namespace std;

double f(double x, double y, double numx, double numy) {
    x = numx - x;
    y = numy - y;
    return (x * x + y * y);
}

pair<double, double> search(vector<pair<double, double>>& a, double rx, double lx, double ry, double ly, int n) {

    double eps = 1e-8;
    for (int j = 0; j < 50; ++j)
    {


        while (rx - lx > eps && ry - ly > eps) {

            double xm1 = lx + (rx - lx) / 3;
            double xm2 = rx - (rx - lx) / 3;

            double ym1 = ly + (ry - ly) / 3;
            double ym2 = ry - (ry - ly) / 3;

            double temp1 = 0;
            double temp2 = 0;
            double temp3 = 0;
            double temp4 = 0;

            for (int i = 0; i < n; i++) {
                temp1 += f(a[i].first, a[i].second, xm1, ym1);

                temp2 += f(a[i].first, a[i].second, xm1, ym2);

                temp3 += f(a[i].first, a[i].second, xm2, ym1);

                temp4 += f(a[i].first, a[i].second, xm2, ym2);

            }

            if (rx - lx > eps) {
                if (temp1 > temp3 && temp2 > temp4) lx = xm1;
                else rx = xm2;
            }

            if (ry - ly > eps) {
                if (temp1 > temp2 && temp3 > temp4) ly = ym1;
                else ry = ym2;
            }
        }
    }
    return make_pair(rx, ry);
}
int main() {

    int n;
    cin >> n;


    double tempx, tempy;

    double lx = 1e9;
    double rx = -1e9;

    double ly = 1e9;
    double ry = -1e9;

    vector<pair<double, double>> dots;

    for (int i = 0; i < n; i++) {

        cin >> tempx >> tempy;

        dots.push_back(make_pair(tempx, tempy));

        if (tempx > rx) rx = tempx;
        if (tempx < lx) lx = tempx;

        if (tempy > ry) ry = tempy;
        if (tempy < ly) ly = tempy;
    }

    double dot = 1e9;

    pair<double, double> res = search(dots, dot, -dot, dot, -dot, n);

    cout << res.first << " " << res.second;


    return 0;
}