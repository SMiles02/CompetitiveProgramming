#include <bits/stdc++.h>
#include "robots.h"
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

bool ok(int k, vector<pair<int,int>> v, int X[], int Y[], int A, int B, int T)
{
    int cur=0;
    priority_queue<pair<int,int>> q;
    for (int i=0;i<A;++i)
    {
        while (cur<T)
        {
            if (v[cur].first>=X[i])
                break;
            q.push({v[cur].second,v[cur].first});
            ++cur;
        }
        for (int j=0;j<k&&sz(q);++j)
            q.pop();
    }
    while (cur<T)
    {
        q.push({v[cur].second,v[cur].first});
        ++cur;
    }
    for (int i=0;i<B;++i)
    {
        for (int j=0;j<k&&sz(q);++j)
        {
            if (q.top().first>=Y[i])
                return 0;
            q.pop();
        }
    }
    if (sz(q))
        return 0;
    return 1;
}

int putaway(int A,int B,int T,
int X[],int Y[],int W[],int S[])
{
    int l=1,r=T,m;
    vector<pair<int,int>> v;
    for (int i=0;i<T;++i)
        v.push_back({W[i],S[i]});
    sort(v.begin(), v.end());
    sort(X,X+A);
    sort(Y,Y+B,greater<int>());
    if (!ok(T,v,X,Y,A,B,T))
        return -1;
    while (l<r)
    {
        m=l+(r-l)/2;
        if (ok(m,v,X,Y,A,B,T))
            r=m;
        else
            l=m+1;
    }
    return l;
}