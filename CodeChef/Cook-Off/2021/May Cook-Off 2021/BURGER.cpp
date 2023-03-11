#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int findPow(ll k)
{
    for (int i=0;i<100;++i)
        if ((1LL<<i)==k)
            return i;
    return -1;
}

void solve()
{
    ll x,y,z,ans=1e18,cur;
    cin>>x>>y;
    if (y%x)
    {
        cout<<"-1\n";
        return;
    }
    y/=x;
    for (int i=1;i<100;++i)
        if (__builtin_popcountll(y+i)==i)
        {
            cur=i-1;
            z=y+i;
            while (z)
            {
                cur+=findPow(z&-z);
                z-=z&-z;
            }
            ans=min(ans,cur);
        }
    if (ans==1e18)
        ans=-1;
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