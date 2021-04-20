#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 2e5+1;
int n,c[N],d;
ll ans;
vector<array<int,3>> v[N];
vector<int> p;

int newnode(int I)
{
    v[I].push_back({-1,-1,0});
    return c[I]++;
}

void find(int I, int i, int l, int r)
{
    if (i==-1||v[I][i][2]==0)
        return;
    if (l==r)
    {
        p.push_back(l);
        return;
    }
    find(I,v[I][i][0],l,l+(r-l)/2);
    find(I,v[I][i][1],l+(r-l)/2+1,r);
}

void find(int I)
{
    find(I,0,1,n);
}

int update(int I, int i, int l, int r, int x)
{
    if (r<x||x<l)
        return i;
    if (i==-1)
        i=newnode(I);
    ++v[I][i][2];
    if (l==r)
        return i;
    v[I][i][0] = update(I,v[I][i][0],l,l+(r-l)/2,x);
    v[I][i][1] = update(I,v[I][i][1],l+(r-l)/2+1,r,x);
    return i;
}

void update(int I, int x)
{
    update(I,0,1,n,x);
}

int query(int I, int i, int l, int r, int x)
{
    if (i==-1||x<l)
        return 0;
    if (r<=x)
        return v[I][i][2];
    return query(I,v[I][i][0],l,l+(r-l)/2,x) + query(I,v[I][i][1],l+(r-l)/2+1,r,x);
}

int query(int I, int x)
{
    return query(I,0,1,n,x);
}

int size(int I)
{
    return v[I][0][2];
}

int seg(int x)
{
    newnode(d);
    update(d,x);
    return d++;
}

int dfs()
{
    int x;
    cin>>x;
    if (x)
        return seg(x);
    int s = dfs(), t = dfs();
    if (size(s) < size(t))
        swap(s,t);
    ll y=0,z=1LL*size(s)*size(t);
    p.clear();
    find(t);
    for (int i : p)
        y+=query(s,i);
    for (int i : p)
        update(s,i);
    ans+=min(y,z-y);
    return s;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    dfs();
    cout<<ans;
    return 0;
}