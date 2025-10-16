#pragma GCC optimize("O3,unroll-loops")
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

int main()
{
    fastio();
    int tc = 1;
    cin >> tc;
    while (tc--)
    {
        int n = nxt();
        vi v(3 * n);
        cin >> v;
        sort(all(v));
        int l = 0, r = 3 * n - 1, res = 0;
        while (l < r)
        {
            res += v[r - 1];
            l++;
            r -= 2;
        }
        cout << res << endl;
    }
    return 0;
}