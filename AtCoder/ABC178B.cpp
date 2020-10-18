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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll a,b,c,d,ans=-1e18;
    cin>>a>>b>>c>>d;
    ans=max(ans,a*c);
    ans=max(ans,a*d);
    ans=max(ans,b*c);
    ans=max(ans,b*d);
    if ((a<=0&&0<=b)||(c<=0&&0<=d))
        ans=max(ans,0);
    cout<<ans;
    return 0;
}