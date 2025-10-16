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
    int N, k;
    cin >> N >> k;
    while (N != 0)
    {
        int a[201][2];
        for (int i = 0; i < N; i++)
        {
            for (int j = 0; j < 2; j++)
            {
                cin >> a[i][j];
            }
        }

        int f[200][200][3];
        for (int i = 0; i < k; i++)
        {
            for (int j = 0; j < 3; j++)
            {
                f[0][i][j] = 0;
            }
        }
        for (int n = 1; n <= N; n++)
        {
            for (int j = 0; j < k; j++)
            {
                if (j == 0)
                {
                    f[n][j][0] = max({f[n - 1][j][0], f[n - 1][j][1], f[n - 1][j][2]}) + a[n - 1][0] + a[n - 1][1];
                    f[n][j][1] = -1;
                    f[n][j][2] = -1;
                    continue;
                }
                f[n][j][0] = max({f[n - 1][j][0], f[n - 1][j][1], f[n - 1][j][2]}) + a[n - 1][0] + a[n - 1][1];
                f[n][j][1] = max({f[n - 1][j - 1][0], f[n - 1][j - 1][2]}) + a[n - 1][0];
                f[n][j][2] = max({f[n - 1][j - 1][0], f[n - 1][j - 1][1]}) + a[n - 1][1];
            }
        }
        cout << max(max(f[N][0][0], f[N][0][1]), f[N][0][1])<<endl;
        cin >> N >> k;
    }
    return 0;
}