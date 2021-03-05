#include <bits/stdc++.h>
using namespace std;

const int mn = 1e5+1;
int p[mn],d[mn],to[mn];
vector<int> from[mn];
bitset<mn> done;

void dfs(int c)
{
    done[c]=1;
    for (int i : from[c])
        if (!done[i])
            dfs(i);
}

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
    dfs(1);
    for (int i=2;i<=n;++i)
        if (!done[i])
            for (int j : from[i])
                --to[j];
    stack<int> s;
    s.push(1);
    while (!s.empty())
    {
        x=s.top();
        s.pop();
        for (int i : from[x])
        {
            if (d[i]<d[x]+1)
            {
                d[i]=d[x]+1;
                p[i]=x;
            }
            if (--to[i]==0)
                s.push(i);
        }
    }
    if (d[n]==0)
    {
        cout<<"IMPOSSIBLE";
        return 0;
    }
    while (n)
    {
        s.push(n);
        n=p[n];
    }
    cout<<s.size()<<"\n";
    while (!s.empty())
    {
        cout<<s.top()<<" ";
        s.pop();
    }
    return 0;
}