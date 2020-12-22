#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,q,ans=0,x,y;
    cin>>n>>q;
    int a[n+2];
    a[0]=0;a[n+1]=0;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        if (a[i]!=a[i-1])
            ++ans;
    }
    while (q--)
    {
        cin>>x>>y;
        if (a[x]==y)
        {
            cout<<ans<<"\n";
            continue;
        }
        if (a[x-1]==a[x]&&a[x]==a[x+1])
            ans+=2;
        else if (a[x-1]==a[x])
        {
            if (y!=a[x+1])
                ++ans;
        }
        else if (a[x+1]==a[x])
        {
            if (y!=a[x-1])
                ++ans;
        }
        else if (y==a[x-1]&&y==a[x+1])
            ans-=2;
        else if (y==a[x-1]||y==a[x+1])
                --ans;
        a[x]=y;
        cout<<ans<<"\n";
    }
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