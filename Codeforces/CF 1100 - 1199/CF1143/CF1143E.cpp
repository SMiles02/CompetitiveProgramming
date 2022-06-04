#include <bits/stdc++.h>
using namespace std;

const int N = 2e5+1;
int up[18][N],p[N],l[N],mx[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,q,x,y;
    cin>>n>>m>>q;
    int a[n+1];
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        p[a[i]]=i;
    }
    a[0]=a[n];
    for (int i=1;i<=m;++i)
    {
        cin>>x;
        up[0][i]=l[a[p[x]-1]];
        for (int j=1;j<18;++j)
            up[j][i]=up[j-1][up[j-1][i]];
        y=i;
        for (int j=0;j<18;++j)
            if ((n-1)&(1<<j))
                y=up[j][y];
        mx[i]=max(mx[i-1],y);
        l[x]=i;
    }
    while (q--)
    {
        cin>>x>>y;
        if (mx[y]<x)
            cout<<0;
        else
            cout<<1;
    }
    return 0;
}