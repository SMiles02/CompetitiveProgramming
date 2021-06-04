#include <bits/stdc++.h>
using namespace std;

const int N = 1e5+2;
int nxt[N], ct[N], e[N], a[N];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,b,t,x,y,ans;
    cin>>n>>q;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        a[i]=min(i+a[i],n+1);
    }
    b=sqrt(n);
    x=n;
    for (int i=n;i;--i)
    {
        if (i%b==0)
            x=i;
        e[i]=x;
        if (a[i]>x)
        {
            nxt[i]=a[i];
            ct[i]=1;
        }
        else
        {
            nxt[i]=nxt[a[i]];
            ct[i]=ct[a[i]]+1;
        }
    }
    while (q--)
    {
        cin>>t;
        if (t==0)
        {
            cin>>x>>y;
            a[x]=min(n+1,x+y);
            for (int i=x;e[i]==e[x];--i)
            {
                if (a[i]>e[i])
                {
                    nxt[i]=a[i];
                    ct[i]=1;
                }
                else
                {
                    nxt[i]=nxt[a[i]];
                    ct[i]=ct[a[i]]+1;
                }
            }
        }
        else
        {
            cin>>x;
            ans=0;
            while (nxt[x]<=n)
            {
                ans+=ct[x];
                x=nxt[x];
            }
            while (a[x]<=n)
            {
                ++ans;
                x=a[x];
            }
            cout<<x<<" "<<ans+1<<"\n";
        }
    }
    return 0;
}