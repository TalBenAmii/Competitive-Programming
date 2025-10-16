#include <bits/stdc++.h>

using namespace std;

#define fixed(n) fixed << setprecision(n)
#define ceil(n, m) (((n) + (m) - 1) / (m))
#define add_mod(a, b, m) (((a % m) + (b % m)) % m)
#define sub_mod(a, b, m) (((a % m) - (b % m) + m) % m)
#define mul_mod(a, b, m) (((a % m) * (b % m)) % m)
#define all(vec) vec.begin(), vec.end()
#define rall(vec) vec.rbegin(), vec.rend()
#define sz(x) int(x.size())
#define debug(x) cout << #x << ": " << (x) << "\n";
#define fi first
#define se second
#define ll long long
#define ull unsigned long long
#define EPS 1e-9
constexpr int INF = 1 << 30, Mod = 1e9 + 7;
constexpr ll LINF = 1LL << 62;
#define PI acos(-1)
template <typename T = int> using Pair = pair<T, T>;
vector<string> RET = {"NO", "YES"};

template <typename T = int> istream &operator>>(istream &in, vector<T> &v)
{
    for (auto &x : v)
        in >> x;
    return in;
}

template <typename T = int> ostream &operator<<(ostream &out, const vector<T> &v)
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

void Solve()
{
    int n;
    while (cin >> n)
    {

        vector<int> v(n);
        unordered_map<int, int> s;
        for (int i = 0; i < n; i++)
        {
            int x = nxt();
            s[x] = i;
            v[i] = x;
        }
        int m = nxt();
        vector<int> res(2), tmp(2);
        int val = INF;
        for (int i = 0; i < n; i++)
        {
            if (s.count(m - v[i]) && v[i] <= m - v[i])
            {
                res[0] = v[i];
                res[1] = m - v[i];
                if (abs(res[0] - res[1]) < val)
                {
                    tmp[0] = res[0];
                    tmp[1] = res[1];
                    val=abs(res[0] - res[1]) ;
                }
            }
        }
        cout << "Peter should buy books whose prices are " << tmp[0] << " and " << tmp[1] << "." << endl << endl;
    }
}

int main()
{
    ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
    int test_cases = 1;
    // cin >> test_cases;
    for (int tc = 1; tc <= test_cases; tc++)
    {
        // cout << "Case #" << tc << ": ";
        Solve();
    }
    return 0;
}