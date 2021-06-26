#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 1e5+1;
int t;
vector<int> children[mn];
vector<array<int,3>> v;
bitset<mn> ans;
set<array<int,2>> s1,s2;

void dfs(int c, int h)
{
    v.push_back({h,++t,c});
    for (int i : children[c])
        dfs(i,h+1);
}

void dfs2(int c, int h, int x)
{
    if (ans[c])
        ++x;
    s1.insert({h,x});
    for (int i : children[c])
        dfs2(i,h+1,x);
}

void dfs3(int c, int h, int x)
{
    if (ans[c])
        ++x;
    s2.insert({h,x});
    for (int i : children[c])
        dfs3(i,h+1,x);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,k;
    cin>>n>>x;
    for (int i=2;i<=n;++i)
    {
        cin>>k;
        children[k].push_back(i);
    }
    dfs(1,0);
    sort(v.rbegin(), v.rend());
    for (int i=0;i<x;++i)
        ans[v[i][2]]=1;
    dfs2(1,0,0);
    for (int i=0;i<n;++i)
        ans[i]=0;
    for (int i=n-x;i<n;++i)
        ans[v[i][2]]=1;
    dfs3(1,0,0);
    cout<<min(sz(s1),sz(s2))<<"\n";
    if (sz(s1)<sz(s2))
    {
        for (int i=0;i<n;++i)
            ans[i]=0;
        for (int i=0;i<x;++i)
            ans[v[i][2]]=1;
    }
    for (int i=1;i<=n;++i)
    {
        if (ans[i])
            cout<<"a";
        else
            cout<<"b";
    }
    return 0;
}