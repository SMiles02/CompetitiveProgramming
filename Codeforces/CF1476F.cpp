#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 3e5+7, INF = 1e9+7;
int segTree[mn*4][2], p[mn];

void build(int i, int l, int r)
{
    if (l==r)
    {
        segTree[i][0]=l-p[l];
        segTree[i][1]=l+p[l];
        return;
    }
    build(i*2+1,l,l+(r-l)/2);
    build(i*2+2,l+(r-l)/2+1,r);
    segTree[i][0]=min(segTree[i*2+1][0],segTree[i*2+2][0]);
    segTree[i][1]=max(segTree[i*2+1][1],segTree[i*2+2][1]);
}

int query(int i, int cL, int cR, int l, int r, int j)
{
    if (r<cL||cR<l)
    {
        if (j==0)
            return INF;
        return 0;
    }
    if (l<=cL&&cR<=r)
        return segTree[i][j];
    if (j==0)
        return min(query(i*2+1,cL,cL+(cR-cL)/2,l,r,j),query(i*2+2,cL+(cR-cL)/2+1,cR,l,r,j));
    return max(query(i*2+1,cL,cL+(cR-cL)/2,l,r,j),query(i*2+2,cL+(cR-cL)/2+1,cR,l,r,j));
}

void solve()
{
    int n,l,r,m,c=1;
    bool b=0;
    cin>>n;
    for (int i=1;i<=n;++i)
        cin>>p[i];
    build(0,1,n);
    string ans(n+1,'R');
    while (c<n)
    {
        if (c<query(0,1,n,c+1,n,0))
        {
            cout<<"NO\n";
            return;
        }
        l=c+1;r=n;
        while (l^r)
        {
            m=l+(r-l)/2+1;
            if (c<query(0,1,n,m,n,0))
                r=m-1;
            else
                l=m;
        }
        ans[l]='L';
        if (b==0&&query(0,1,n,c,l-1,1)<l)
        {
            c=l;
        }
        else if (b==1&&query(0,1,n,c,l-1,1)<l)
        {
            c=l;
        }
        else
        {
            c=l+1;
            b=1;
        }
    }
    if (c==n)
    {
        cout<<"NO\n";
        return;
    }
    cout<<"YES\n";
    for (int i=1;i<=n;++i)
        cout<<ans[i];
    cout<<"\n";
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