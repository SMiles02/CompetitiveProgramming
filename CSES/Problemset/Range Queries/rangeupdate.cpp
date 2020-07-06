#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

ll ans;
int a[200001];
int segPosition[200001];
ll segTree[1000000];

void build(int l, int r, int i)
{
    if (l==r)
    {
        segTree[i]=a[l];
        segPosition[l]=i;
        return;
    }
    build(l,l+(r-l)/2,i*2+1);
    build(l+(r-l)/2+1,r,i*2+2);
}

void update(int curL, int curR, int l, int r, int x, int i)
{
    if (curR<l||r<curL)
        return;
    if (l<=curL&&curR<=r)
    {
        segTree[i]+=x;
        return;
    }
    update(curL,curL+(curR-curL)/2,l,r,x,i*2+1);
    update(curL+(curR-curL)/2+1,curR,l,r,x,i*2+2);
}

void query(int x)
{
    ll ans=0;
    int flag=1;
    while (flag)
    {
        if (x==0)
            flag=0;
        ans+=segTree[x];
        --x;
        x/=2;
    }
    cout<<ans<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,w,x,y,z;
    cin>>n>>q;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    build(1,n,0);
    while (q--)
    {
        cin>>w;
        if (w==1)
        {
            cin>>x>>y>>z;
            update(1,n,x,y,z,0);
        }
        else
        {
            cin>>x;
            query(segPosition[x]);
        }
    }
    return 0;
}