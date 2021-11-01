#include <bits/stdc++.h>
using namespace std;

const int N = 4e5+1;
int ans[N], eC[N];
vector<int> e[N];

void solve()
{
    int n,k,x,y;
    cin>>n>>k;
    for (int i=1;i<=n;++i)
    {
        ans[i]=n+2;
        eC[i]=0;
        e[i].clear();
    }
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        e[x].push_back(y);
        e[y].push_back(x);
    }
    queue<int> q;
    for (int i=1;i<=n;++i)
    {
        eC[i]=e[i].size();
        if (eC[i]<=1)
        {
            ans[i]=1;
            q.push(i);
        }
    }
    while (!q.empty())
    {
        x=q.front();
        q.pop();
        for (int i : e[x])
            if (ans[x]+1<ans[i]&&--eC[i]<=1)
            {
                ans[i]=ans[x]+1;
                q.push(i);
            }
    }
    x=0;
    for (int i=1;i<=n;++i)
        x+=(ans[i]>k);
    cout<<x<<"\n";
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}