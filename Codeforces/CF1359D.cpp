#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
 
int segtree[1000000];
int a[1000000];
 
void build(int l, int r, int i)
{
    if (l==r)
    {
        segtree[i]=a[l];
        return;
    }
    build(l,l+(r-l)/2,2*i+1);
    build(l+(r-l)/2+1,r,2*i+2);
    segtree[i]=max(segtree[2*i+1],segtree[2*i+2]);
}
 
int query(int l, int r, int curL, int curR, int i)
{
    if (curR<l||r<curL)
        return -30;
    if (l<=curL&&curR<=r)
        return segtree[i];
    return max(query(l,r,curL,curL+(curR-curL)/2,2*i+1),query(l,r,curL+(curR-curL)/2+1,curR,2*i+2));
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,l=0,su=0,ans=0;
    cin>>n;
    for (int i=0;i<n;++i)
        cin>>a[i];
    build(0,n-1,0);
    for (int i=0;i<n;++i)
    {
        if (su>0)
        {
            su+=a[i];
            ans=max(ans,su-query(l,i,0,n-1,0));
        }
        else
        {
            l=i;
            su=a[i];
        }
    }
    cout<<ans;
    return 0;
}