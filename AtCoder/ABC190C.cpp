#include <bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,k,ans=0,cur;
    cin>>n>>m;
    int a[m][2],b[n+1];
    for (int i=0;i<m;++i)
        cin>>a[i][0]>>a[i][1];
    cin>>k;
    int c[k][2];
    for (int i=0;i<k;++i)
        cin>>c[i][0]>>c[i][1];
    for (int i=0;i<(1<<k);++i)
    {
        for (int j=1;j<=n;++j)
            b[j]=0;
        for (int j=0;j<k;++j)
        {
            if (i&(1<<j))
                ++b[c[j][0]];
            else
                ++b[c[j][1]];
        }
        cur=0;
        for (int j=0;j<m;++j)
            if (b[a[j][0]]&&b[a[j][1]])
                ++cur;
        ans=max(ans,cur);
    }
    cout<<ans;
    return 0;
}