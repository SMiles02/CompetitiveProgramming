#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll min(ll a, ll b)
{
    if (a>b)
        return b;
    return a;
}

ll max(ll a, ll b)
{
    if (a<b)
        return b;
    return a;
}

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

ll lcm(ll a, ll b)
{
    return a*(b/gcd(a,b));
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    ll r,b,k,g;
    cin>>n;
    while (n--)
    {
        cin>>r>>b>>k;
        if (r>b)
            swap(r,b);
        g=gcd(r,b);
        r/=g;b/=g;
        if ((k-1)*r+1>=b)
            cout<<"OBEY\n";
        else
            cout<<"REBEL\n";
    }
    return 0;
}