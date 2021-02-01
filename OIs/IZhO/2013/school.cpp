#include <bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

bool cmp(pii& a, pii& b)
{
    return a.f-a.s<b.f-b.s;
}

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

int main()
{
    ios_base::sync_with_stdio(0);cin.tie(0);
    int n,M,S;
    cin>>n>>M>>S;
    pii a[n+1];
    for (int i=1;i<=n;++i)
        cin>>a[i].f>>a[i].s;
    sort(a+1,a+n+1,cmp);
    ll sum=0,ans=0,b[n+2],c[n+2];
    priority_queue<int,vector<int>,greater<int>> p,q;
    for (int i=1;i<=n;++i)
    {
        sum+=a[i].s;
        p.push(a[i].s);
        if (i>S)
        {
            sum-=p.top();
            p.pop();
        }
        b[i]=sum;
    }
    sum=0;
    for (int i=n;i;--i)
    {
        sum+=a[i].f;
        q.push(a[i].f);
        if (n-i>=M)
        {
            sum-=q.top();
            q.pop();
        }
        c[i]=sum;
    }
    b[0]=c[n+1]=0;
    b[n+1]=b[n];
    c[0]=c[1];
    for (int i=0;i<=n;++i)
        ans=max(ans,b[i]+c[i+1]);
    cout<<ans;
}