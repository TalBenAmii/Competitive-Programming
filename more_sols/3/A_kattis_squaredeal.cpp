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
    // cin >> tc;
    while (tc--)
    {
        int n = 3;
        vector<pii> v(3);
        for (int i = 0; i < 3; i++)
        {
            int h = nxt(), w = nxt();
            v[i] = make_pair(h, w);
        }
        sort(all(v), greater<>());
        bool res = false;
        int h1 = v[0].first, h2 = v[1].first, h3 = v[2].first;
        int w1 = v[0].second, w2 = v[1].second, w3 = v[2].second;
        if ((h1 == h2 && h2 == h3) && (w1 + w2 + w3) == h1)
            res = true;
        else if ((w2 == w3) && (h2 + h3 == h1) && (w1 + w2 == h1))
            res = true;
        else if ((h2 == h3) && (w2 + w3 == h1) && (w1 + h2 == h1))
            res = true;
        else if ((w2 == h3) && (h2 + w3 == h1) && (w1 + w2 == h1))
            res = true;
        else if ((h2 == w3) && (w2 + h3 == h1) && (w1 + h2 == w1))
            res = true;
        string s = res ? "YES" : "NO";
        cout << s << endl;
    }
    return 0;
}