#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+1;
int p[N],r[N];
bitset<N> dp;

int findParent(int x)
{
    if (p[x]==x)
        return x;
    return p[x] = findParent(p[x]);
}

void unite(int x, int y)
{
    x = findParent(x);
    y = findParent(y);
    if (x!=y)
    {
        if (r[x]<r[y])
            swap(x,y);
        p[y]=x;
        r[x]+=r[y];
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,y;
    cin>>n>>m;
    for (int i=1;i<=n;++i)
    {
        p[i]=i;
        r[i]=1;
    }
    while (m--)
    {
        cin>>x>>y;
        unite(x,y);
    }
    dp[0]=1;
    for (int i=1;i<=n;++i)
        if (findParent(i)==i)
            dp|=dp<<r[i];
    for (int i=1;i<=n;++i)
        cout<<dp[i];
    return 0;
}