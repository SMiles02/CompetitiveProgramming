#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n,m,x;
ll s[160000][4];

void calc(int i)
{
    int l=i*2+1,r=i*2+2;
    s[i][0]=max(s[l][0]+max(s[r][0],s[r][2]),s[l][1]+s[r][0]);
    s[i][1]=max(s[l][0]+max(s[r][1],s[r][3]),s[l][1]+s[r][1]);
    s[i][2]=max(s[l][2]+max(s[r][0],s[r][2]),s[l][3]+s[r][0]);
    s[i][3]=max(s[l][2]+max(s[r][1],s[r][3]),s[l][3]+s[r][1]);
}

void build(int i, int l, int r)
{
    if (l==r)
    {
        cin>>s[i][3];
        return;
    }
    build(i*2+1,l,l+(r-l)/2);
    build(i*2+2,l+(r-l)/2+1,r);
    calc(i);
}

void update(int i, int l, int r)
{
    if (x<l||r<x)
        return;
    if (l==r)
    {
        cin>>s[i][3];
        return;
    }
    update(i*2+1,l,l+(r-l)/2);
    update(i*2+2,l+(r-l)/2+1,r);
    calc(i);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    freopen("optmilk.in", "r", stdin);
    freopen("optmilk.out", "w", stdout);
    ll ans=0;
    cin>>n>>m;
    build(0,1,n);
    while (m--)
    {
        cin>>x;
        update(0,1,n);
        ans+=max({s[0][0],s[0][1],s[0][2],s[0][3]});
    }
    cout<<ans;
    return 0;
}