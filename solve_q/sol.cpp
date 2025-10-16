#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

int dp[3 * 100000 + 5][3][8];
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    rep(i, 0, n + 1)
    {
        rep(j, 0, 3)
        {
            rep(k, 0, 8)
            {
                dp[i][j][k] = -1e9;
            }
        }
    }
    vi v(n);
    rep(i, 0, n)
    {
        cin >> v[i];
    }
    dp[0][0][0b110] = 0;
    dp[0][1][0b101] = 0;
    dp[0][2][0b011] = 0;

    rep(i, 0, n)
    {
        rep(j, 0, 3)
        {
            rep(k, 0, 8)
            {
                if (v[i] == j)
                {
                    dp[i + 1][j][k] = max(dp[i + 1][j][k], 1 + dp[i][j][k]);
                }
                else
                {
                    dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k]);
                    if (k & (1 << v[i]))
                        dp[i + 1][v[i]][k ^ (1 << v[i])] = max(dp[i + 1][v[i]][k ^ (1 << v[i])], 1 + dp[i][j][k]);
                }
            }
        }
    }
    int res = -1e9;
    rep(j, 0, 3)
    {
        rep(k, 0, 8)
        {
            res = max(res, dp[n][j][k]);
        }
    }
    cout << res;
}