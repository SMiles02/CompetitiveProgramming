#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll weights[100001];

ll max(ll a, ll b)
{
    if (a>b)
    {
        return a;
    }
    return b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,w,a,b;
    cin>>n>>w;
    while (n--)
    {
        cin>>a>>b;
        for (int i=w;i-a>=0;--i)
        {
            weights[i]=max(weights[i],weights[i-a]+b);
        }
    }
    ll ans=0;
    for (int i=0;i<=w;++i)
    {
        ans=max(ans,weights[i]);
    }
    cout<<ans;
    return 0;
}