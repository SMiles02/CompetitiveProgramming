//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int N = 1e5+7;
int a[2][N], p[2][N];

void solve()
{
    int n, ans=2e9;
    cin>>n;
    for (int i=0;i<2;++i)
        for (int j=1;j<=n;++j)
        {
            cin>>a[i][j];
            p[i][j]=p[i][j-1]+a[i][j];
        }
    for (int i=1;i<=n;++i)
        ans=min(ans,max(p[1][i-1],p[0][n]-p[0][i]));
    cout<<ans<<"\n";
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