#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

const int maxn=1e5+7,INF=-1e9;
int dp[maxn];
pair<int,pii> a[maxn];

int dist(pii p, pii q)
{
    return abs(p.f-q.f)+abs(p.s-q.s);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int r,n,ans=0;
    cin>>r>>n;
    a[0]={0,{1,1}};
    dp[0]=0;
    for (int i=1;i<=n;++i)
    {
        dp[i]=INF;
        cin>>a[i].f>>a[i].s.f>>a[i].s.s;
        for (int j=max(0,i-2000);j<i;++j)
            if (dist(a[i].s,a[j].s)<=a[i].f-a[j].f)
                dp[i]=max(dp[j]+1,dp[i]);
        ans=max(dp[i],ans);
    }
    cout<<ans;
    return 0;
}