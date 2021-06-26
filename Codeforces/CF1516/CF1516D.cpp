#include <bits/stdc++.h>
using namespace std;

const int N = 1e5, lg = 17;
int last[N+1],up[lg][N+1];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,x,l,r;
    cin>>n>>q;
    int a[n+1];
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=0;i<lg;++i)
        up[i][0]=1;
    for (int i=1;i<=n;++i)
    {
        x=up[0][i-1];
        for (int j=2;j*j<=a[i];++j)
            if (a[i]%j==0)
            {
                x=max(x,last[j]+1);
                last[j]=i;
                while (a[i]%j==0)
                    a[i]/=j;
            }
        if (a[i]>1)
        {
            x=max(x,last[a[i]]+1);
            last[a[i]]=i;
        }
        up[0][i]=x;
        for (int j=1;j<lg;++j)
            up[j][i]=up[j-1][up[j-1][i]-1];
    }
    while (q--)
    {
        cin>>l>>r;
        x=0;
        for (int i=lg-1;i>=0;--i)
            if (up[i][r]>l)
            {
                x+=(1<<i);
                r=up[i][r]-1;
            }
        cout<<x+1<<"\n";
    }
    return 0;
}