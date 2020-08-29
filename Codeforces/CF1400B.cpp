#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

ll min(ll a, ll b)
{
    if (a<b)
        return a;
    return b;
}

void solve()
{
    ll p,f,cS,cW,s,w,ans=0,k,x,y,a,b,c;
    cin>>p>>f;
    cin>>cS>>cW;
    cin>>s>>w;
    for (ll i=0;i<=cS;++i)
        if (s*i<=p)
        {
            k=min((p-s*i)/w,cW);
            x=cS-i;
            y=cW-k;
            if (s<=w)
            {
                a=min(x,f/s);
                c=f-(a*s);
                b=min(y,c/w);
            }
            else
            {
                a=min(y,f/w);
                c=f-(a*w);
                b=min(x,c/s);
            }
            ans=max(ans,i+k+a+b);
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