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

//-----------------------------------------------------------------------------------------------------------//-----------------------------------------------------------------------------------------------------------

int mem[1010][2010];
vi weights;
int pos=1000,neg=1000;

void back(int i, int w)
{
    if(w>=1000)
    {
        pos=min(pos,w-1000);
    }
    else
    {
        neg=min(neg,1000-w);
    }
    if (w >= 2000 || i >= sz(weights) || mem[i][w] != -1)
        return;
    mem[i][w] = 1;
    back(i + 1, w + weights[i]);
    back(i + 1, w);
}

int main()
{
    fastio();
    int N;
    cin >> N;
    weights.assign(N, 0);
    cin >> weights;
    memset(mem, -1, sizeof mem);
    back(0, 0);
    // int pos = 1000, neg = 1000;
    // for (int i = 0; i < 2000; i++)
    // {
    //     if (mem[0][i] != 1)
    //         continue;
    //     int dist = abs(1000 - i);
    //     if (i < 1000)
    //     {
    //         neg = min(neg, dist);
    //     }
    //     else
    //     {
    //         pos = min(pos, dist);
    //     }
    // }
    int res = (pos <= neg) ? 1000 + pos : 1000 - neg;
    cout << res << endl;
    return 0;
}