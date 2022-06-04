#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n>>m;
    ll a[n],b,c;
    for (int i=0;i<n;++i)
        cin>>a[i];
    if (n==1)
    {
        while (m--)
        {
            cin>>b;
            cout<<a[0]+b<<" ";
        }
        return 0;
    }
    sort(a,a+n);
    c=a[1]-a[0];
    for (int i=2;i<n;++i)
        c=gcd(c,a[i]-a[0]);
    while (m--)
    {
        cin>>b;
        cout<<gcd(a[0]+b,c)<<" ";
    }
    return 0;
}