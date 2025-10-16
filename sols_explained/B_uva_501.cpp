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

    int k = nxt();
    while (k--)
    {
        multiset<int> s;
        int m = nxt(), n = nxt();
        vi v1(m), v2(n);
        cin >> v1;
        cin >> v2;
        int j = 0;
        auto it = s.begin();
        for (int i = 0; i < n; i++)
        {
            while (s.size() < v2[i] )
            {
                int elem = v1[j++];
                s.insert(elem);
                if(it==s.end()||*it>elem )it--;
            }
            cout << *it<<endl;
            it++;
        }
        if(k>0) cout<<endl;
    }
    return 0;
}
