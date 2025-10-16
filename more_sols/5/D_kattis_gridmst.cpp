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

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;
typedef vector<int> vi;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vi> vvi;
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

struct unionfind
{
    vector<int> rank;
    vector<int> parent;

    unionfind(int size)
    {
        rank = vector<int>(size, 0);
        parent = vector<int>(size);
        for (int i = 0; i < size; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        int tmp = x;
        while (x != parent[x])
            x = parent[x];
        while (tmp != x)
        {
            int remember = parent[tmp];
            parent[tmp] = x;
            tmp = remember;
        }
        return x;
    }

    void unite(int p, int q)
    {
        p = find(p);
        q = find(q);
        if (q == p)
            return;
        if (rank[p] < rank[q])
            parent[p] = q;
        else
            parent[q] = p;
        if (rank[p] == rank[q])
            rank[p]++;
    }
};

// input: edges v1->v2 of the form (weight,(v1,v2)),
//        number of nodes (n), all nodes are between 0 and n-1.
// output: weight of a minimum spanning tree.
// time: O(ElogV).
int Kruskal(vector<iii> &edges, int n)
{
    sort(edges.begin(), edges.end());
    int mst_cost = 0;
    unionfind components(n);
    for (iii e : edges)
    {
        if (components.find(e.second.first) != components.find(e.second.second))
        {
            mst_cost += e.first;
            components.unite(e.second.first, e.second.second);
        }
    }
    return mst_cost;
}

int res = 0;

int dist(int i, int j, int x, int y)
{
    return abs(i - x) + abs(j - y);
}

void bfs(queue<ii> &q, vvi &grid)
{
    while (!q.empty())
    {
        ii p = q.front();
        q.pop();
        int idx = p.first, i = p.second / 1000, j = p.second % 1000;
        if (grid[i][j] != -1)
        {
            continue;
        }
        grid[i][j] = idx;
        if (i - 1 >= 0)
            q.push({idx, (i - 1) * 1000 + j});
        if (j - 1 >= 0)
            q.push({idx, i * 1000 + j - 1});
        if (i + 1 < 1000)
            q.push({idx, (i + 1) * 1000 + j});
        if (j + 1 < 1000)
            q.push({idx, i * 1000 + j + 1});
    }
}
//-----------------------------------------------------------------------------------------------------------//-----------------------------------------------------------------------------------------------------------

int main()
{
    fastio();
    int n = nxt();
    queue<ii> q;
    vii v(n);
    vvi grid(1000, vi(1000, -1));
    for (int i = 0; i < n; i++)
    {
        int x = nxt(), y = nxt();
        v[i] = {x, y};
        q.push({i, x * 1000 + y});
    }
    bfs(q, grid);
    vector<iii> edges;
    for (int i = 0; i < 1000; i++)
    {
        for (int j = 0; j < 1000; j++)
        {
            if (grid[i][j] == -1)
                continue;
            int u = grid[i][j],
                u1 = i - 1 >= 0 ? grid[i - 1][j] : -1,
                u2 = j - 1 >= 0 ? grid[i][j - 1] : -1,
                u3 = i + 1 < 1000 ? grid[i + 1][j] : -1,
                u4 = j + 1 < 1000 ? grid[i][j] : -1;
            unordered_set<int> s;
            int ux = v[u].first, uy = v[u].second;
            if (u != u1 && u1 != -1 && !s.count(u1))
            {
                int x = v[u1].first, y = v[u1].second;
                edges.push_back({dist(x, y, ux, uy), {u, u1}});
                s.insert(u1);
            }
            if (u != u2 && u2 != -1 && !s.count(u2))
            {
                int x = v[u2].first, y = v[u2].second;
                edges.push_back({dist(x, y, ux, uy), {u, u2}});
                s.insert(u2);
            }
            if (u != u3 && u3 != -1 && !s.count(u3))
            {
                int x = v[u3].first, y = v[u3].second;
                edges.push_back({dist(x, y, ux, uy), {u, u3}});
                s.insert(u3);
            }
            if (u != u4 && u4 != -1 && !s.count(u4))
            {
                int x = v[u4].first, y = v[u4].second;
                edges.push_back({dist(x, y, ux, uy), {u, u4}});
                s.insert(u4);
            }
        }
    }
    cout << Kruskal(edges, n) << endl;
    return 0;
}