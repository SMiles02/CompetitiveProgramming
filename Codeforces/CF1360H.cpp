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

int n,m;

ll query()
{
    string s;
    cin>>s;
    ll cur=0,k=1;
    for (int i=0;i<m;++i)
    {
        if (s.back()=='1')
            cur+=k;
        s.pop_back();
        k*=2;
    }
    return cur;
}

void g(ll k)
{
    vector<int> v;
    for (int i=0;i<m;++i)
    {
        v.push_back(k%2);
        k/=2;
    }
    for (int i=m-1;i>=0;--i)
        cout<<v[i];
    cout<<"\n";
}

void solve()
{
    cin>>n>>m;
    ll l=0,r=binpow(2,m)-1,mid,x,k;
    k=r+1-n;
    ll a[n];
    for (int i=0;i<n;++i)
        a[i]=query();
    while (l<r)
    {
        mid=l+(r-l)/2;
        x=mid+1;
        for (int i=0;i<n;++i)
            if (a[i]<=mid)
                --x;
        if (x<(k-1)/2+1)
            l=mid+1;
        else
            r=mid;
    }
    g(r);
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}