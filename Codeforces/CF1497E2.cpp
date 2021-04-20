#include <bits/stdc++.h>
using namespace std;

const int mn = 1e7+1, N = 2e5+1, INF = 1e9+7;
int r[mn],m[mn],dp[N][21],a[N],l[N][21];
bitset<mn> comp;
bitset<N> used;

void precalc()
{
    int c,x;
    for (int i=1;i<mn;++i)
        r[i]=1;
    for (int i=2;i<mn;++i)
        if (comp[i]==0)
            for (int j=i;j<mn;j+=i)
            {
                comp[j]=1;
                c=0;
                x=j;
                while (x%i==0)
                {
                    ++c;
                    x/=i;
                }
                if (c&1)
                    r[j]*=i;
            }
}

void solve()
{
    int n,x,d;
    cin>>n>>x;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        a[i]=r[a[i]];
    }
    for (int j=0;j<=x;++j)
    {
        l[n][j]=0;
        d=0;
        for (int i=0;i<=n;++i)
            used[i]=0;
        for (int k=n;k>0;--k)
        {
            if (m[a[k]])
            {
                if (d==j)
                {
                    l[n][j]=k;
                    break;
                }
                else
                {
                    used[m[a[k]]]=1;
                    ++d;
                }
            }
            m[a[k]]=k;
        }
        for (int i=n-1;i>0;--i)
        {
            if (m[a[i+1]]==i+1)
                m[a[i+1]]=0;
            if (used[i+1])
                --d;
            l[i][j]=0;
            for (int k=l[i+1][j];k>0;--k)
            {
                if (m[a[k]])
                {
                    if (d==j)
                    {
                        l[i][j]=k;
                        break;
                    }
                    else
                    {
                        used[m[a[k]]]=1;
                        ++d;
                    }
                }
                m[a[k]]=k;
            }
        }
        m[a[1]]=0;
    }
    for (int i=1;i<=n;++i)
        for (int j=0;j<=x;++j)
        {
            dp[i][j]=INF;
            for (int k=0;k<=j;++k)
                dp[i][j]=min(dp[i][j],dp[l[i][k]][j-k]+1);
        }
    cout<<dp[n][x]<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    precalc();
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}