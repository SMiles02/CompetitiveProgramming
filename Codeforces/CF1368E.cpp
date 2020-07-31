#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

void solve()
{
    int n,m,ans=0,x,y;
    cin>>n>>m;
    vector<int> inc[n+1];
    int assigned[n+1];
    for (int i=1;i<=n;++i)
        inc[i].clear();
    while (m--)
    {
        cin>>x>>y;
        inc[y].push_back(x);
    }
    for (int i=1;i<=n;++i)
    {
        assigned[i]=0;
        for (int j : inc[i])
        {
            if (assigned[j]==1)
            {
                assigned[i]=2;
                ++ans;
                break;
            }
            if (assigned[j]==0)
                assigned[i]=1;
        }
    }
    cout<<ans<<"\n";
    for (int i=1;i<=n;++i)
        if (assigned[i]==2)
            cout<<i<<" ";
    cout<<"\n";
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