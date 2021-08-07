//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1e5+7, L = 17;
int a[N], up[N][L];

void solve()
{
    int n,k,s,ans=0,c,tmp=0,r;
    cin>>n>>k>>s;
    r=n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=0;i<L;++i)
        up[n+1][i]=up[n+2][i]=n;
    for (int i=n;i>0;--i)
    {
        tmp+=a[i];
        while (tmp>s)
            tmp-=a[r--];
        up[i][0]=r;
        for (int j=1;j<L;++j)
            up[i][j]=up[up[i][j-1]+1][j-1];
        c=i-1;
        for (int j=0;j<L;++j)
            if (k&(1<<j))
                c=up[c+1][j];
        //cout<<i<<" "<<c<<"\n";
        ans=max(ans,c-i+1);
    }
    cout<<ans<<"\n";
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