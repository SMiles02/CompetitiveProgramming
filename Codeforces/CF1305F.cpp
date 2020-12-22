#include <bits/stdc++.h>
#define ll long long
using namespace std;
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,ans;
    ll x,cur;
    cin>>n;
    ans=n;
    vector<ll> v(n);
    for (int i=0;i<n;++i)
        cin>>v[i];
    shuffle(v.begin(), v.end(), rng);
    m=min(n,25);
    for (int i=0;i<m;++i)
        for (ll l=max(1,v[i]-1);l<v[i]+2;++l)
        {
            x=l;
            for (ll j=2;j*j<=x;++j)
                if (x%j==0)
                {
                    cur=0;
                    for (int k=0;k<n;++k)
                    {
                        if (v[k]<j)
                            cur+=j-v[k];
                        else
                            cur+=min(v[k]%j,j-(v[k]%j));
                    }
                    if (cur<ans)
                        ans=cur;
                    while (x%j==0)
                        x/=j;
                }
            if (x>1)
            {
                cur=0;
                for (int k=0;k<n;++k)
                {
                    if (v[k]<x)
                        cur+=x-v[k];
                    else
                        cur+=min(v[k]%x,x-(v[k]%x));
                }
                if (cur<ans)
                    ans=cur;
            }
        }
    cout<<ans;
    return 0;
}