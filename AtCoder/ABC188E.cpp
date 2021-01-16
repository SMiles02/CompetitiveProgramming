#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 2e5+7, INF = 2e9;
int n, a[mn], minVal[mn], to[mn];
vector<int> from[mn];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int m,x,y,ans=-INF;
    cin>>n>>m;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        minVal[i]=INF;
    }
    while (m--)
    {
        cin>>x>>y;
        from[x].push_back(y);
        ++to[y];
    }
    stack<int> s;
    for (int i=1;i<=n;++i)
        if (to[i]==0)
            s.push(i);
    while (!s.empty())
    {
        x=s.top();s.pop();
        ans=max(ans,a[x]-minVal[x]);
        minVal[x]=min(minVal[x],a[x]);
        for (int i : from[x])
        {
            minVal[i]=min(minVal[i],minVal[x]);
            if (--to[i]==0)
                s.push(i);
        }
    }
    cout<<ans;
    return 0;
}