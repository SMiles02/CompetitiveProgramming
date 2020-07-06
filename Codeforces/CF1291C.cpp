#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,m,k,ans=0,minAns;
    cin>>n>>m>>k;
    int a[n];
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    k=min(k,m);
    for (int i=0;i<=k;++i)
    {
        minAns=1000000000;
        for (int j=0;j<=m-k;++j)
        {
            cout<<i+j<<" "<<n-1-k+i+1-m+k<<"\n";
            minAns=min(minAns,max(a[i+j],a[n-1-k+i+1-m+k]));
        }
        ans=max(ans,minAns);
    }
    cout<<ans<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}