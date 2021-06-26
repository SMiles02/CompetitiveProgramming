#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int mod=1000000007;

ll binpow(ll a, ll b) {
    if (b == 0)
    {
        return 1;
    }
    ll res = binpow(a, b / 2);
    res*=res;
    res%=mod;
    if (b % 2)
    {
        return (res * a)%mod;
    }
    return res;
}

ll add(ll a, ll b)
{
    return (a+b)%mod;
}

int a[1000001];

void solve()
{
    int n,p,k;
    ll x=0,y=0;
    cin>>n>>p;
    for (int i=0;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    if (p==1)
    {
        cout<<n%2<<"\n";
        return;
    }
    vector<pair<int,int>> v;
    vector<pair<int,int>> w;
    for (int i=n-1;i+1;--i)
    {
        if (sz(v)==0)
            v.push_back({a[i],1});
        else if (sz(w)==0)
        {
            if (sz(v)==1&&v[0].first==a[i])
                v.clear();
            else
                w.push_back({a[i],1});
        }
        else
        {
            if (w.back().first==a[i])
            {
                ++w.back().second;
                while (w.back().second>=p)
                {
                    k=w.back().first;
                    w.pop_back();
                    if (sz(w)&&w.back().first==k+1)
                        ++w.back().second;
                    else
                        w.push_back({k+1,1});
                }
                if (sz(w)==1)
                    if (v==w)
                    {
                        v.clear();
                        w.clear();
                    }
            }
            else
                w.push_back({a[i],1});
        }
    }
    for (auto i : v)
        x=add(x,(binpow(p,i.first)*i.second)%mod);
    for (auto i : w)
        y=add(y,(binpow(p,i.first)*i.second)%mod);
    cout<<(x+mod-y)%mod<<"\n";
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