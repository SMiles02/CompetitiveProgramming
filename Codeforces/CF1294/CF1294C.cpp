#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int binpow(int a, int b) {
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

void solve()
{
    int n,cur,k;
    cin>>n;
    k=n;
    vector<pair<int,int>> v;
    if (!(n%2))
    {
        cur=0;
        while (!(n%2))
        {
            ++cur;
            n/=2;
        }
        v.push_back({2,cur});
    }
    for (int i=3;i<=sqrt(n);i+=2)
    {
        if (!(n%i))
        {
            cur=0;
            while (!(n%i))
            {
                ++cur;
                n/=i;
            }
            v.push_back({i,cur});
        }
    }
    if (n>1)
    {
        v.push_back({n,1});
    }
    if (sz(v)==1)
    {
        if (v[0].second>=6)
        {
            cout<<"YES\n"<<v[0].first<<" "<<v[0].first*v[0].first<<" "<<k/(v[0].first*v[0].first*v[0].first)<<"\n";
        }
        else
        {
            cout<<"NO\n";
        }
        return;
    }
    if (sz(v)==2)
    {
        if (v[0].second>=3)
        {
            cout<<"YES\n"<<v[0].first<<" "<<v[0].first*v[0].first<<" "<<k/(v[0].first*v[0].first*v[0].first)<<"\n";
            return;
        }
        if (v[1].second>=3)
        {
            cout<<"YES\n"<<v[1].first<<" "<<v[1].first*v[1].first<<" "<<k/(v[1].first*v[1].first*v[1].first)<<"\n";
            return;
        }
        if (v[0].second>=2&&v[1].second>=2)
        {
            cout<<"YES\n"<<v[0].first<<" "<<v[1].first<<" "<<k/(v[0].first*v[1].first)<<"\n";
        }
        else
        {
            cout<<"NO\n";
        }
        return;
    }
    cout<<"YES\n"<<v[0].first<<" "<<v[1].first<<" "<<k/(v[0].first*v[1].first)<<"\n";
    return;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
    {
        solve();
    }
    return 0;
}