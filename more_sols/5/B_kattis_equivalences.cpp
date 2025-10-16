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

typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vi> vvi;
typedef set<int> si;
typedef vector<si> vsi;

const int UNSEEN = -1;
const int SEEN = 1;

void KosarajuDFS(const vvi &g, int u, vi &S, vi &colorMap, int color)
{
    // DFS on digraph g from node u:
    // visit a node only if it is mapped to the color UNSEEN,
    // Mark all visited nodes in the color map using the given color.
    // input: digraph (g), node (v), mapping:node->color (colorMap), color (color).
    // output: DFS post-order (S), node coloring (colorMap).
    colorMap[u] = color;
    for (auto &v : g[u])
        if (colorMap[v] == UNSEEN)
            KosarajuDFS(g, v, S, colorMap, color);
    S.push_back(u);
}

// Compute the number of SCCs and maps nodes to their corresponding SCCs.
// input: directed graph (g[u] contains the neighbors of u, nodes are named 0,1,...,|V|-1).
// output: the number of SCCs (return value), a mapping from node to SCC color (components).
// time: O(V+E).
int findSCC(const vvi &g, vi &components)
{
    // first pass: record the `post-order' of original graph
    vi postOrder, seen;
    seen.assign(g.size(), UNSEEN);
    for (int i = 0; i < g.size(); ++i)
        if (seen[i] == UNSEEN)
            KosarajuDFS(g, i, postOrder, seen, SEEN);
    // second pass: explore the SCCs based on first pass result
    vvi reverse_g(g.size(), vi());
    for (int u = 0; u < g.size(); u++)
        for (int v : g[u])
            reverse_g[v].push_back(u);
    vi dummy;
    components.assign(g.size(), UNSEEN);
    int numSCC = 0;
    for (int i = (int)g.size() - 1; i >= 0; --i)
        if (components[postOrder[i]] == UNSEEN)
            KosarajuDFS(reverse_g, postOrder[i], dummy, components, numSCC++);
    return numSCC;
}

// Computes the SCC graph of a given digraph.
// input: directed graph (g[u] contains the neighbors of u, nodes are named 0,1,...,|V|-1).
// output: strongly connected components graph of g (sccg).
// time: O(V+E).
void findSCCgraph(const vvi &g, vsi &sccg)
{
    vi component;
    int n = findSCC(g, component);
    sccg.assign(n, si());
    for (int u = 0; u < g.size(); u++)
        for (int v : g[u]) // for every edge u->v
            if (component[u] != component[v])
                sccg[component[u]].insert(component[v]);
}

int main()
{
    fastio();
    int tc = nxt();
    while (tc--)
    {
        int n = nxt(), m = nxt();
        vii v = nxt<vii>(m);
        vvi adj(n);
        for (auto p : v)
        {
            adj[p.first - 1].push_back(p.second - 1);
        }
        vsi scc;
        findSCCgraph(adj, scc);
        vi in(scc.size()), out(scc.size());
        for (int i = 0; i < sz(scc); i++)
        {
            if (scc[i].size())
                out[i]++;
            for (auto x : scc[i])
            {
                in[x]++;
            }
        }
        int totIn = 0, totOut = 0;
        for (int i = 0; i < sz(scc); i++)
        {
            if (!in[i])
                totIn++;
            if (!out[i])
                totOut++;
        }
        if (sz(scc) == 1)
            cout << 0 << endl;
        else
            cout << max(totIn, totOut) << endl;
    }
    return 0;
}
