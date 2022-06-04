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
    ll n,m=0;
    cin>>n;
    ll a[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            for (int k=0;k<n;++k)
                m=max(m,a[i]|a[j]|a[k]);
    cout<<m;
    return 0;
}
