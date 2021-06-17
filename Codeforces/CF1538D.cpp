#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int pF(int n)
{
    int ret = 0;
    for (int i=2;i*i<=n;++i)
        while (n%i==0)
        {
            ++ret;
            n/=i;
        }
    if (n>1)
        ++ret;
    return ret;
}

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

void solve()
{
    int a,b,k,g,x;
    cin>>a>>b>>k;
    if (k==1)
    {
        if (a==b||(a%b&&b%a))
            cout<<"NO\n";
        else
            cout<<"YES\n";
        return;
    }
    g=gcd(a,b);
    x=pF(a/g)+pF(b/g)+2*pF(g);
    if (x>=k)
        cout<<"YES\n";
    else
        cout<<"NO\n";
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