#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b)
{
    if (b == 0)
        return 1;
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
        return res * a;
    return res;
}

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a, ll b)
{
    return (a/gcd(a,b))*b;
}

void solve()
{
    int n,a=1,b;
    ll ans,c;
    cin>>n;
    b=n-1;
    ans=n-1;
    for (int i=2;i*i<=n;++i)
    {
        if (n%i==0)
        {
            c=lcm(i,n-i);
            if (c<ans)
            {
                a=i;
                b=n-i;
                ans=c;
            }
            c=lcm(n/i,n-(n/i));
            if (c<ans)
            {
                a=n/i;
                b=n-(n/i);
                ans=c;
            }
        }
    }
    cout<<a<<" "<<b<<"\n";
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