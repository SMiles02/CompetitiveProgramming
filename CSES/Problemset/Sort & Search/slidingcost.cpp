#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll fenwick[2][200001];
int x,med,b[200001];

void update(int i, int delta, int j)
{
    while (i<=x)
    {
        fenwick[j][i]+=delta;
        i+=(i&-i);
    }
}

ll prefix(int i, int j)
{
    ll s=0;
    while (i)
    {
        s+=fenwick[j][i];
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
        if (prefix(m,0)<med)
            l=m+1;
        else
            r=m;
    }
    return l;
}

void process()
{
    int n=binsearch();
    cout<<(prefix(n-1,0)*b[n]-prefix(n-1,1))+((prefix(x,1)-prefix(n,1))-((prefix(x,0)-prefix(n,0))*b[n]))<<" ";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n>>k;
    int a[n];
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
    {
        update(pos[a[i]],1,0);
        update(pos[a[i]],a[i],1);
    }
    process();
    for (int i=k;i<n;++i)
    {
        update(pos[a[i-k]],-1,0);
        update(pos[a[i-k]],-a[i-k],1);
        update(pos[a[i]],1,0);
        update(pos[a[i]],a[i],1);
        process();
    }
    return 0;
}