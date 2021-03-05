#include <bits/stdc++.h>
#define sz(x) (int)(x).size()
using namespace std;

const int mn = 1e5+1;
int n,a[mn],seg[mn<<2];
map<int,set<int>> m;
set<int> ans;

void build(int i, int l, int r)
{
    if (l==r)
    {
        cin>>a[l];
        seg[i]=a[l];
        m[a[l]].insert(l);
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

void calc(int l, int r, int x)
{
    if (l>r)
        return;
    if (l==r)
    {
        ans.insert(a[x]-a[l]);
        return;
    }
    int mx=query(0,1,n,l,r),k;
    ans.insert(a[x]-mx);
    if (x<l)
    {
        k=*(m[mx].lower_bound(x+1));
        calc(x+1,k-1,x);
    }
    else
    {
        k=*(--m[mx].lower_bound(x));
        calc(k+1,x-1,x);
    }
}

void f(int l, int r)
{
    if (l>=r)
        return;
    cout<<l<<" "<<r<<"\n";
    int mx = query(0,1,n,l,r);
    vector<int> v;
    for (int i=l;i<=r;++i)
        if (a[i]==mx)
            v.push_back(i);
    calc(l,v[0]-1,v[0]);
    calc(v.back()+1,r,v.back());
    f(l,v[0]-1);
    f(v.back()+1,r);
    for (int i=0;i+1<sz(v);++i)
    {
        calc(v[i]+1,v[i+1]-1,v[i]);
        calc(v[i]+1,v[i+1]-1,v[i+1]);
        f(v[i]+1,v[i+1]-1);
    }
}

void solve()
{
    cin>>n;
    ans.clear();
    m.clear();
    build(0,1,n);
    f(1,n);
    cout<<sz(ans)<<"\n";
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}