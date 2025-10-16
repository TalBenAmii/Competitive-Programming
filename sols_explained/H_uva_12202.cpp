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

vvii graph;
unordered_set<int> graves,haunted;
vll dist;
vii dirs={{0,-1},{0,1},{-1,0},{1,0}};

bool BellmanFord() {
    int s=0;
    dist.assign(graph.size(), INF);
    dist[s] = 0;
    bool changed = false;
    // V times
    for (int i = 0; i < graph.size(); ++i) {
        changed = false;
        // go over all edges u->v with weight w
        for (int u = 0; u < graph.size(); ++u) for (ii e : graph[u]) {
                int v = e.first;
                int w = e.second;
                // relax the edge
                if (dist[u] < INF && dist[u]+w < dist[v]) {
                    dist[v] = dist[u]+w;
                    changed = true;
                }
            }
    }
    // there is a negative cycle if there were changes in the last iteration
    return changed;
}


int main()
{
    fastio();
    int w,h;
    while(cin>>h>>w)
    {
        graves.clear();
        haunted.clear();
        if(!w && !h) break;
        int g=nxt();
        while(g--)
        {
            int x=nxt(),y=nxt();
            graves.insert(x*w+y);
        }
        int e=nxt();
        int n=w*h;
        graph.assign(n,vii());
        while(e--)
        {
            int x1=nxt(),y1=nxt(),x2=nxt(),y2=nxt(),t=nxt();
            int u=x1*w+y1,v=x2*w+y2;
            haunted.insert(u);
            graph[u].emplace_back(v,t);
        }
        for(int x=0;x<h;x++)
        {
            for(int y=0;y<w;y++)
            {
                int u=x*w+y;
                if(haunted.count(u) ||(x==h-1 && y==w-1)) continue;
                for(auto p:dirs)
                {
                    int vX=x+p.first,vY=y+p.second;
                    int v= vX*w+vY;
                    if(vX<0 || vY<0 || vX>=h||vY>=w ||graves.count(v)) continue;
                    graph[u].emplace_back(v,1);
                }
                
            }
        }
        bool isNever = BellmanFord();
        int target = (h-1)*w + (w-1);
        if(isNever) cout<<"Never"<<endl;
        else if(dist[target]==INF)cout<<"Impossible"<<endl;
        else cout<<dist[target]<<endl;
    }
    return 0;
}
