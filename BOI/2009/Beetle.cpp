#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int l[301][301][303];
int r[301][301][303];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,INF=1e8,z,ans=0;
    cin>>n>>m;
    ++n;
    int a[n];
    a[0]=0;
    for (int i=1;i<n;++i)
        cin>>a[i];
    sort(a,a+n);
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
            for (int k=0;k<=n;++k)
            {
                l[i][j][k]=INF;
                r[i][j][k]=INF;
            }
    for (int i=0;i<n;++i)
        for (int j=0;j<n;++j)
        {
            l[i][j][0]=0;
            r[i][j][0]=0;
        }
    for (int i=0;i<n;++i)
        if (a[i]==0)
            z=i;
    for (int k=1;k<n;++k)
        for (int i=0;i<n;++i)
            for (int j=i;j<n;++j)
            {
                if (0<i)
                {
                    l[i][j][k]=min(l[i][j][k],l[i-1][j][k-1]+k*(a[i]-a[i-1]));
                    r[i][j][k]=min(r[i][j][k],l[i-1][j][k-1]+k*(a[j]-a[i-1]));
                }
                if (j+1<n)
                {
                    l[i][j][k]=min(l[i][j][k],r[i][j+1][k-1]+k*(a[j+1]-a[i]));
                    r[i][j][k]=min(r[i][j][k],r[i][j+1][k-1]+k*(a[j+1]-a[j]));
                }
            }
    for (int i=0;i<n;++i)
        ans=max(ans,i*m-l[z][z][i]);
    cout<<ans;
    return 0;
}