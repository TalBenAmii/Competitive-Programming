#include <bits/stdc++.h>
#include <vector>
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
    ll N, M, L;
    cin >> N >> M >> L;
    vector<ll> lens;

    ll f = L;
    for(int i =0; i < N; i++){
        ll f1;
        cin >> f1;
        lens.push_back(f-f1);
        f =f1;
    }
    lens.push_back(f);
    enum et {S, E, C, S0, E0};
    vector<pair<ll, et>> segs;
    ll edge = 0;
    segs.push_back({0, S0});
    for(int i =0; i < lens.size(); i++){
        if(i%2 == 0){
            if(i == lens.size()-1){
                segs.push_back({edge+lens[i], E0});
            }
            else

                segs.push_back({edge+lens[i], E});
            edge = edge+ lens[i];
        } else {
            if(i == lens.size()-1){
                segs.push_back({edge-lens[i], S0});
            }
            else
                segs.push_back({edge-lens[i], S});
            edge = edge-lens[i];
        }
    }
    for(int i =0; i < M; i++){
        ll cut;
        cin >> cut;
        segs.push_back({cut, C});
    }
    sort(segs.begin(), segs.end());
    int countA = 0;
    ll last = segs.begin()->first;
    ll sum = 0;
    for(int i =0; i < segs.size(); i++){
        sum+= ((segs[i].first)-last)*countA;
        last = segs[i].first;
        switch(segs[i].second){
            case S:
                countA+=2;
                break;
            case S0:
                countA+=1;
                break;
            case E:
                countA-=2;
                break;
            case E0:
                countA-=1;
                break;
            case C:
                cout << sum << " ";
                sum =0;
                break;
        }
    }
    cout << sum << " ";
    return 0;
}