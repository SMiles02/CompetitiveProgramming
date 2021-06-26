#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,m,ans;
    string s,t;
    cin>>s>>t;
    n=sz(s);m=sz(t);
    ans=n+m;
    for (int j=1;j<=n;++j)
        for (int i=0;i+j<=n;++i)
            for (int k=0;k+j<=m;++k)
                if (s.substr(i,j)==t.substr(k,j))
                    ans=n+m-2*j;
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