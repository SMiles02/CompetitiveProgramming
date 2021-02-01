#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m=0,x;
    cin>>n;
    ll a[n+1];
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        if (abs(a[i])>=m)
        {
            m=a[i];
            x=i;
        }
    }
    cout<<2*n-1<<"\n";
    for (int i=1;i<=n;++i)
    {
        cout<<x<<" "<<i<<"\n";
        a[i]+=a[x];
    }
    if (m>=0)
        for (int i=2;i<=n;++i)
            cout<<i-1<<" "<<i<<"\n";
    else
        for (int i=n-1;i>0;--i)
            cout<<i+1<<" "<<i<<"\n";
    return 0;
}