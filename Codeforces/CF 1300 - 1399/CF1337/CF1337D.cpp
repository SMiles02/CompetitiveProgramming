#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
 
ll ans;
 
int binSearchAbove(int a[], int n, int s)
{
    if (a[s-1]<n)
    {
        return a[s-1];
    }
    int l=0,r=s-1,m;
    while (l<r)
    {
        m=l+(r-l)/2;
        if (a[m]<n)
        {
            l=m+1;
        }
        else
        {
            r=m;
        }
    }
    return a[l];
}
 
int binSearchBelow(int a[], int n, int s)
{
    if (a[0]>n)
    {
        return a[0];
    }
    int l=0,r=s-1,m;
    while (l<r)
    {
        m=l+(r-l)/2+1;
        if (a[m]>n)
        {
            r=m-1;
        }
        else
        {
            l=m;
        }
    }
    return a[l];
}
 
ll sq(ll a)
{
    return a*a;
}
 
ll sumS(ll a, ll b, ll c)
{
    return sq(a-b)+sq(b-c)+sq(c-a);
}
 
void numGetter(int r[], int g[], int b[], int x, int y, int z)
{
    int s,t;
    for (int i=0;i<x;++i)
    {
        s=binSearchBelow(g,r[i],y);
        t=binSearchBelow(b,r[i],z);
        ans=min(ans,sumS(r[i],s,t));
        t=binSearchAbove(b,r[i],z);
        ans=min(ans,sumS(r[i],s,t));
        t=binSearchBelow(b,min(r[i],s)+abs(r[i]-s)/2,z);
        ans=min(ans,sumS(r[i],s,t));
        t=binSearchAbove(b,min(r[i],s)+abs(r[i]-s)/2+1,z);
        ans=min(ans,sumS(r[i],s,t));
        s=binSearchAbove(g,r[i],y);
        t=binSearchBelow(b,r[i],z);
        ans=min(ans,sumS(r[i],s,t));
        t=binSearchAbove(b,r[i],z);
        ans=min(ans,sumS(r[i],s,t));
        t=binSearchBelow(b,min(r[i],s)+abs(r[i]-s)/2,z);
        ans=min(ans,sumS(r[i],s,t));
        t=binSearchAbove(b,min(r[i],s)+abs(r[i]-s)/2+1,z);
        ans=min(ans,sumS(r[i],s,t));
    }
}
 
void solve()
{
    ans=2000000000000000000;
    int x,y,z;
    cin>>x>>y>>z;
    int r[x];
    int g[y];
    int b[z];
    for (int i=0;i<x;++i)
    {
        cin>>r[i];
    }
    for (int i=0;i<y;++i)
    {
        cin>>g[i];
    }
    for (int i=0;i<z;++i)
    {
        cin>>b[i];
    }
    sort(r,r+x);
    sort(g,g+y);
    sort(b,b+z);
    numGetter(r,g,b,x,y,z);
    numGetter(g,b,r,y,z,x);
    numGetter(b,r,g,z,x,y);
    numGetter(r,b,g,x,z,y);
    numGetter(g,r,b,y,x,z);
    numGetter(b,g,r,z,y,x);
    cout<<ans<<"\n";
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    cin>>n;
    while (n--)
    {
        solve();
    }
    return 0;
}