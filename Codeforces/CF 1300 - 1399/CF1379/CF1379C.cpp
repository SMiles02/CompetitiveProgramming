#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll max(ll a, ll b)
{
    if (a>b)
        return a;
    return b;
}

void solve()
{
    int n,m,tmp;
    ll ans=0,cur;
    cin>>n>>m;
    pair<int,int> a[m];
    for (int i=0;i<m;++i)
    {
        cin>>a[i].first>>a[i].second;
        cur=a[i].second;
        cur*=(n-1);
        cur+=a[i].first;
        ans=max(ans,cur);
    } 
    sort(a,a+m);
    cur=0;tmp=0;
    for (int i=0;i<min(n,m);++i)
    {
        cur+=
    }
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