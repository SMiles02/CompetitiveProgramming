#include <bits/stdc++.h>
using namespace std;

const int mn = 2e5+7;
int f[mn];

void solve()
{
    int n,m,x,y,a,b,ans=0;
    cin>>n>>m;
    for (int i=0;i<m;++i)
        f[i]=0;
    for (int i=0;i<n;++i)
    {
        cin>>x;
        ++f[x%m];
    }
    priority_queue<array<int,2>> pq;
    for (int i=0;i<m;++i)
        if (f[i])
            pq.push({f[i],i});
    while (!pq.empty())
    {
        x=pq.top()[0];
        y=pq.top()[1];
        pq.pop();
        if (x!=f[y])
            continue;
        a=y;
        b=(m-y)%m;
        ++ans;
        for (int i=0;1;++i)
        {
            if (i&1)
            {
                if (f[b]--<=0)
                    break;
            }
            else
            {
                if (f[a]--<=0)
                    break;
            }
        }
        if (f[a]>0)
            pq.push({f[a],a});
        if (f[b]>0)
            pq.push({f[b],b});
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}