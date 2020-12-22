#include <bits/stdc++.h>
#define pii pair<int,int>
#define f first
#define s second
using namespace std;

int t;
vector<int> edges[1000];
vector<pii> temp;

void dfs(int c, int p, bool h)
{
    ++t;
    if (!h)
        temp.push_back({t,c});
    for (int i : edges[c])
        if (i!=p)
            dfs(i,c,h^1);
    ++t;
    if (h)
        temp.push_back({t,c});    
}

vector<int> label(int n, int k, vector<int> u, vector<int> v)
{
    vector<int> labels(n);
    for (int i=0;i<n;++i)
        edges[i].clear();
    for (int i=0;i<n-1;++i)
    {
        edges[u[i]].push_back(v[i]);
        edges[v[i]].push_back(u[i]);
    }
    temp.clear();
    t=-1;
    dfs(0,-1,0);
    sort(temp.begin(), temp.end());
    for (int i=0;i<n;++i)
        labels[temp[i].s]=i;
    return labels;
}

int find_next_station(int a, int b, vector<int> c)
{
    int x = c.size();
    sort(c.begin(), c.end());
    if (a==0)
    {
        if (1<=b&&b<=c[0])
            return c[0];
        for (int i=1;i<x;++i)
            if (c[i-1]+1<=b&&b<=c[i])
                return c[i];
    }
    if (a<c[0])
    {
        if (x>1)
        {
            if (a+1<=b&&b<=c[0])
                return c[0];
            for (int i=1;i<x-1;++i)
                if (c[i-1]+1<=b&&b<=c[i])
                    return c[i];
        }
        return c.back();
    }
    if (x>1)
    {
        if (c[x-1]<=b&&b<=a-1)
            return c[x-1];
        for (int i=x-2;i>0;--i)
            if (c[i]<=b&&b<=c[i+1]-1)
                return c[i];
    }
    return c[0];
}