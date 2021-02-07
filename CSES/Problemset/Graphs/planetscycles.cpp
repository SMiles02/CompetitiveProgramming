#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 2e5+1;
int ans[mn],cmp[mn],to[mn],t,g;
vector<int> e1[mn], e2[mn], e3[mn];
vector<array<int,2>> v;
set<int> exist[mn];
bitset<mn> done;

void dfs1(int c)
{
    done[c]=1;
    for (int i : e1[c])
        if (!done[i])
            dfs1(i);
    v.push_back({++t,c});
}

void dfs2(int c)
{
    done[c]=1;
    cmp[c]=t;
    ++g;
    for (int i : e2[c])
        if (!done[i])
            dfs2(i);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n;
    for (int i=1;i<=n;++i)
    {
        cin>>k;
        e1[k].push_back(i);
        e2[i].push_back(k);
    }
    for (int i=1;i<=n;++i)
        if (!done[i])
            dfs1(i);
    sort(v.rbegin(), v.rend());
    done.reset();
    t=0;
    for (auto i : v)
        if (!done[i[1]])
        {
            ++t;
            g=0;
            dfs2(i[1]);
            ans[t]=g;
        }
    for (int i=1;i<=n;++i)
        for (int j : e1[i])
            if (cmp[i]^cmp[j]&&exist[cmp[i]].find(cmp[j])==exist[cmp[i]].end())
            {
                e3[cmp[i]].push_back(cmp[j]);
                ++to[cmp[j]];
                exist[cmp[i]].insert(cmp[j]);
            }
    stack<int> s;
    for (int i=1;i<=t;++i)
        if (to[i]==0)
            s.push(i);
    while (!s.empty())
    {
        k=s.top();
        s.pop();
        for (int i : e3[k])
        {
            ans[i]+=ans[k];
            if (--to[i]==0)
                s.push(i);
        }
    }
    for (int i=1;i<=n;++i)
        cout<<ans[cmp[i]]<<" ";
    return 0;
}