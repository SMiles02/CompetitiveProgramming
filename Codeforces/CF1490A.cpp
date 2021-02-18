#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int f(int x, int y)
{
    int r=0;
    while (x*2<y)
    {
        x*=2;
        ++r;
    }
    return r;
}

void solve()
{
    int n,x,y,ans=0;
    cin>>n;
    cin>>x;
    for (int i=1;i<n;++i)
    {
        cin>>y;
        ans+=f(min(x,y),max(x,y));
        x=y;
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