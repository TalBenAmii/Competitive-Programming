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
ll gcd(ll a, ll b)
{
    return b == 0 ? a : gcd(b, a % b);
}

int main()
{
    fastio();
    ll a, b, c, d;
    cin >> a >> b >> c >> d;
    unordered_map<char, int> toRemove;
    ll cdGcd = gcd(c, d);
    c /= cdGcd; // handling big numbers mult (aTag*d)
    d /= cdGcd;

    string aStr = to_string(a), bStr = to_string(b);
    for (int i = 0; i < (1 << sz(aStr)); i++)
    {
        toRemove.clear();
        string aTagStr = "";
        for (int j = 0; j < sz(aStr); j++)
        {
            if ((1 << j) & i)
            {
                toRemove[aStr[j]]++;
            }
            else
            {
                aTagStr += aStr[j];
            }
        }
        if (aTagStr.empty() || aTagStr[0] == '0')
            continue; // empty or leading zeros
        ll aTag = stoll(aTagStr);
        if(aTag / c > (1e18 / d)) continue; // prevents overflow

        if (((aTag % c) * (d % c)) % c != 0)
            continue; // handling not divisible by c
        ll target = (aTag / c) * d;
        string targetStr = to_string(target);
        int targetIdx = 0;
        string bTagStr = "";
        for (int j = 0; j < sz(bStr); j++)
        {
            if (targetIdx < sz(targetStr) && targetStr[targetIdx] == bStr[j])
            {
                bTagStr += bStr[j];
                targetIdx++;
            }
            else
            {
                toRemove[bStr[j]]--;
            }
        }
        if (bTagStr.empty() || bTagStr[0] == '0' || targetIdx < sz(targetStr))
            continue; // empty or leading zeros or doesnt match
        bool isResult = true;
        for (auto x : toRemove)
            if (x.second != 0)
                isResult = false;
        if (isResult)
        {
            cout << "possible" << endl
                 << aTag << " " << target << endl;
            return 0;
        }
    }
    cout << "impossible" << endl;
    return 0;
}