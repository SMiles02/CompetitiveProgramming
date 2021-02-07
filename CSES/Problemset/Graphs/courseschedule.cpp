#include <bits/stdc++.h>
using namespace std;

const int mn = 1e5+1;
vector<int> from[mn];
int to[mn];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,x,y;
    cin>>n>>m;
    while (m--)
    {
        cin>>x>>y;
        from[x].push_back(y);
        ++to[y];
    }
    stack<int> s;
    int ans[n];
    y=-1;
    for (int i=1;i<=n;++i)
        if (!to[i])
            s.push(i);
    while (!s.empty())
    {
        x=s.top();
        s.pop();
        ans[++y]=x;
        for (int i : from[x])
            if (!--to[i])
                s.push(i);
    }
    if (++y^n)
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    for (int i=0;i<n;++i)
        cout<<ans[i]<<" ";
    return 0;
}