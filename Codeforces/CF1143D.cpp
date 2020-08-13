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

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll n,k,a,b,mini,maxi,x,l;
    cin>>n>>k;
    cin>>a>>b;
    mini=n*k;
    maxi=1;
    vector<int> c;
    for (int i : {-1,1})
        for (int j : {-1,1})
        {
            x=i*a+j*b;
            x%=k;
            while (x<0)
                x+=k;
            c.push_back(x);
        }
    for (int i=0;i<n;++i)
        for (int j : c)
        {
            l=i*k+j;
            x=(n*k)/gcd(n*k,l);
            mini=min(mini,x);
            maxi=max(maxi,x);
        }
    cout<<mini<<" "<<maxi;
    return 0;
}