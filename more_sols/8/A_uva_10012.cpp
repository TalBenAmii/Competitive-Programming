#include <bits/stdc++.h>

using namespace std;

typedef long double ld;
typedef vector<ld> vld;
const int INF = 1e9;

ld calcDist(ld r1, ld r2) {
    ld c = r1 + r2;
    ld a = r1 - r2;
    return sqrt(c*c - a*a);
}

int main() {
    cout << fixed << setprecision(3);
    int n; cin >> n;
    while (n--) {
        int m; cin >> m;
        vector<ld> r(m);
        for (int i = 0; i < m; ++i) {
            cin >> r[i];
        }

        sort(r.begin(), r.end());
        vld positions(m);
        ld minWidth = INF;
        do {
            positions[0] = 0;
            for (int i = 1; i < m; ++i) {
                ld x = -INF;
                for (int j = 0; j < i; ++j) {
                    x = max(x, positions[j] +  calcDist(r[j], r[i]));
                }
                positions[i] = x;
            }

            ld startX = INF, endX = -INF;
            for (int i = 0; i < m; ++i) {
                startX = min(startX, positions[i] - r[i]);
                endX = max(endX, positions[i] + r[i]);
            }
            minWidth = min(minWidth, endX - startX);

        } while (next_permutation(r.begin(), r.end()));

        cout << minWidth << endl;
    }

    return 0;
}
