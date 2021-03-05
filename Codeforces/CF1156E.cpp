#include <bits/stdc++.h>
using namespace std;

const int mn = 2e5+1;
int n,a[mn],p[mn],seg[mn<<2],ans;

void build(int i, int l, int r)
{
    if (l==r)
    {
        cin>>a[l];
        p[a[l]]=l;
        seg[i]=a[l];
        return;
    }
    build((i<<1)+1,l,(l+r)/2);
    build((i<<1)+2,(l+r)/2+1,r);
    seg[i]=max(seg[i*2+1],seg[i*2+2]);
}

int query(int i, int cL, int cR, int l, int r)
{
    if (cR<l||r<cL)
        return 0;
    if (l<=cL&&cR<=r)
        return seg[i];
    return max(query(i*2+1,cL,(cL+cR)/2,l,r),query(i*2+2,(cL+cR)/2+1,cR,l,r));
}

void calc(int l, int r, int x, int y, int z)
{
    for (int i=l;i<=r;++i)
        if (a[i]<z&&x<=p[z-a[i]]&&p[z-a[i]]<=y)
            ++ans;
}

void f(int l, int r)
{
    if (l>r)
        return;
    int mx = query(0,1,n,l,r);
    if (p[mx]-l<r-p[mx])
        calc(l,p[mx]-1,p[mx]+1,r,mx);
    else
        calc(p[mx]+1,r,l,p[mx]-1,mx);
    f(l,p[mx]-1);
    f(p[mx]+1,r);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    cin>>n;
    build(0,1,n);
    f(1,n);
    cout<<ans;
    return 0;
}