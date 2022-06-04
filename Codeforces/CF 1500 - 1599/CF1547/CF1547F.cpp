#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//uniform_int_distribution<int>(1000,10000)(rng)

ll binpow(ll a, ll b)
{
    ll res = 1;
    while (b > 0)
    {
        if (b & 1)
            res = res * a;
        a = a * a;
        b >>= 1;
    }
    return res;
}

ll gcd(ll a,ll b)
{
    if (b==0) return a;
    return gcd(b,a%b);
}

string to_upper(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='a' && a[i]<='z') a[i]-='a'-'A';
    return a;
}
 
string to_lower(string a)
{
    for (int i=0;i<(int)a.size();++i) if (a[i]>='A' && a[i]<='Z') a[i]+='a'-'A';
    return a;
}

const int mn = 2e5+7;
int n, segTree[mn<<2], a[mn], g;

void build(int i, int l, int r)
{
    if (l==r)
    {
        cin>>segTree[i];
        a[l]=segTree[i];
        g=gcd(g,a[l]);
        return;
    }
    build(i*2+1,l,l+(r-l)/2);
    build(i*2+2,l+(r-l)/2+1,r);
    segTree[i]=gcd(segTree[i*2+1],segTree[i*2+2]);
}

int query(int i, int cL, int cR, int l, int r)
{
    if (r<cL||cR<l)
        return 0;
    if (l<=cL&&cR<=r)
        return segTree[i];
    return gcd(query((i<<1)+1,cL,cL+((cR-cL)>>1),l,r),query((i<<1)+2,cL+((cR-cL)>>1)+1,cR,l,r));
}

int query(int l, int r)
{
    return query(0,0,n-1,l,r);
}

void solve()
{
    g=0;
    cin>>n;
    build(0,0,n-1);
    int ans=0,l,r,m;
    for (int i=0;i<n;++i)
    {
        if (a[i]==g)
            continue;
        l=1;r=n-1;
        while (l<r)
        {
            m=l+(r-l)/2;
            if (i-m<0)
            {
                if (gcd(query(i-m+n,n-1),query(0,i))==g)
                    r=m;
                else
                    l=m+1;
            }
            else
            {
                if (query(i-m,i)==g)
                    r=m;
                else
                    l=m+1;
            }
        }
        ans=max(ans,l);
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