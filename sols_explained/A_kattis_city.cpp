#include <bits/stdc++.h>


using namespace std;

typedef long long ll;
typedef vector<int> vi;
typedef vector<ll> vll;


const int MAX_N = 1e4;
const int MAX_HP = 1e9;
const ll INF = (ll) MAX_HP * MAX_N;


struct Building {
    int hp;
    int dmg;
};
vector<Building> buildings;
int n, d;

int calcMoves(int hp) {
    if (hp <= 0) return 0;
    return ceil((double) hp / d);
}

int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        cin >> n >> d;
        buildings = vector<Building>(n);
        for (int i = 0; i < n; ++i) {
            cin >> buildings[i].hp;
        }
        for (int i = 0; i < n; ++i) {
            cin >> buildings[i].dmg;
        }
        if (n == 1) {
            cout << calcMoves(buildings[0].hp) << endl;
            continue;
        }

        // dp[i][j] = min moves to destroy buildings 0...i, such that the next building (i+1) already exploded iff j == true
        vector<vll> dp(n, vll(2, INF));
        dp[0][0] = calcMoves(buildings[0].hp);
        dp[0][1] = calcMoves(buildings[0].hp - buildings[1].dmg);
        for (int i = 1; i < n; ++i) {
            int hp = buildings[i].hp;
            for (int j = 0; j < 2; ++j) {
                dp[i][j] = min(dp[i - 1][1] + calcMoves(hp),
                               dp[i - 1][0] + calcMoves(hp - buildings[i - 1].dmg));
                if (i < n - 1) hp -= buildings[i + 1].dmg;
            }
        }
        cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
    }

    return 0;
}