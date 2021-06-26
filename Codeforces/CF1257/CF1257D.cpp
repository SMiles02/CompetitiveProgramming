#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

int segtree[1000000];
int a[200000];

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

void solve()
{
    int n,m,maxi=0,done=0,l,r,mid,l1,r1,m1,health,ans=0;
    cin>>n;
    for (int i=0;i<n;++i)
    {
        cin>>a[i];
        maxi=max(maxi,a[i]);
    }
    cin>>m;
    pair<int,int> h[m];
    for (int i=0;i<m;++i)
        cin>>h[i].first>>h[i].second;
    sort(h,h+m);
    if (h[m-1].first<maxi)
    {
        cout<<"-1\n";
        return;
    }
    int suff[m];
    suff[m-1]=h[m-1].second;
    for (int i=m-2;i+1;--i)
        suff[i]=max(suff[i+1],h[i].second);
    build(0,n-1,0);
    while (done<n)
    {
        l=done;r=n-1;
        while (l<r)
        {
            mid=l+(r-l)/2+1;
            health=query(done,mid,0,n-1,0);
            l1=0;r1=m-1;
            while (l1<r1)
            {
                m1=l1+(r1-l1)/2;
                if (h[m1].first<health)
                    l1=m1+1;
                else
                    r1=m1;
            }
            if (suff[l1]<mid-done+1)
                r=mid-1;
            else
                l=mid;
        }
        ++ans;
        done=l+1;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
        solve();
    return 0;
}