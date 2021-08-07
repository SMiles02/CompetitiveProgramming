#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define int ll
using namespace std;

const int N = 2e5+7, L = 18, INF = 1e9+7;
ll sparse[N][L], a[N];

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

void solve()
{
    int n,ans=1,cur;
    ll g;
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    if (n==1)
    {
        cout<<"1\n";
        return;
    }
    for (int i=n-1;i>0;--i)
    {
        sparse[i][0]=abs(a[i+1]-a[i]);
        for (int j=1;j<L;++j)
            if (i+(1<<j)-1<n)
                sparse[i][j]=gcd(sparse[i][j-1],sparse[i+(1<<(j-1))][j-1]);
    }
    for (int i=1;i<n;++i)
        if (abs(a[i+1]-a[i])>1)
        {
            cur=i+1;g=abs(a[i+1]-a[i]);
            for (int j=L-1;j>=0;--j)
                if (cur+(1<<j)-1<n)
                    if (cur+(1<<j)-1<n&&gcd(g,sparse[cur][j])>1)
                    {
                        g=gcd(g,sparse[cur][j]);
                        cur+=(1<<j);
                    }
            ans=max(ans,cur-i+1);
        }
    cout<<ans<<"\n";
}
 
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}