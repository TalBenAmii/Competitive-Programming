#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int)(x).size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<int> vi;
typedef pair<int, int> pii;

struct unionfind
{
    vector<int> rank;
    vector<int> parent;
    vector<int> a;
    unionfind(int size)
    {
        rank = vector<int>(size, 1);
        parent = vector<int>(size);
        a = vector<int>(size, 0);
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
    bool Union(int p, int q)
    {
        p = find(p);
        q = find(q);
        bool flag = false;
        if (q == p)
        {
            if (rank[p] > a[p])
            {
                a[p]++;
                flag = true;
            }
            return flag;
        }

        if (rank[p] < rank[q])
            parent[p] = q;

        else
            parent[q] = p;

        rank[p] += rank[q];
        rank[q] = rank[p];
        a[p] += a[q];
        a[q] = a[p];
        if (rank[p] > a[p])
        {
            a[p]++;
            a[q]++;
            flag = true;
        }
        return flag;
    }
};

int main()
{
    int n, d;
    cin >> n >> d;
        vi a(d + 10, 0);
        unionfind uf(d + 1);
        for (int i = 0; i < n; i++)
        {
            int d1, d2;
            cin >> d1 >> d2;

            if (uf.Union(d1, d2))
                cout << "LADICA" << endl;
            else
                cout << "SMECE" << endl;
        }

    return 0;
}
