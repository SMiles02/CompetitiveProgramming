#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll binpow(ll a, ll b) {
    if (b == 0)
    {
        return 1;
    }
    ll res = binpow(a, b / 2);
    res*=res;
    if (b % 2)
    {
        return res * a;
    }
    return res;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    ll x1,y1,x2,y2,n;
    cin>>x1>>y1;
    cin>>x2>>y2;
    cin>>n;
    ll xChange[n+1];
    ll yChange[n+1];
    xChange[0]=0;
    yChange[0]=0;
    string s;
    cin>>s;
    for (int i=0;i<n;++i)
    {
        if (s[i]=='U')
        {
            xChange[i+1]=xChange[i];
            yChange[i+1]=yChange[i]+1;
        }
        if (s[i]=='D')
        {
            xChange[i+1]=xChange[i];
            yChange[i+1]=yChange[i]-1;
        }
        if (s[i]=='R')
        {
            xChange[i+1]=xChange[i]+1;
            yChange[i+1]=yChange[i];
        }
        if (s[i]=='L')
        {
            xChange[i+1]=xChange[i]-1;
            yChange[i+1]=yChange[i];
        }
    }
    if (abs((x1+(xChange[n]*binpow(10,9)))-x2)+abs((y1+(yChange[n]*binpow(10,9)))-y2)>(binpow(10,9)*n))
    {
        cout<<-1;
        return 0;
    }
    ll l=1,r=binpow(10,15),m;
    while (l<r)
    {
        m=l+(r-l)/2;
        if (abs((x1+(xChange[n]*(m/n))+(xChange[m%n]))-x2)+abs((y1+(yChange[n]*(m/n))+(yChange[m%n]))-y2)>m)
        {
            l=m+1;
        }
        else r=m;
    }
    cout<<l;
    return 0;
}