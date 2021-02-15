#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 1e5+7;
vector<int> edges[mn];
bitset<mn> ok;

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y,ans=0;
    cin>>n;
    for (int i=1;i<n;++i)
    {
        cin>>x>>y;
        edges[x].push_back(y);
        edges[y].push_back(x);
    }
    for (int i=2;i<=n;++i)
        if (sz(edges[i])==1)
            ok[edges[i][0]]=1;
    for (int i=2;i<=n;++i)
        ans+=(sz(edges[i])==2&&ok[i]);
    cout<<ans;
    return 0;
}