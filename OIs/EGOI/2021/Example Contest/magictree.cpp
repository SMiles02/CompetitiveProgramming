#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1e5+7;
vector<int> e[N];
int a[N][2],n,m,k;
ll dp[N][25],tmp;

const int mn = 2e5+7, INF = 1e9+7;
ll segTree[mn<<2];

void update(int i, int cL, int cR, int j, int x)
{
    if (j<cL||cR<j)
        return;
    if (cL==cR)
    {
        segTree[i]=x;
        return;
    }
    update((i<<1)+1,cL,cL+((cR-cL)>>1),j,x);
    update((i<<1)+2,cL+((cR-cL)>>1)+1,cR,j,x);
    segTree[i]=max(segTree[(i<<1)+1],segTree[(i<<1)+2]);
}

ll query(int i, int cL, int cR, int l, int r)
{
    if (r<cL||cR<l)
        return 0;
    if (l<=cL&&cR<=r)
        return segTree[i];
    return max(query((i<<1)+1,cL,cL+((cR-cL)>>1),l,r),query((i<<1)+2,cL+((cR-cL)>>1)+1,cR,l,r));
}

void dfs(int c)
{
    for (int i : e[c])
    {
        dfs(i);
        for (int j=1;j<=k;++j)
        {
            tmp=dp[c][j];
            for (int l=1;l<=j;++l)
                tmp=max(tmp,dp[c][j]+dp[i][l]);
            dp[c][j]=tmp;
        }
    }
    dp[c][a[c][0]]+=a[c][1];
    // cout<<c<<":\n";
    // for (int i=1;i<=k;++i)
    //     cout<<dp[c][i]<<" ";
    // cout<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int x;
    ll ans=0;
    cin>>n>>m>>k;
    bool ok1=1,ok2=1;
    for (int i=2;i<=n;++i)
    {
        cin>>x;
        if (x!=i-1)
            ok2=0;
        e[x].push_back(i);
    }
    while (m--)
    {
        cin>>x;
        if (!e[x].empty())
            ok1=0;
        cin>>a[x][0]>>a[x][1];
        ans+=a[x][1];
    }
    if (ok1)
    {
        cout<<ans;
        return 0;
    }
    if (ok2)
    {
        for (int i=n;i>0;--i)
            if (a[i][0])
                update(0,1,k,a[i][0],query(0,1,n,1,a[i][0])+a[i][1]);
        cout<<query(0,1,n,1,k);
        return 0;
    }
    dfs(1);
    ans=0;
    for (int i=1;i<=k;++i)
        ans=max(ans,dp[1][i]);
    cout<<ans;
    return 0;
}