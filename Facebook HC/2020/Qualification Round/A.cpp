#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n;
    cin>>n;
    bool d[n+2][n+2];
    string inc="N",o="N",s;
    cin>>s;
    inc+=s+"N";
    cin>>s;
    o+=s+"N";
    for (int i=0;i<n+2;++i)
        for (int j=0;j<n+2;++j)
            d[i][j]=0;
    for (int i=1;i<=n;++i)
    {
        if (o[i]=='Y'&&inc[i-1]=='Y')
            d[i][i-1]=1;
        if (o[i]=='Y'&&inc[i+1]=='Y')
            d[i][i+1]=1;
        d[i][i]=1;
    }
    for (int j=1;j<=n;++j)
        for (int i=1;i<=n;++i)
            for (int k=1;k<=n;++k)
                d[i][k]=d[i][k]|(d[i][j]&d[j][k]);
    s="NY";
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=n;++j)
            cout<<s[d[i][j]];
        cout<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cout<<"Case #"<<i<<": \n";
        solve();
    }
    return 0;
}