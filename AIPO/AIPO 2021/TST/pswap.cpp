#include <bits/stdc++.h>
using namespace std;

const int N = 2507;
int p[N][N*2];
bitset<N> e[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,ans=0;
    bool ok;
    cin>>n>>m;
    for (int i=0;i<n;++i)
        for (int j=0;j<m;++j)
            cin>>p[i][j];
    for (int i=0;i<n;++i)
        for (int j=i+1;j<n;++j)
        {
            x=0;
            for (int k=0;k<m;++k)
                x+=(p[i][k]!=p[j][k]);
            if (x<3)
            {
                e[i][j]=1;
                e[j][i]=1;
            }
        }
    for (int i=1;i<(1<<n);++i)
    {
        ok=1;
        for (int j=0;j<n;++j)
            if (i&(1<<j))
                for (int k=0;k<j;++k)
                    if (i&(1<<k))
                        if (e[j][k])
                            ok=0;
        ans=max(ans,__builtin_popcount(i));
    }
    cout<<ans;
    return 0;
}