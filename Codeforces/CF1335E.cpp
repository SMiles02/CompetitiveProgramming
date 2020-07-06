#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,ans=1;
    cin>>n;
    int a[n+1];
    int prefix[n+1][27];
    for (int i=1;i<27;++i)
    {
        prefix[0][i]=0;
    }
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        for (int j=1;j<27;++j)
        {
            prefix[i][j]=prefix[i-1][j];
        }
        ++prefix[i][a[i]];
    }
    for (int i=1;i<=n;++i)
    {
        for (int j=i;j<=n;++j)
        {
            for (int a=1;a<27;++a)
            {
                for (int b=1;b<27;++b)
                {
                    ans=max(ans,min(prefix[i-1][a],(prefix[n][a]-prefix[j][a]))*2+prefix[j][b]-prefix[i-1][b]);
                }
            }
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
    {
        solve();
    }
    return 0;
}