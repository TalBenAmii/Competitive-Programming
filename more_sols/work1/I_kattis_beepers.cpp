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
#define ff first
#define ss second

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef pair<ll, ll> pll;

typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vi> vvi;
typedef vector<ll> vll;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;

typedef set<int> si;
typedef vector<si> vsi;
typedef unordered_map<int, int> umii;

constexpr ll LINF = 1LL << 62;
constexpr int INF = 1 << 30, Mod = 1e9 + 7;
#define EPS 1e-9
#define PI acos(-1)
#define debug(x) cout << #x << ": " << (x) << "\n";

template <typename T = int>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
        in >> x;
    return in;
}

template <typename T1 = int, typename T2 = int>
istream &operator>>(istream &in, vector<pair<T1, T2>> &v)
{
    for (auto &x : v)
        in >> x.first >> x.second;
    return in;
}

template <typename T = int>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (const T &x : v)
        out << x << ' ';
    return out;
}

template <typename T1 = int, typename T2 = int>
ostream &operator<<(ostream &out, const vector<pair<T1, T2>> &v)
{
    for (const auto &x : v)
        out << '(' << x.first << ", " << x.second << ") ";
    return out;
}

template <typename T = int>
inline T nxt()
{
    T x;
    cin >> x;
    return x;
}

template <typename T = vi>
inline T nxt(size_t size)
{
    T v(size);
    cin >> v;
    return v;
}

//-----------------------------------------------------------------------------------------------------------//-----------------------------------------------------------------------------------------------------------
int n, C;
vvi memo, g;
unordered_map<int, ii> cords; //{u,{x,y}}

int f(int v, int visited)
{
    if (memo[v][visited] != -1)
        return memo[v][visited];
    if (visited == (1 << n) - 1)
        return g[v][0];
    int ans = INF;
    for (int u = 0; u < n; u++)
        if (!(visited & (1 << u)))
            ans = min(ans, g[v][u] + f(u, visited | (1 << u)));
    return memo[v][visited] = ans;
}

int main()
{
    fastio();
    int tc = nxt();
    while (tc--)
    {
        cords.clear();
        int xSize = nxt(), ySize = nxt(), xStart = nxt(), yStart = nxt();
        cords[sz(cords)] = {xStart, yStart};
        n = nxt() + 1;
        for (int i = 0; i < n - 1; i++)
        {
            int x = nxt(), y = nxt();
            cords[sz(cords)] = {x, y};
        }
        g.assign(n, vi(n, 0));
        for (auto p1 : cords)
        {
            int u = p1.ff, x1 = p1.ss.ff, y1 = p1.ss.ss;
            for (auto p2 : cords)
            {
                int v = p2.ff, x2 = p2.ss.ff, y2 = p2.ss.ss;
                if (u == v)
                    continue;
                g[u][v] = abs(x1 - x2) + abs(y1 - y2);
            }
        }
        C = 1 << n;
        memo.assign(n, vi(C + 1, -1));
        cout << f(0, 1) << endl;
    }
    return 0;
}
