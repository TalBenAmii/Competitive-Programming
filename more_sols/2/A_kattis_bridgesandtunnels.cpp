#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int)(x).size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<int> vi;

struct unionfind
{
    vector<int> rank;
    vector<int> parent;
    unionfind(int size)
    {
        rank = vector<int>(size, 1);
        parent = vector<int>(size);
        for (int i = 0; i < size; i++)
            parent[i] = i;
    }

    int find(int x)
    {
        int tmp = x;
        while (x != parent[x])
            x = parent[x];
        while (tmp != x) // for log*, not needed most of the time
        {
            int remember = parent[tmp];
            parent[tmp] = x;
            tmp = remember;
        }
        return x;
    }
    void Union(int p, int q)
    {
        p = find(p);
        q = find(q);
        if (q == p)
        {
            // alredy in the same group
            return;
        }
        if (rank[p] < rank[q])
        {
            parent[p] = q;
            rank[q] += rank[p];
        }
        else
        {
            parent[q] = p;
            rank[p] += rank[q];
        }
        
            
    }
};

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    int n;
    cin >> n;
    unionfind uf(n * 2 + 1);

    unordered_map<string, int> m;
    for (int i = 0; i < 2 * n ; i += 2)
    {
        string s1, s2;
        cin >> s1 >> s2;
        if (!m.count(s1))
            m[s1] = i;
        if (!m.count(s2))
            m[s2] = i + 1;
        // cout << s1 << ' ' << m[s1] << ' ' << s2 << ' ' << m[s2] << '\n';
        uf.Union(m[s1], m[s2]);
        cout << max(uf.rank[uf.find(m[s1])], uf.rank[uf.find(m[s2])]) << '\n';
    }

    return 0;
}
