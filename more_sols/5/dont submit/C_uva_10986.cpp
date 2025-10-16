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

// input: non-negatively weighted directed graph (g[u] contains pairs (v,w) such that u->v has weight w, nodes are named 0,1,...,|V|-1), source (s).
// output: distances from s (dist).
// time: O(ElogV).
void Dijkstra(const vvii &g, int s, vi &dist)
{
    dist = vi(g.size(), INF);
    dist[s] = 0;
    priority_queue<ii, vii, greater<ii>> q;
    q.push({0, s});
    while (!q.empty())
    {
        ii front = q.top();
        q.pop();
        int d = front.first, u = front.second;
        if (d > dist[u])
            continue; // We may have found a shorter way to get to u after inserting it to q.
        // In that case, we want to ignore the previous insertion to q.
        for (ii next : g[u])
        {
            int v = next.first, w = next.second;
            if (dist[u] + w < dist[v])
            {
                dist[v] = dist[u] + w;
                q.push({dist[v], v});
            }
        }
    }
}

int main()
{
    fastio();
    int cases;
    cin >> cases;
    for (int i = 1; i <= cases; ++i)
    {
        int n, m, S, T;
        cin >> n >> m >> S >> T;
        vvii g(n, vii());
        for (int j = 0; j < m; ++j)
        {
            int a, b, d;
            cin >> a >> b >> d;
            ii e = {b, d};
            g[a].push_back(e);
            g[b].push_back({a, d});
        }

        vi dist;
        Dijkstra(g, S, dist);
        cout << "Case #" << i << ": ";

        if (dist[T] != INF)
        {
            cout << dist[T] << endl;
        }
        else
        {
            cout << "unreachable" << endl;
        }
    }

    return 0;
}
