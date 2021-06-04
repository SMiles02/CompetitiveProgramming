#include "secret.h"
 
int n, a[1000], pre[1000][1000];
 
void build(int l, int r)
{
    if (l+1>=r)
        return;
    int m=l+(r-l)/2;
    pre[m][m]=a[m];
    pre[m+1][m+1]=a[m+1];
    for (int i=m-1;i>=l;--i)
        pre[i][m]=Secret(a[i],pre[i+1][m]);
    for (int i=m+2;i<=r;++i)
        pre[m+1][i]=Secret(pre[m+1][i-1],a[i]);
    build(l,m);
    build(m+1,r);
}
 
void Init(int N, int A[])
{
    n=N;
    for (int i=0;i<n;++i)
        a[i]=A[i];
    build(0,n-1);
}
 
int Query(int l, int r)
{
    if (l==r)
        return a[l];
    if (l+1==r)
        return Secret(a[l],a[r]);
    int x=0, y=n-1, m;
    while (1)
    {
        m=x+(y-x)/2;
        if (l<=m&&m<r)
            return Secret(pre[l][m],pre[m+1][r]);
        if (m<l)
            x=m+1;
        else
            y=m;
    }
    return -1;
}