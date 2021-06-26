#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

double h,c,t;

ll min(ll a, ll b)
{
    if (a>b)
        return b;
    return a;
}

pair<ll,ll> ans(ll k)
{
    ll a=(k/2),b=k-a;
    double x;
    x=a*c+b*h;
    if (x>=t*k)
        return {x-t*k,k};
    return {t*k-x,k};
}

int comp(ll a, ll b)
{
    pair<ll,ll> p;
    pair<ll,ll> q;
    p=ans(a);
    q=ans(b);
    if (p.first*q.second<p.second*q.first)
        return 1;
    if (p.first*q.second==p.second*q.first)
        return 0;
    return -1;
}

void solve()
{
    ll l=0,r=1e8,m;
    cin>>h>>c>>t;
    if (t==h)
    {
        cout<<"1\n";
        return;
    }
    if (t*2<=h+c)
    {
        cout<<"2\n";
        return;
    }
    while (l<r)
    {
        m=l+(r-l)/2;
        if (comp(2*m+3,2*m+1)==1)
            l=m+1;
        else
            r=m;
    }
    if (comp(2,2*l+1)==1)
        cout<<2<<"\n";
    else if (comp(2,2*l+1)==0)
        cout<<min(2,2*l+1)<<"\n";
    else
        cout<<2*l+1<<"\n";
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