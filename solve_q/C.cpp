#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
int main()
{
    cin.tie(0)->sync_with_stdio(0);
    int n;
    cin >> n;
    rep(j, 0, n)
    {
        int x;
        cin >> x;
        // int digits = 0;
        // int tmp = x;
        // while (tmp)
        // {
        //     digits++;
        //     tmp /= 10;
        // }
        // rep(j, 0, digits)
        // {
        // cout << x << endl;
        for (int i = 0; i < 256; i++)
        {
            int res = i ^ ((i << 1)%256);
            if (res == x)
            {
                cout << i << " ";
                break;
            };
        }
    }
}