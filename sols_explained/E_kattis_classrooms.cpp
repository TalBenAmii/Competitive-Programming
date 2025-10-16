#include <iostream>
#include <algorithm>
#include <vector>
#include <set>
using namespace std;

int main(){
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> acts;
    for(int i = 0; i < n; i++){
        int s, f;
        cin >> s >> f;
        acts.push_back({f, s});
    }
    sort(acts.begin(), acts.end());
    
    multiset<int> classes;
    int count = 0;
    for(int i =0; i < k; i++){
        classes.insert(-1);
    }
    for(int i =0; i < acts.size(); i++){
        int s = acts[i].second, f = acts[i].first;
        auto it = classes.lower_bound(s);
        if(it!= classes.begin()){
            classes.erase(--it);
            classes.insert(f);
            count++;
        }
    }
    cout << count;
    return 0;
}