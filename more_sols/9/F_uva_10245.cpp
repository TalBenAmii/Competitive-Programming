#include <bits/stdc++.h>


using namespace std;


typedef pair<double, double> Point;
#define x first
#define y second

double dist(const Point& a, const Point& b) {
    return hypot(a.x - b.x, a.y - b.y);
}

#define INF 1e9

int main() {
    ios_base::sync_with_stdio();
    cin.tie(0);
    cout << fixed << setprecision(4);

    int n;
    while (cin >> n && n) {
        vector<Point> v(n);
        for (int i = 0; i < n; ++i) {
            cin >> v[i].x >> v[i].y;
        }

        sort(v.begin(), v.end());
        double d = INF;
        for (auto i = v.begin(); i != v.end(); ++i) {
            Point left{i->x - d, i->y};
            for (auto j = lower_bound(v.begin(), i, left); j != i; ++j) {
                d = min(d, dist(*i, *j));
            }
        }

        if (d < 1e4) {
            cout << d << endl;
        } else {
            cout << "INFINITY" << endl;
        }
    }

    return 0;
}
