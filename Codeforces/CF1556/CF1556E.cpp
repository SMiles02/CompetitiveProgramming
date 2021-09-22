#include <bits/stdc++.h>
#define ll long long
using namespace std;

const int N = 1e5+7, S = 4;
int a[N], b[N];
vector<array<ll,S>> s(N*4);
array<ll,4> cur;

/**

0 ++
1 --
2 +-
3 -+

**/

array<ll,S> merge(array<ll,S> l, array<ll,S> r)
{
    array<ll,S> a = l;
    a[2]+=max(0LL,r[2]-l[2]);
    r[2]=0;
    l[2]=max(0LL,l[2]-r[2]);
    ll x=min(l[0],r[1]);
    a[0]-=x;
    r[1]-=x;
    a[2]+=x;
    r[3]-=min(a[0],r[3]);
    x=min(a[2],r[0]);
    a[2]-=x;
    r[0]-=x;
    a[0]+=x;
    for (int i=0;i<4;++i)
        a[i]+=r[i];
    return a;
}

void build(int i, int l, int r)
{
    if (l==r)
    {
        for (int j=0;j<4;++j)
            s[i][j]=0;
        if (a[l]>b[l])
            s[i][1]=a[l]-b[l];
        else
            s[i][0]=b[l]-a[l];
        return;
    }
    int x=i*2+1,y=i*2+2;
    build(x,l,l+(r-l)/2);
    build(y,l+(r-l)/2+1,r);
    s[i]=merge(s[x],s[y]);
}

void query(int i, int l, int r, int qL, int qR)
{
    if (r<qL||qR<l)
        return;
    if (qL<=l&&r<=qR)
    {
        cur=merge(cur,s[i]);
        return;
    }
    int m=l+(r-l)/2;
    query(i*2+1,l,m,qL,qR);
    query(i*2+2,m+1,r,qL,qR);
}
  
signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,l,r;
    cin>>n>>q;
    for (int i=1;i<=n;++i)
        cin>>a[i];
    for (int i=1;i<=n;++i)
        cin>>b[i];
    build(0,1,n);
    while (q--)
    {
        cin>>l>>r;
        for (int i=0;i<4;++i)
            cur[i]=0;
        query(0,1,n,l,r);
        if (cur[0]||cur[1]||cur[3])
            cout<<"-1\n";
        else
            cout<<cur[2]<<"\n";
    }
    return 0;
}