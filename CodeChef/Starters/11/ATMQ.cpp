//#pragma GCC optimize("Ofast,unroll-loops")
//#pragma GCC target("avx,avx2,sse,sse2")
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

struct segtree
{
    const ll MN_VAL = -1e18;
    int n;
    vector<ll> v;
    segtree(int n) : n(n), v(n*4+20, MN_VAL) {}
    void update(int i, int l, int r, int j, ll x)
    {
        if (j<l||r<j)
            return;
        if (l==r)
        {
            v[i]=x;
            return;
        }
        int m=l+(r-l)/2;
        if (j<=m)
            update(i*2+1,l,m,j,x);
        else
            update(i*2+2,m+1,r,j,x);
        v[i]=max(v[i*2+1],v[i*2+2]);
    }
    void update(int i, ll x)
    {
        update(0,0,n,i,x);
    }
    ll query(int i, int l, int r, int qL, int qR)
    {
        if (r<qL||qR<l)
            return MN_VAL;
        if (qL<=l&&r<=qR)
            return v[i];
        int m=l+(r-l)/2;
        return max(query(i*2+1,l,m,qL,qR),query(i*2+2,m+1,r,qL,qR));
    }
    ll query(int l, int r)
    {
        if (l>r)
            return MN_VAL;
        return query(0,0,n,l,r);
    }
};

struct BIT {
    int n,rtn;
    vector<int> bit;
    BIT(int n) : n(n), bit(n+1,0) {}
    void update(int x, int d) {
        for (int i=x;i<=n;i+=i&-i)
            bit[i]+=d;
    }
    int query(int x) {
        rtn=0;
        for (int i=x;i;i-=i&-i)
            rtn+=bit[i];
        return rtn;
    }
    int query(int x, int y) {
        return query(y) - query(x-1);
    }
};

void solve()
{
    int n,l,r,m,cur=1,x;
    cin>>n;
    int a[n+1],ans[n+1];
    segtree seg(n);
    BIT bit(n);
    cerr<<"New case\n";
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        seg.update(i,a[i]);
    }
    ans[1]=1;
    for (int i=2;i<=n;++i)
        if (a[i])
        {
            x=i;
            vector<int> v;
            while (1)
            {
                cerr<<x<<" ";
                v.push_back(x);
                if (seg.query(x,n)==a[x])
                    break;
                l=x;r=n;
                while (l<r)
                {
                    m=l+(r-l)/2;
                    if (seg.query(x,m)==a[x])
                        l=m+1;
                    else
                        r=m;
                }
                if (l-x-bit.query(x,l)-cur>0)
                    break;
                x=l;
            }
            while (!v.empty())
            {
                bit.update(v.back(),1);
                ans[v.back()]=++cur;
                a[v.back()]=0;
                v.pop_back();
            }
            cerr<<"\n";
        }
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    cout<<"\n";
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