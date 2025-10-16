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
#define LL_INF 1e18

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
int w;
ll profits[1010][10];
ll mem[1010][4][4][4][4];

ll back(int i, int a, int b, int c, int d)
{
    if (a < 0 || b < 0 || c < 0 || d < 0)
        return -LL_INF;
    if(i>=w)return 0;
    if (mem[i][a][b][c][d] != -1)
        return mem[i][a][b][c][d];
    ll ans1, ans2, ans3, ans4;
    ans1 = profits[i][0] + back(i + 1, a - 2, min(b + 1, 2), min(c + 1, 2), min(d + 1, 2));
    ans2 = profits[i][1] + back(i + 1, min(a + 1, 2), b - 2, min(c + 1, 2), min(d + 1, 2));
    ans3 = profits[i][2] + back(i + 1, min(a + 1, 2), min(b + 1, 2), c - 2, min(d + 1, 2));
    ans4 = profits[i][3] + back(i + 1, min(a + 1, 2), min(b + 1, 2), min(c + 1, 2), d - 2);

    return mem[i][a][b][c][d]=max({ans1,ans2,ans3,ans4});
}

int main()
{
    fastio();
    int tc;
    cin >> tc;
    while (tc--)
    {
        cin >> w;
        for (int i = 0; i < w; i++)
        {
            cin >> profits[i][0] >> profits[i][1] >> profits[i][2] >> profits[i][3];
        }
        memset(mem, -1, sizeof mem);
        cout << back(0, 2, 2, 2, 2) << endl;
    }
    return 0;
}