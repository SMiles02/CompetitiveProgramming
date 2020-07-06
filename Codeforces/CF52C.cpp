#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int segTree[1000000];
int a[200000];

void build(int cur, int l, int r)
{
    if (l==r) 
    {
        segTree[cur]=a[l];
        return;
    }
    build(2*cur+1,l,l+(r-l)/2);
    build(2*cur+2,l+(r-l)/2+1,r);
    segTree[cur]=min(segTree[2*cur+1],segTree[2*cur+2]);
}

void query()
{
    int l,r,v;
    cin>>l>>r;
    
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
    }
    build(0,0,n-1);
    cin>>m;
    while (m--) query();
    return 0;
}