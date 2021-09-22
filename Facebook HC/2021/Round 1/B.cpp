#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,m,a,b;
    cin>>n>>m>>a>>b;
    if (min(a,b)<n+m-1||1000*(n+m-1)<max(a,b)||((n==1||m==1)&&a!=b))
    {
        cout<<"Impossible\n";
        return;
    }
    cout<<"Possible\n";
    if (n==1)
    {
        cout<<a-m+1<<" ";
        for (int i=1;i<m;++i)
            cout<<"1 ";
        cout<<"\n";
        return;
    }
    if (m==1)
    {
        cout<<a-n+1<<"\n";
        for (int i=1;i<n;++i)
            cout<<"1\n";
        return;
    }
    for (int i=1;i<=n;++i)
    {
        for (int j=1;j<=m;++j)
        {
            if (i==1&&j==1)
                cout<<a-n-m+2<<" ";
            else if (i==1&&j==m)
                cout<<b-n-m+2<<" ";
            else
                cout<<"1 ";
        }
        cout<<"\n";
    }
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    for (int i=1;i<=t;++i)
    {
        cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}