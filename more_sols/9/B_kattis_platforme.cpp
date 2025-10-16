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
#include <iostream>
#include <cstdlib>
#include <time.h>
#include <math.h>
#include <chrono>
#include <vector>
#include <bitset>
#include <stdio.h>
#include <fstream>
#include <stack>
#include <algorithm>
using namespace std;

typedef long long ll;

#define EPS 1e-9
#define MAX_SIZE 100

//-----------------------------------------------------------------------------------------------------------//-----------------------------------------------------------------------------------------------------------
struct P
{
    int y, x1, x2;
};

int main()
{
    fastio();
    int n;
    cin >> n;
    // vector<priority_queue<int, vi, greater<int>>> v(10001);
    vector<P> points(n);
    for (int i = 0; i < n; i++)
    {
        int y, x1, x2;
        cin >> y >> x1 >> x2;
        // v[x1].push(y);
        // v[x2].push(y);
        points[i] = {y, x1, x2};
    }
    ll res = 0;
    for (auto p1 : points)
    {
        int leftClose = p1.y, rightClose = p1.y;
        for (auto p2 : points)
        {
            if (p2.x1 <= p1.x1 && p1.x1 < p2.x2 && p1.y > p2.y)
            {
                leftClose = min(leftClose, p1.y - p2.y);
            }
            if (p2.x1 < p1.x2 && p1.x2 <= p2.x2 && p1.y > p2.y)
            {
                rightClose = min(rightClose, p1.y - p2.y);
            }
        }
        res += leftClose + rightClose;
    }
    cout << res << endl;
    return 0;
}