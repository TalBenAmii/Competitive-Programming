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
#define ll long long
#define ull unsigned long long
#define lld long double
#define vi vector<int>
#define pii pair<int, int>
#define umii unordered_map<int, int>
#define EPS 1e-9
constexpr int INF = 1 << 30, Mod = 1e9 + 7;
constexpr ll LINF = 1LL << 62;
#define PI acos(-1)
#define debug(x) cout << #x << ": " << (x) << "\n";

template <typename T = int>
istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
        in >> x;
    return in;
}

template <typename T = int>
ostream &operator<<(ostream &out, const vector<T> &v)
{
    for (const T &x : v)
        out << x << ' ';
    return out;
}

inline int nxt()
{
    int x;
    cin >> x;
    return x;
}

int main()
{
    fastio();
    int tc = 1;
    // cin >> tc;
    while (tc--)
    {
        int n = nxt();
        vi v(n);
        cin >> v;
        ll res = 0;
        for (auto w : v)
        {
            res += pow(2, n - 1) * w;
        }
        for (int i = 0; i < n; i++)
        {
            if (v[i] < 200)
                res -= v[i];
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                int s = v[i] + v[j];
                if (s < 200)
                    res -= s;
            }
        }
        for (int i = 0; i < n; i++)
        {
            for (int j = i + 1; j < n; j++)
            {
                for (int h = j + 1; h < n; h++)
                {
                    int s = v[i] + v[j] + v[h];
                    if (s < 200)
                        res -= s;
                }
            }
        }
        cout<<res<<endl;
    }
    return 0;
}
