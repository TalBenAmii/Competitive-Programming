#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for (int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;
#define INF 500
int n, C;
vector<vector<double>> memo;
void printDp(int v, int visited, vector<vector<double>> g)
{
    if (visited == (1 << n) - 1)
        return;
    if (memo[v][visited] + 1 > 1e-3)
{
    cout<<memo[v][visited];
    return;
}
}

double f(int v, int visited, vector<vector<double>> g)
{
    if (memo[v][visited] + 1 > 1e-3)
        return memo[v][visited];
    if (visited == (1 << n) - 1)
        return g[v][0];
    double ans = INF;
    for (int u = 0; u < n; u++)
        if (!(visited & (1 << u)))
            ans = min(ans, g[v][u] + f(u, visited | (1 << u), g));
    return memo[v][visited] = ans;
}

int main()
{
    cin.tie(0)->sync_with_stdio(0);
    unordered_map<string, int> namesToId;
    cin >> n;
    vector<pair<double, double>> points(n);
    rep(i, 0, n)
    {
        string name;
        double x, y;
        cin >> name >> x >> y;
        cin.ignore();

        namesToId[name] = i;
        points[i] = {x, y};
    }

    string sen;
    while (getline(cin, sen))
    {
        string s;
        stringstream ss(sen);
        unordered_map<string, int> graphNames;
        unordered_set<string> inGraph;
        unordered_map<int, string> graphIds;
        graphIds[sz(graphNames)] = "home";
        graphNames["home"] = sz(graphNames);
        inGraph.insert("home");
        while (ss >> s)
        {
            graphIds[sz(graphNames)] = s;
            graphNames[s] = sz(graphNames);
            inGraph.insert(s);
        }
        vector<vector<double>> graphDist(sz(inGraph), vector<double>(sz(inGraph)));
        for (auto &name1 : inGraph)
        {
            int u = namesToId[name1];
            for (auto &name2 : inGraph)
            {
                int v = namesToId[name2];
                if (name2 == "home")
                    v = namesToId["work"];
                if (u == v)
                    continue;
                double d = hypot(points[u].first - points[v].first, points[u].second - points[v].second);
                graphDist[graphNames[name1]][graphNames[name2]] = d;
            }
        }
        n = sz(inGraph);
        C = (1 << n);
        memo.assign(n, vector<double>(C + 1, -1));
        cout << f(0, 1, graphDist);
        cout << endl;
    }
}