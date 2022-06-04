#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int maxn = 5e5+7, INF = 1e9;
int a[maxn],lis[maxn],l,r,m,lt;
bitset<maxn> fix;

int solve(int L, int R, int mn, int mx)
{
    if (mn>mx)
        return INF;
    lt=0;
    lis[1]=INF;
    for (int i=L;i<=R;++i)
        if (mn<=a[i]&&a[i]<=mx)
        {
            l=0;r=lt;
            while (l<r)
            {
                m=l+((r-l)>>1)+1;
                if (lis[m]<=a[i])
                    l=m;
                else
                    r=m-1;
            }
            lis[l+1]=min(lis[l+1],a[i]);
            if (l==lt)
            {
                ++lt;
                lis[lt+1]=INF;
            }
        }
    return R-L+1-lt;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k,x,last=0;
    ll ans=0;
    cin>>n>>k;
    lis[0]=-INF;
    a[0]=-INF;
    fix[0]=1;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        a[i]-=i;
    }
    while (k--)
    {
        cin>>x;
        fix[x]=1;
    }
    a[n+1]=INF;
    fix[n+1]=1;
    for (int i=1;i<=n+1;++i)
        if (fix[i])
        {
            if (a[last]>a[i])
                ans+=INF;
            if (!fix[i-1])
                ans+=solve(last+1,i-1,a[last],a[i]);
            last=i;
        }
    if (ans>n)
        ans=-1;
    cout<<ans;
    return 0;
}