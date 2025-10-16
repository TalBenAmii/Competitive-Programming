#include <bits/stdc++.h>


using namespace std;

#define st first
#define nd second
#define gcd(x, y) __gcd((x),(y))

typedef pair<int, int> ii;

const int W = 2e7;

struct cmp {
    bool operator()(const ii& a, const ii& b) const {
        return (double) a.nd / a.st > (double) b.nd / b.st;
    }
};

int main() {
    ios_base::sync_with_stdio();
    cin.tie(0);

    int n;
    cin >> n;
    int m = n / 4 + 1;
    int s = 2; // height + width
    set<ii, cmp> slopes;
    bool found = false;
    while (!found) {
        for (int dx = 1; dx < s; ++dx) {
            int dy = s - dx;
            int g = gcd(dx, dy);
            slopes.insert({dx / g, dy / g});
            if (slopes.size() >= m) {
                found = true;
                break;
            }
        }
        ++s;
    }

    int x = W, y = W;
    for (auto p : slopes) { x -= p.st; }


    for (auto p : slopes) {
        x += p.st;
        y += p.nd;
        cout << x << " " << y << endl;
        --n;
        if (!n) return 0;
    }

    for (auto it = slopes.rbegin(); it != slopes.rend(); ++it) {
        auto p = *it;
        x += p.st;
        y -= p.nd;
        cout << x << " " << y << endl;
        if (!--n) return 0;
    }

    for (auto p : slopes) {
        x -= p.st;
        y -= p.nd;
        cout << x << " " << y << endl;
        if (!--n) return 0;
    }

    for (auto it = slopes.rbegin(); it != slopes.rend(); ++it) {
        auto p = *it;
        x -= p.st;
        y += p.nd;
        cout << x << " " << y << endl;
        if (!--n) return 0;
    }

    return 0;
}
