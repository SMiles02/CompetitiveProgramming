#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int n,m,a,b,s[200000];

bool ok(int k, int t)
{
    for (int i=k-1;i+1;--i)
    {
        if (s[i]>=t)
            return 0;
        --t;
    }
    return 1;
}

void solve()
{
    cin>>n>>m>>a>>b;
    for (int i=0;i<m;++i)
        cin>>s[i];
    sort(s,s+m);
    int l=0,r=min(m,abs(a-b)-1),mid,t;
    if (a<b)
        t=b-1;
    else
        t=n-b;
    while (l<r)
    {
        mid=l+(r-l)/2+1;
        if (ok(mid,t))
            l=mid;
        else
            r=mid-1;
    }
    cout<<l<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin>>tc;
    while (tc--)
        solve();
    return 0;
}