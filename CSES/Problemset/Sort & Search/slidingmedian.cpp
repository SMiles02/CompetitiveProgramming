#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int fenwick[200001],x,med;

void update(int i, int delta)
{
    while (i<=x)
    {
        fenwick[i]+=delta;
        i+=(i&-i);
    }
}

int prefix(int i)
{
    int s=0;
    while (i)
    {
        s+=fenwick[i];
        i-=(i&-i);
    }
    return s;
}

int binsearch()
{
    int l=1,r=x,m;
    while (l<r)
    {
        m=l+((r-l)>>1);
        if (prefix(m)<med)
            l=m+1;
        else
            r=m;
    }
    return l;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n>>k;
    int a[n],b[n+1];
    map<int,int> pos;
    set<int> s;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        s.insert(a[i]);
    }
    for (int i : s)
    {
        b[++x]=i;
        pos[i]=x;
    }
    med=(k+1)/2;
    for (int i=0;i<k;++i)
        update(pos[a[i]],1);
    cout<<b[binsearch()]<<" ";
    for (int i=k;i<n;++i)
    {
        update(pos[a[i-k]],-1);
        update(pos[a[i]],1);
        cout<<b[binsearch()]<<" ";
    }
    return 0;
}