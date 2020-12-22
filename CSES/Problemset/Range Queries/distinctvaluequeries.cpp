#include <bits/stdc++.h>
using namespace std;

const int mn = 2e5+1;
int bit[mn];
vector<pair<int,int>> ed[mn];

void update(int i, int x)
{
    while (i<mn)
    {
        bit[i]+=x;
        i+=(i&-i);
    }
}

int pre(int i)
{
    int a=0;
    while (i)
    {
        a+=bit[i];
        i-=(i&-i);
    }
    return a;
}

int query(int l, int r) 
{
    return pre(r)-pre(l-1);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,x,y;
    cin>>n>>q;
    int a[n+1],ans[q];
    for (int i=1;i<=n;++i)
        cin>>a[i];
    map<int,int> m;
    for (int i=0;i<q;++i)
    {
        cin>>x>>y;
        ed[y].push_back({x,i});
    }
    for (int i=1;i<=n;++i)
    {
        if (m[a[i]])
            update(m[a[i]],-1);
        update(i,1);
        m[a[i]]=i;
        for (auto j : ed[i])
            ans[j.second]=query(j.first,i);
    }
    for (int i=0;i<q;++i)
        cout<<ans[i]<<"\n";
    return 0;
}