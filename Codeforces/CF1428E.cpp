#include <bits/stdc++.h>
#define ll long long
#define pii pair<ll,int>
#define f first
#define s second
using namespace std;

ll sq(ll x)
{
    return x*x;
}

ll calc(ll x, ll k)
{
    return k*sq(x/k)+(x%k)*(sq(x/k+1)-sq(x/k));
}

ll calc_diff(ll x, ll k1, ll k2)
{
    return calc(x,k1)-calc(x,k2);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n>>k;
    k-=n;
    int a[n],b[n];
    pii p;
    priority_queue<pii> q;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        b[i]=1;
        q.push({calc_diff(a[i],1,2),i});
    }
    for (int i=0;i<k;++i)
    {
        p=q.top();
        q.pop();
        ++b[p.s];
        q.push({calc_diff(a[p.s],b[p.s],b[p.s]+1),p.s});
    }
    ll ans=0;
    for (int i=0;i<n;++i)
        ans+=calc(a[i],b[i]);
    cout<<ans;
    return 0;
}