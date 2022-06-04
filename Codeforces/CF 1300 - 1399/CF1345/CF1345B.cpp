#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int query(int x)
{
    return (1.5*x*x+0.5*x);
}

void solve()
{
    int n,ans=0;
    cin>>n;
    for (int i=25820;i>0;--i)
    {
        if (query(i)<=n)
        {
            ++ans;
            n-=query(i);
            ++i;
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