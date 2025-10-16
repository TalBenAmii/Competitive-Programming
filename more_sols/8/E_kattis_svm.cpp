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
#define INF_LL 1e18

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

int main()
{
    fastio();
    int n;
    cin >> n;
    vector<double> w(n), x(n);
    double b;
    cin >> w >> b;
    while (cin >> x)
    {
        double wx = 0, wNorm = 0;
        for (int i = 0; i < n; i++)
        {
            wx += w[i] * x[i];
            wNorm += w[i] * w[i];
        }
        wNorm = sqrt(wNorm);
        cout << (wx + b) / wNorm << endl;
    }
    return 0;
}