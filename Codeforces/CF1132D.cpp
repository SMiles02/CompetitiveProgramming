#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pli pair<ll,int>
#define P pair<pli,pli>
#define f first
#define s second
using namespace std;

int n,k;
ll a[200000];
int b[200000];

bool ok(ll x)
{
    priority_queue<P,vector<P>,greater<P>> pq;
    P p,q;
    for (int i=0;i<n;++i)
    {
        p = { {a[i]/b[i]+1 , 1} , {a[i] , b[i]} };
        pq.push(p);
    }
    for (int i=1;i<k;++i)
    {
        p=pq.top();
        pq.pop();
        if (p.f.f < i || p.s.f - 1LL * p.s.s * (i - p.f.s + 1) + x < 0)
            return 0;
        q = {{(p.s.f - 1LL * p.s.s * (i - p.f.s + 1) + x) / p.s.s + i + 1, i + 1} , {p.s.f - 1LL * p.s.s * (i - p.f.s + 1) + x, p.s.s}};
        pq.push(q);
    }
    if (pq.top().f.f < k)
        return 0;
    return 1;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n>>k;
    for (int i=0;i<n;++i)
        cin>>a[i];
    for (int i=0;i<n;++i)
        cin>>b[i];
    ll l=0,r=2e12+69,m;
    if (!ok(r))
    {
        cout<<-1;
        return 0;
    }
    while (l<r)
    {
        m=l+(r-l)/2;
        if (ok(m))
            r=m;
        else
            l=m+1;
    }
    cout<<l;
    return 0;
}