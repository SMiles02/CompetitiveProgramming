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

ll f(ll a)
{
    ll maxi=0,mini=9;
    while (a)
    {
        maxi=max(maxi,a%10);
        mini=min(mini,a%10);
        a/=10;
    }
    return maxi*mini;
}

void solve()
{
    ll n,k;
    cin>>n>>k;
    k=min(1500,k);
    for (int i=1;i<k&&n%10;++i)
        n+=f(n);
    cout<<n<<"\n";
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