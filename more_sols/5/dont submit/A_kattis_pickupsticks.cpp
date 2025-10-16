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

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vi> vvi;
typedef set<int> si;
typedef vector<si> vsi;

// input: directed graph (g[u] contains the neighbors of u, nodes are named 0,1,...,|V|-1).
// output: is g a DAG (return value), a topological ordering of g (order).
// comment: order is valid only if g is a DAG.
// time: O(V+E).
bool topological_sort(const vvi &g, vi &order)
{
    // compute indegree of all nodes
    vi indegree(g.size(), 0);
    for (int v = 0; v < g.size(); v++)
        for (int u : g[v])
            indegree[u]++;
    // order sources first
    order = vector<int>();
    for (int v = 0; v < g.size(); v++)
        if (indegree[v] == 0)
            order.push_back(v);
    // go over the ordered nodes and remove outgoing edges,
    // add new sources to the ordering
    for (int i = 0; i < order.size(); i++)
        for (int u : g[order[i]])
        {
            indegree[u]--;
            if (indegree[u] == 0)
                order.push_back(u);
        }
    return order.size() == g.size();
}

int main()
{
    fastio();
    int n = nxt(), m = nxt();
    vvi v(n, vi());
    while (m--)
    {
        int v1 = nxt(), u1 = nxt();
        v[v1 - 1].push_back(u1 - 1);
    }
    vi tOrder;
    if (!topological_sort(v, tOrder))
    {
        cout << "IMPOSSIBLE" << endl;
    }
    else
    {
        for (int a : tOrder)
        {
            cout << (a + 1) << endl;
        }
    }

    return 0;
}
