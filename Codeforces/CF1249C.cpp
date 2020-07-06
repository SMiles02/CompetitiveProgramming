#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int a[39];

void solve()
{
    ll n,ans=0,k=1;
    cin>>n;
    for (int i=38;i>=0;--i)
    {
        a[i]=(n%3);
        n/=3;
    }
    for (int i=38;i>=0;--i)
    {
        if (a[i]==2)
        {
            a[i]=0;
            ++a[i-1];
            ans=0;
        }
        if (a[i]==3)
        {
            a[i]=0;
            ++a[i-1];
            ans=0;
        }
        ans+=(k*a[i]);
        k*=3;
    }
    cout<<ans<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int q;
    cin>>q;
    while (q--)
    {
        solve();
    }
    return 0;
}