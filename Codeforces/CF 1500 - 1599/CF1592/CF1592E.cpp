#include <bits/stdc++.h>
using namespace std;

const int N = 2e6, INF = 1e9;
int a[N], p[N], v[2][N];
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,ans=0,x=(1<<25)-1,l;
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=0;i<N;++i)
    {
        v[0][i]=INF;
        v[1][i]=INF;
    }
    for (int k=1;k<1e6;k*=2)
    {
        x^=k;
        l=-1;
        v[0][0]=0;
        for (int i=1;i<=n;++i)
        {
            p[i]=p[i-1]^a[i]&x;
            if (a[i]&k)
                ans=max(ans,i-v[i&1][p[i]]);
            else
            {
                for (int j=l+1;j<i;++j)
                    v[j&1][p[j]]=INF;
                l=i-1;
            }
            if (v[i&1][p[i]]==INF)
                v[i&1][p[i]]=i;
        }
        for (int j=l+1;j<=n;++j)
            v[j&1][p[j]]=INF;
    }
    cout<<ans;
    return 0;
}