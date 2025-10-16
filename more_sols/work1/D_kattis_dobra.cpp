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

unordered_set<char> vowls = {'A', 'E', 'I', 'O', 'U'};
unordered_set<char> non_vowls = {'B', 'C', 'D', 'F', 'G', 'H', 'J', 'K', 'M', 'N', 'P', 'Q', 'R', 'S', 'T', 'V', 'W', 'X', 'Y', 'Z'};

ll res = 0;

bool isLegal(string s)
{
    int vowlSeq = 0, nonVowlSeq = 0;
    for (int i = 0; i < sz(s); i++)
    {
        if (i < 0 || i >= sz(s) || s[i] == '*')
            continue;
        if (s[i] == 'O')
            vowlSeq++;
        else
            vowlSeq = 0;
        if (s[i] == 'A' || s[i] == 'L')
            nonVowlSeq++;
        else
            nonVowlSeq = 0;
        if (vowlSeq >= 3 || nonVowlSeq >= 3)
            return false;
    }
    return true;
}

void dfs(string s, int i, ll multBy)
{
    if (s[i] == '*')
    {
        int lCount = 0;
        for (char c : s)
            if (c == 'L')
                lCount++;
        if (lCount && isLegal(s))
        {
            // cout << s <<" add by: "<<multBy<< endl;
            res += multBy;
        }

        return;
    }

    if (s[i] == '_')
    {
        s[i] = 'A';
        dfs(s, i + 1, multBy * 20);
        s[i] = 'O';
        dfs(s, i + 1, multBy * 5);
        s[i] = 'L';
        dfs(s, i + 1, multBy);
    }
    else
    {
        dfs(s, i + 1, multBy);
    }
}

int main()
{
    fastio();
    string origS;
    cin >> origS;
    string s = "**" + origS + "**"; // padding
    for (int i = 0; i < sz(s); i++)
    {
        if (vowls.count(s[i]))
            s[i] = 'O';
        else if (non_vowls.count(s[i]))
            s[i] = 'A';
        }
        
        // cout<<s;
    dfs(s, 2, 1);
    cout << res;
    return 0;
}
