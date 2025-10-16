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
#define EPS 1e-9
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
    int tc;
    cin >> tc;
    vector<pair<string, string>> v;
    while (tc--)
    {
        int n;
        cin >> n;
        string d, k, q;
        long double x = 0, y = 0;
        double angle = 0;
        v.assign(n, {"", ""});
        for (int i = 0; i < n; i++)
        {
            cin >> d >> k;
            v[i].first = d;
            v[i].second = k;
            if (k == "?")
            {
                q = d;
                continue;
            }
            double moveBy = stoi(k);
            if (d == "fd")
            {
                x += cos(angle) * moveBy;
                y += sin(angle) * moveBy;
            }
            else if (d == "bk")
            {
                x -= cos(angle) * moveBy;
                y -= sin(angle) * moveBy;
            }
            else if (d == "lt")
            {
                angle += (moveBy / 180) * PI;
            }
            else if (d == "rt")
            {
                angle -= (moveBy / 180) * PI;
            }
        }
        if (q == "fd" || q == "bk")
        {
            cout << hypot(x, y) << endl;
        }
        else
        {

            for (int a = 0; a < 360; a++)
            {
                x = 0, y = 0, angle = 0;

                double moveBy;
                for (int i = 0; i < n; i++)
                {
                    d = v[i].first;
                    k = v[i].second;
                    if (k == "?")
                    {
                        moveBy = a;
                    }
                    else
                    {
                        moveBy = stoi(k);
                    }
                    if (d == "fd")
                    {
                        x += cos(angle) * moveBy;
                        y += sin(angle) * moveBy;
                    }
                    else if (d == "bk")
                    {
                        x -= cos(angle) * moveBy;
                        y -= sin(angle) * moveBy;
                    }
                    else if (d == "lt")
                    {
                        angle += (moveBy / 180) * PI;
                    }
                    else if (d == "rt")
                    {
                        angle -= (moveBy / 180) * PI;
                    }
                }
                if (abs(x) < 0.01 && abs(y) < 0.01)
                {
                    cout << a << endl;
                    break;
                }
            }
            // cout << ((int)((angle / PI) * 180)) % 360 << endl;
        }
    }
    return 0;
}