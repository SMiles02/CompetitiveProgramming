#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int MOD = 1e9+7;
ll x[42];

ll lcm(ll a, ll b)
{
    return (a/gcd(a,b))*b;
}

int add(int a, int b)
{
    a+=b;
    if (a>=MOD)
        a-=MOD;
    return a;
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    ll k, ans;
    cin>>n;
    x[0]=1;
    for (int i=1;x[i-1]<=1e16;++i)
        x[i]=lcm(x[i-1],i);
    while (n--)
    {
        cin>>k;
        ans=add(k%MOD,k%MOD);
        for (int i=2;i<=40;++i)
            ans=add(ans,(k/x[i])%MOD);
        cout<<ans<<"\n";
    }
    return 0;
}