#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int)(x).size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<int> vi;
typedef pair<int, int> pii;

int main()
{

    int n, k;
    cin >> n >> k;
    vi a(n), b(n);
    int i = 0;
    while (i < n)
    {
        cin >> a[i] >> b[i];
        i++;
    }
    sort(a.begin(), a.end());
    sort(b.begin(), b.end());
    int ai = 0, bi = 0, res = 0, in = 0;
    while (ai < n && bi < n)
    {
        if (a[ai] - b[bi] <= k)
        {
            in++;
            ai++;
        }
        else
        {
            in--;
            bi++;
        }
        res = max(res, in);
    }
    cout << res;
    return 0;
}
