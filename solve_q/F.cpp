#include <bits/stdc++.h>
#include <vector>
#include <algorithm>
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
    int N;
    cin >> N;
    vector<int> reg(N);
    for(int i = 0; i < N; i++){
        int p;
        cin >> p;
        reg[i] = p;
    }
    sort(reg.begin(), reg.end());
    int sum = 0;
    for(int i =0; i < N/2+1; i++){
        sum += reg[i]/2;
    }
    for(int i = N/2+1; i < N; i++){
        sum+= reg[i];
    }
    cout << sum;
}