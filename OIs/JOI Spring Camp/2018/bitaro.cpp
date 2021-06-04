#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;
 
const int N = 1e5+4, B = 316, INF = -1e9;
vector<int> to[N], from[N];
vector<array<int,2>> pre[N];
int ans[N];
bitset<N> d;
 
vector<array<int,2>> merge(vector<array<int,2>> v, vector<array<int,2>> w)
{
    int x=0,y=0;
    vector<array<int,2>> u;
    while (x<sz(v)&&y<sz(w)&&sz(u)<B)
    {
        if (v[x][0]+1>w[y][0])
        {
            if (!d[v[x][1]])
            {
                d[v[x][1]]=1;
                u.push_back({v[x][0]+1,v[x][1]});
            }
            ++x;
        }
        else
        {
            if (!d[w[y][1]])
            {
                d[w[y][1]]=1;
                u.push_back(w[y]);
            }
            ++y;
        }
    }
    while (x<sz(v)&&sz(u)<B)
    {
        if (!d[v[x][1]])
        {
            d[v[x][1]]=1;
            u.push_back({v[x][0]+1,v[x][1]});
        }
        ++x;
    }
    while (y<sz(w)&&sz(u)<B)
    {
        if (!d[w[y][1]])
        {
            d[w[y][1]]=1;
            u.push_back(w[y]);
        }
        ++y;
    }
    for (auto i : u)
        d[i[1]]=0;
    return u;
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,q,x,y,z,a;
    cin>>n>>m>>q;
    while (m--)
    {
        cin>>x>>y;
        from[x].push_back(y);
        to[y].push_back(x);
    }
    for (int i=1;i<=n;++i)
        pre[i].push_back({0,i});
    for (int i=1;i<=n;++i)
        for (int j : from[i])
            pre[j]=merge(pre[i],pre[j]);
    while (q--)
    {
        cin>>x>>y;
        a=-1;
        if (y<B)
        {
            vector<int> t(y);
            for (int i=0;i<y;++i)
            {
                cin>>t[i];
                d[t[i]]=1;
            }
            for (auto i : pre[x])
                if (!d[i[1]])
                    a=max(a,i[0]);
            for (int i : t)
                d[i]=0;
        }
        else
        {
            for (int i=0;i<y;++i)
            {
                cin>>z;
                if (z<=x)
                    d[z]=1;
            }
            for (int i=1;i<=x;++i)
                ans[i]=INF;
            ans[x]=0;
            for (int i=x;i;--i)
            {
                if (!d[i])
                    a=max(a,ans[i]);
                else
                    d[i]=0;
                for (int j : to[i])
                    ans[j]=max(ans[j],ans[i]+1);
            }
        }
        cout<<a<<"\n";
    }
    return 0;
}