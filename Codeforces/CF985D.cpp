#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll min(ll a, ll b)
{
    if (a>b) return b;
    return a;
}

ll s(ll a)
{
    return a*a;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,h,l=1,r=1414213562,m;
    cin>>n>>h;
    while (l<r)
    {
        m=l+(r-l)/2;
        if (s(m)-((min(h,m)*(min(h,m)-1))/2)<n)
            l=m+1;
        else
            r=m;
    }
    cout<<l;
    return 0;
}