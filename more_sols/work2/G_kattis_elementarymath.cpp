
// This file contains implementations of some well-known graph algorithms.
// Written by Nofar Carmeli. Some code is based on the book Competitive Programming 3 by Steven and Felix Halim.

#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <set>
#include <map>
using namespace std;

typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef vector<ii> vii;
typedef vector<vii> vvii;
typedef vector<int> vi;
typedef vector<vi> vvi;
typedef set<int> si;
typedef vector<si> vsi;

typedef long long ll;

const int INF = 1e9;


/********** Max Flow **********/


int augment(vvi& res, int s, int t, const vi& p, int minEdge) {
    // traverse the path from s to t according to p.
    // change the residuals on this path according to the min edge weight along this path.
    // return the amount of flow that was added.
    if (t == s) {
        return minEdge;
    } else if (p[t] != -1) {
        int f = augment(res, s, p[t], p, min(minEdge, res[p[t]][t]));
        res[p[t]][t] -= f;
        res[t][p[t]] += f;
        return f;
    }
    return 0;
}

// input: number of nodes (n), all nodes are between 0 and n-1,
//        edges v1->v2 of the form (weight,(v1,v2)), source (s) and target (t).
// output: max flow from s to t over the edges.
// time: O(VE^2) and O(EF).
int EdmondsKarp (int n, vector<iii>& edges, int s, int t, vvi& res) {
    // initialise adjacenty list and residuals adjacency matrix
    vvi adj(n);
    for (iii e : edges) {
        res[e.second.first][e.second.second] += e.first;
        adj[e.second.first].push_back(e.second.second);
        adj[e.second.second].push_back(e.second.first);
    }
    // while we can add flow
    int addedFlow, maxFlow = 0;
    do {
        // save to p the BFS tree from s to t using only edges with residuals
        vi dist(res.size(), INF);
        dist[s] = 0;
        queue<int> q;
        q.push(s);
        vi p(res.size(), -1);
        while (!q.empty()) {
            int u = q.front(); q.pop();
            if (u == t) break;
            for (int v : adj[u]) if (res[u][v] > 0 && dist[v] == INF) {
                    dist[v] = dist[u] + 1;
                    q.push(v);
                    p[v] = u;
                }
        }
        // add flow on the path between s to t according to p
        addedFlow = augment(res, s, t, p, INF);
        maxFlow += addedFlow;
    } while (addedFlow > 0);
    return maxFlow;
}

void bfs(const vvi& g, int s, vector<int>& d ) {
    queue<int> q; q.push(s);
    vector<bool> visible (g.size(),false);
    visible[s]=true;
    d.assign(g.size(),INF); d[s] = 0;
    while (!q.empty()) {
        int u = q.front(); q.pop();
        for (int v : g[u]) if (!visible[v]) {
                visible[v] = true;
                d[v] = d[u]+1;
                q.push(v);
            }
    }
}

void addRes(int pnum, ll newRes, map<ll, int>& res, vector<iii>& edges, int& count){
    if(res.find(newRes) == res.end()){
        res[newRes] = count;
        edges.push_back({1, {pnum, count}});
        edges.push_back({1, {count, 1}});
        count++;
    } else {
        edges.push_back({1, {pnum, res.find(newRes)->second}});
    }
}

int main(){
    int n;
    cin >> n;
    map<int, pair<ll, ll>> probs;
    map<ll, int> resultMap;
    vector<iii> edges;
    int count = 2;
    for(int i =0; i < n; i++){
        ll x1, x2;
        cin >> x1 >> x2;
        int pnum = count;
        probs[pnum] = {x1, x2};
        edges.push_back({1, {0, pnum}});
        count++;

        set<ll> usedRes;
        addRes(pnum, x1+x2, resultMap, edges, count);
        if(x1-x2 != x1 + x2){
            addRes(pnum, x1-x2, resultMap, edges, count);
        }
        if(x1*x2 != x1+x2 && x1*x2 != x1-x2){
            addRes(pnum, x1*x2, resultMap, edges, count);
        }
    }
    map<int, ll> resultNodes;
    for(auto pr : resultMap){
        resultNodes[pr.second] = pr.first;
    }
    vvi res(count,vi(count,0));
    if(EdmondsKarp(count, edges, 0,1, res) != n){
        cout << "impossible\n";
        return 0;
    }
    for(auto e : edges){
        if(e.second.first == 0 || e.second.second == 1){
            continue;
        }
        int flow = res[e.second.second][e.second.first];
        if(flow == 0){
            continue;
        }
        pair<ll, ll> p = probs[e.second.first];
        ll r = resultNodes[e.second.second];
        if(p.first + p.second == r){
            cout << p.first << " + " << p.second << " = " << r <<"\n";
            continue;
        }
        if(p.first - p.second == r){
            cout << p.first << " - " << p.second << " = " << r <<"\n";
            continue;
        }
        cout << p.first << " * " << p.second << " = " << r <<"\n";
    }
    return 0;
}