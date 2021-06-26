#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,ans=0,x,y;
    cin>>n;
    array<int,2> a[n+1];
    a[0]={1,1};
    for (int j=0;j<2;++j)
        for (int i=1;i<=n;++i)
            cin>>a[i][j];
    sort(a,a+n+1);
    for (int i=0;i<n;++i)
    {
        x=a[i+1][0]-a[i][0];
        y=a[i+1][1]-a[i][1];
        if ((a[i][0]+a[i][1])&1)
            ans+=(x-y+1)/2;
        else
        {
            if (x==y)
            {
                ans+=x;
                continue;
            }
            ans+=(x-y)/2;
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