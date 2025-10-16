#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

vector<ll> v;
int n;
bool can(ll val)
{
    auto it = lower_bound(v.begin(), v.end(), val);
    int res = it - v.begin();
    if (val <= n - res)
        return true;
    return false;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    cin >> n;
    v.assign(n, 0);
    rep(i, 0, n)
    {
        cin >> v[i];
    }
    sort(all(v));
    ll l = 0, h = n;
    while (l < h)
    {
        ll m = (h + l) / 2 + 1;
        if (can(m))
        {
            l = m;
        }
        else
        {
            h = m - 1;
        }
    }

    cout << l << endl;
    return 0;
}