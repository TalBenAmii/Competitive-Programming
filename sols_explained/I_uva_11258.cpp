#include <bits/stdc++.h>


using namespace std;

typedef vector<int> vi;
typedef long long ll;

string s;
ll memo[200];

ll solve(int i) {
    if (i == s.size()) return 0;
    if (memo[i] != -1) return memo[i];
    ll res = 0, currNum = 0;
    for (int j = i; j < s.size(); ++j) {
        currNum += s[j] - '0';
        if (currNum > INT_MAX) break;
        res = max(res, currNum + solve(j + 1));
        currNum *= 10;
    }
    return memo[i] = res;
}


int main() {
    int cases;
    cin >> cases;
    while (cases--) {
        cin >> s;
        for (int i = 0; i < s.size(); ++i) {
            memo[i] = -1;
        }
        cout << solve(0) << endl;
    }
    return 0;
}
