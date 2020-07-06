#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
 
ll d[501][501];
 
ll min(ll a, ll b)
{
    if (a>b)
        return b;
    return a;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,a,b,c,q;
    cin>>n>>m>>q;
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            if (i!=j)
                d[i][j]=1e18;
 
    while (m--)
    {
        cin>>a>>b>>c;
        d[a][b]=min(d[a][b],c);
        d[b][a]=d[a][b];
    }
    for (int i=1;i<=n;++i)
        for (int j=1;j<=n;++j)
            for (int k=1;k<=n;++k)
                d[j][k]=min(d[j][k],d[j][i]+d[i][k]);
    while (q--)
    {
        cin>>a>>b;
        if (d[a][b]>=1e18)
            cout<<"-1\n";
        else
            cout<<d[a][b]<<"\n";
    }
    return 0;
}