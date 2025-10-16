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
typedef vector<vector<ll>> matrix;

matrix matMul(const matrix &mat1, const matrix &mat2)
{
    matrix res(2, vector<ll>(2, 0));
    for (int i = 0; i < 2; i++)
    {
        for (int j = 0; j < 2; j++)
        {
            for (int k = 0; k < 2; k++)
            {
                res[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }
    return res;
}
matrix matPower(matrix x, ll y)
{
    matrix res(2, vector<ll>(2, 0));
    res[0][0] = 1;
    res[1][1] = 1;

    while (y > 0)
    {
        if (y & 1)
            res = matMul(res, x);

        y = y >> 1;
        x = matMul(x, x);
    }
    return res;
}
ll f_n(ll p, ll q, ll n)
{
    if (n == 0)
        return 2;
    if (n == 1)
        return p;
    matrix mat(2, vector<ll>(2, 0));
    mat[0][0] = p;
    mat[0][1] = -q, mat[1][0] = 1, mat[1][1] = 0;
    mat = matPower(mat, n);
    return p * mat[1][0] + 2 * mat[1][1];
}
int main()
{
    fastio();
    ll q, p, n;
    while (cin >> p >> q >> n)
    {
        if (!p && !q && !n)
            break;

        cout << f_n(p, q, n) << endl;
    }
    return 0;
}