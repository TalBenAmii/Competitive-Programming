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

//-----------------------------------------------------------------------------------------------------------//-----------------------------------------------------------------------------------------------------------
int main()
{
    fastio();
    string s;
    while (cin >> s)
    {
        int n = s.size();
        vector<int> LIS(n, 1);
        for (int i = 1; i < n; i++)
        {

            for (int j = 0; j < i; j++)
            {
                if (s[i] > s[j])
                    LIS[i] = max(LIS[i], LIS[j] + 1);
            }
        }
        int res = 0;
        for (int x : LIS)
        {
            res = max(x, res);
        }
        cout << 26 - res << endl;
    }

    return 0;
}