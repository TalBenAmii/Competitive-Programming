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
typedef pair<ll, ll> pll;
typedef pair<int, ii> iii;

typedef vector<int> vi;
typedef vector<ll> vll;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<vi> vvi;
typedef vector<pll> vpll;
typedef vector<vpll> vvpll;

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

int mem[160][160][60]; // C,n5,n10
int money, cokes;

int back(int C, int n5, int n10)
{
    int n1 = money - 8 * (cokes - C) - n5 * 5 - n10 * 10;
    if (n1 < 0 || n5 < 0 || n10 < 0)
        return INF;
    if (mem[C][n5][n10] != -1)
        return mem[C][n5][n10];
    if (C == 0)
        return 0;
    int a, b, c, d, e;
    a = 4 + back(C - 1, n5 + 1, n10 - 1);
    b = 1 + back(C - 1, n5, n10 - 1);
    c = 4 + back(C - 1, n5 - 1, n10);
    d = 8 + back(C - 1, n5, n10);
    e = 2 + back(C - 1, n5 - 2, n10);

    return mem[C][n5][n10] = min({a, b, c, d, e});
}

int main()
{
    fastio();
    int tc;
    cin >> tc;
    while (tc--)
    {
        int n1, n5, n10;
        cin >> cokes >> n1 >> n5 >> n10;
        money = n1 + 5 * n5 + 10 * n10;
        memset(mem, -1, sizeof mem);
        cout << back(cokes, n5, n10) << endl;
    }
    return 0;
}