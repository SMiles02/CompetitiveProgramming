#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 300, INF = 1e9, mod = 998244353;
int d[N][N];
map<string,int> m;

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = (res * a)%mod;
        a = (a * a)%mod;
        b >>= 1;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y,ans=0;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<n;++j)
            d[i][j]=INF;
        d[i][i]=0;
    }
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        --x;--y;
        d[x][y]=1;
        d[y][x]=1;
    }
    for (int j=0;j<n;++j)
        for (int i=0;i<n;++i)
            for (int k=0;k<n;++k)
                d[i][k]=min(d[i][k],d[i][j]+d[j][k]);
    string b(n,'0');
    m[b]=mod-1;
    for (int i=0;i<n;++i)
        b[i]='1';
    m[b]=n;
    for (int i=0;i<n;++i)
    {
        for (int j=0;j<n;++j)
            b[j]='0';
        for (int j=0;j<n;++j)
        {
            for (int k=0;k<n;++k)
                if (d[i][k]==j)
                    b[k]='1';
            m[b]=max(m[b],j);
        }
    }
    for (auto i : m)
    {
        cout<<i.first<<" "<<i.second<<"\n";
        ans+=i.second;
        if (ans>=mod)
            ans-=mod;
    }
    cout<<(1LL*ans*binpow(binpow(2,n),mod-2))%mod;
    return 0;
}