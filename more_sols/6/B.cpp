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

vector<string> split_sentence(string sen) {
  
    stringstream ss(sen);
    
    string word;
    
    vector<string> words;
    
    while (ss >> word) {
      
        words.push_back(word);
    }
    
    return words;
}

int n, C;
vvi memo(n, vi(C + 1, -1));
vvi g;

int f(int v, int visited)
{
    if (memo[v][visited] != -1)
        return memo[v][visited];
    if (visited == (1 << n) - 1)
        return g[v][0];
    int ans = INF;
    for (int u = 0; u < n; u++)
    {
        if ((visited & (1 << u)))
            continue;
        ans = min(ans, g[v][u] + f(u, visited | (1 << u)));
    }
    return memo[v][visited] = ans;
}


//-----------------------------------------------------------------------------------------------------------//-----------------------------------------------------------------------------------------------------------
int main()
{
    fastio();
    int n=nxt();
    vector<string> strings(n); // 0->home, 1->work..
    unordered_map<string,int> strToVert;
    vii places(n);
    
    for(int i=0;i<n;i++)
    {
        cin>>strings[i];
        strToVert[strings[i]]=i;
        cin>>places[i].first>>places[i].second;
    }
    string line;
    vvi days;
    string s;
    while(cin>>s)
    {
        days[]
    }
    unordered_map<int,
    vi graphs()
    int ans = f(0, 1);
    return 0;
}