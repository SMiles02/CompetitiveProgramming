#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int a[200000];
int segTree[1000000];

void build(int i, int l, int r)
{
    if (l==r)
    {
        segTree[i]=a[l];
        return;
    }
    build(i*2,l,((l+r)>>1));
    build(i*2+1,((l+r)>>1)+1,r);
    segTree[i]=max(segTree[i*2],segTree[i*2+1]);
}

int query(int i, int l, int r, int x)
{
    int ans;
    if (l==r)
    {
        segTree[i]-=x;
        return l;
    }
    if (segTree[i*2]>=x)
        ans=query(i*2,l,((l+r)>>1),x);
    else
        ans=query(i*2+1,((l+r)>>1)+1,r,x);
    segTree[i]=max(segTree[i*2],segTree[i*2+1]);
    return ans;
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,k;
    cin>>n>>q;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    build(1,1,n);
    while (q--)
    {
        cin>>k;
        if (segTree[1]<k)
            cout<<"0 ";
        else
            cout<<query(1,1,n,k)<<" ";
    }
    return 0;
}