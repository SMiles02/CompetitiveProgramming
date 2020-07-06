#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll binpow(ll a, ll b) {
    if (b == 0)
    {
        return 1;
    }
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
    {
        return res * a;
    }
    return res;
}

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

string to_upper(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

map<int,vector<int>> edges;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,a,b,k,ans=0,flag;
    cin>>n>>m;
    int h[n+1];
    for (int i=1;i<=n;++i)
        cin>>h[i];
    while (m--)
    {
        cin>>a>>b;
        edges[a].push_back(b);
        edges[b].push_back(a);
    }
    for (int i=1;i<=n;++i)
    {
        k=sz(edges[i]);
        if (k)
        {
            flag=1;
            for (int j=0;j<k;++j)
                if (h[edges[i][j]]>=h[i])
                    flag=0;
            if (flag)
                ++ans;
        }
        else
            ++ans;
    }
    cout<<ans;
    return 0;
}