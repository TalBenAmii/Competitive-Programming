#include <bits/stdc++.h>

using namespace std;

#define sz(x) ((int)(x).size())

typedef long long ll;
typedef unsigned long long ull;
typedef long double lld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef pair<int, int> pii;

int main()
{
    int n, t;
    cin >> t;
    while (t--)
    {
    	cin>>n;
    	vi v(n);
    	for(int i=0;i<n;i++)
    	{
    		cin>>v[i];
    	}
    	
    	priority_queue<ll,vll,greater<ll>> h(v.begin(),v.end());
    	ll res=0;
    	while(h.size()>1)
    	{
    		ll v1=h.top();
    		h.pop();
    		v1+=h.top();
    		h.pop();
    		res+=v1;
    		h.push(v1);
    	}
    	cout<<res<<endl;
    }

    return 0;
}
