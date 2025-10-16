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
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vi> vvi;
typedef vector<vii> vvii;
typedef set<int> si;
typedef vector<si> vsi;
typedef unordered_map<int, int> umii;

#define debug(x) cout << #x << ": " << (x) << "\n";
#define PI acos(-1)
#define INF 1e9

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
vvi d;
vvii g;
vector<vector<double>> memo;
int R;
void FloydWarshall()
{
    // initialize distances according to the graph edges
    for (int u = 0; u < g.size(); ++u)
        d[u][u] = 0;
    for (int u = 0; u < g.size(); ++u)
        for (ii e : g[u])
        {
            int v = e.first;
            int w = e.second;
            d[u][v] = min(d[u][v], w);
        }
    // relax distances using the Floyd-Warshall algorithm
    for (int k = 0; k < g.size(); ++k)
        for (int u = 0; u < g.size(); ++u)
            for (int v = 0; v < g.size(); ++v)
                d[u][v] = min(d[u][v], d[u][k] + d[k][v]);
}

double f(int l, int c)
{
    if (l > c || l < 0 || c < 0)
        return 0;
    if (memo[l][c] != -1)
        return memo[l][c];
    double ans = 0;
    for (int i = 1; i <= R; i++)
    {
        ans += f(l - 1, c - i) / R;
    }
    return memo[l][c] = ans;
}

int main()
{
    fastio();
    int tests = nxt();
    for (int tc = 1; tc <= tests; tc++)
    {
        int N = nxt();
        R = nxt();
        g.assign(N, vii());
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < N; j++)
            {
                char a = nxt<char>();
                if (a == 'Y')
                    g[i].emplace_back(j, 1);
            }
        }
        d.assign(g.size(), vi(g.size(), INF));

        FloydWarshall();
        memo.assign(N + 1, vector<double>(N * R + 1, -1));

        memo[0][0] = 1;

        int C = nxt();
        cout << "Case " << tc << endl;
        for (int i = 0; i < C; i++)
        {
            int a = nxt() - 1, b = nxt() - 1, m = nxt();
            double ans = 0;
            for (int j = 0; j <= min(m, (d[a][b]) * R); j++)
            {
                ans += f(d[a][b], j); 
            }
            cout << fixed(6) << ans << endl;
        }
        if (tc < tests)
            cout << endl;
    }
    return 0;
}