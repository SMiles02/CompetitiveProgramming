#include <bits/stdc++.h>
using namespace std;
const int INF = 1e9;

void solve()
{
    int n,p,k,x,y,ans=INF;
    string s;
    cin>>n>>p>>k;
    cin>>s;
    cin>>x>>y;
    int b[n];
    for (int i=max(n-k,p-1);i<n;++i)
    {
        if (s[i]=='1')
            b[i]=0;
        else
            b[i]=x;
        ans=min(ans,b[i]+y*(i-p+1));
    }
    for (int i=n-k-1;i>=p-1;--i)
    {
        if (s[i]=='1')
            b[i]=b[i+k];
        else
            b[i]=x+b[i+k];
        ans=min(ans,b[i]+y*(i-p+1));
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