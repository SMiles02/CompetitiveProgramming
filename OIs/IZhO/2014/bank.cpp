#include <bits/stdc++.h>
using namespace std;

bitset<21> ct[(1<<20)];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,s,l;
    cin>>n>>m;
    int p[n+1],a[m];
    p[0]=0;
    for (int i=1;i<=n;++i)
        cin>>p[i],p[i]+=p[i-1];
    for (int i=0;i<m;++i)
        cin>>a[i],ct[1<<i][0]=1;
    for (int i=1;i<(1<<m);++i)
    {
        s=0;
        for (int j=0;j<m;++j)
            if (i&(1<<j))
                s+=a[j];
        l=0;
        for (int j=1;j<=n;++j)
            if (s==p[j])
                l=j;
        if (s==p[l]&&ct[i][l-1])
            ct[i][l]=1;
        for (int j=0;j<m;++j)
            if (!(i&(1<<j)))
                for (int k=0;k<=n;++k)
                    ct[i^(1<<j)][k]=ct[i^(1<<j)][k]|ct[i][k];
    }
    if (ct[(1<<m)-1][n])
        cout<<"YES";
    else
        cout<<"NO";
    return 0;
}