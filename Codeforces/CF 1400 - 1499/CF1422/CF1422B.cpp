#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

void solve()
{
    int n,m,x;
    ll ans=0;
    cin>>n>>m;
    int a[n][m];
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            cin>>a[i][j];
    pair<int,pii> b[4];
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
        {
            b[0]={a[i][j],{i,j}};
            b[1]={a[n-1-i][j],{n-1-i,j}};
            b[2]={a[i][m-1-j],{i,m-1-j}};
            b[3]={a[n-1-i][m-1-j],{n-1-i,m-1-j}};
            sort(b,b+4);
            x=b[1].f;
            for (int k=0;k<4;++k)
            {
                ans+=abs(a[b[k].s.f][b[k].s.s]-x);
                a[b[k].s.f][b[k].s.s]=x;
            }
        }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}