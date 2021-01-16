#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 2e5+5, INF = 1e9;
int a[mn],p[mn],segTree[2][mn*4];

void build(int i, int l, int r)
{
    //cout<<l<<" "<<r<<"\n";
    if (l==r)
    {
        segTree[0][i]=segTree[1][i]=p[l];
        return;
    }
    build(i*2+1,l,l+(r-l)/2);
    build(i*2+2,l+(r-l)/2+1,r);
    segTree[0][i]=min(segTree[0][i*2+1],segTree[0][i*2+2]);
    segTree[1][i]=max(segTree[1][i*2+1],segTree[1][i*2+2]);
    //cout<<l<<" "<<r<<" "<<segTree[1][i]<<"\n";
}

int query(int i, int cL, int cR, int l, int r, int x)
{
    if (r<cL||cR<l)
    {
        if (x==0)
            return INF;
        else
            return -INF;
    }
    if (l<=cL&&cR<=r)
        return segTree[x][i];
    if (x)
        return max(query(i*2+1,cL,cL+(cR-cL)/2,l,r,x),query(i*2+2,cL+(cR-cL)/2+1,cR,l,r,x));
    return min(query(i*2+1,cL,cL+(cR-cL)/2,l,r,x),query(i*2+2,cL+(cR-cL)/2+1,cR,l,r,x));
}

void solve()
{
    int n,m,l,r,x,y;
    cin>>n>>m;
    string s;
    cin>>s;
    for (int i=0;i<n;++i)
    {
        if (s[i]=='-')
            a[i+1]=-1;
        else
            a[i+1]=1;
        p[i+1]=p[i]+a[i+1];
    }
    build(0,1,n);
    while (m--)
    {
        cin>>l>>r;
        if (l==1&&r==n)
        {
            cout<<"1\n";
            continue;
        }
        if (l==1)
        {
            x=-min(0,query(0,1,n,r+1,n,0)-p[r]);
            y=max(0,query(0,1,n,r+1,n,1)-p[r]);
            cout<<x+y+1<<"\n";
            continue;
        }
        if (r==n)
        {
            x=-min(0,query(0,1,n,1,l-1,0));
            y=max(0,query(0,1,n,1,l-1,1));
            cout<<x+y+1<<"\n";
            continue;
        }
        x=min(0,query(0,1,n,1,l-1,0));
        y=max(0,query(0,1,n,1,l-1,1));
        x=min(x,p[l-1]+query(0,1,n,r+1,n,0)-p[r]);
        y=max(y,p[l-1]+query(0,1,n,r+1,n,1)-p[r]);
        cout<<y-x+1<<"\n";
    }
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin>>tc;
    while (tc--)
        solve();
    return 0;
}