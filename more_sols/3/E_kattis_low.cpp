#include <bits/stdc++.h>

using namespace std;

#define fastio()                      \
    ios_base::sync_with_stdio(false); \
    cin.tie(nullptr);                 \
    cout.tie(nullptr)
#define fixed(n) fixed << setprecision(n)
#define ceil(n, m) (((n) + (m) - 1) / (m))
#define add_mod(a, b, m) (((a % m) + (b % m)) % m)
#define sub_mod(a, b, m) (((a % m) - (b % m) + m) % m)
#define mul_mod(a, b, m) (((a % m) * (b % m)) % m)
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define sz(x) int(x.size())
#define ll long long
#define ull unsigned long long
#define lld long double
#define vi vector<int>
#define pii pair<int, int>
#define umii unordered_map<int, int>
#define EPS 1e-9
constexpr int INF = 1 << 30, Mod = 1e9 + 7;
constexpr ll LINF = 1LL << 62;
#define PI acos(-1)
#define debug(x) cout << #x << ": " << (x) << "\n";

template <typename T = int>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
        in >> x;
    return in;
}

template <typename T = int>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (const T &x : v)
        out << x << ' ';
    return out;
}

inline int nxt()
{
    int x;
    cin >> x;
    return x;
}

bool can(vi v, int k, int d)
{
    ll canChoose = 0;
    for (ll i = 1; i < sz(v); i++)
    {
        if (v[i] - v[i - 1] <= d)
        {
            i++;
            canChoose += 2 * k - 2;
        }
        else
        {
            canChoose--;
            if (canChoose < 0)
                return false;
        }
    }
    return true;
}

int main()
{
    fastio();
    int n = nxt(), k = nxt();
    vi v(2 * n * k);
    cin >> v;
    sort(all(v));
    ll l = 0, h = v[sz(v) - 1] - v[0];
    while (l < h)
    {
        ll m = (h + l) / 2;
        if (can(v, k, m))
        {
            h = m;
        }
        else
        {
            l = m + 1;
        }
    }
    cout << l;
    return 0;
}
