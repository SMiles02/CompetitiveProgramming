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

struct implicit {
    struct node {
        int val = 0;
        node *l, *r;
    };
    deque<node> buffer;
    node *newnode() {
        buffer.emplace_back();
        return &buffer.back();
    }
    int n;
    node *root;
    implicit(int n) : n(n) {root = newnode();}
    void update(node *&v, int l, int r, int i, int x) {
        if (i<l||r<i)
            return;
        if (!v) 
            v=newnode();
        v->val+=x;
        if (l==r)
            return;
        update(v->l,l,(l+r)>>1,i,x);
        update(v->r,(l+r+2)>>1,r,i,x);
    }
    void update(int i, int x) {
        update(root, 0, n, i, x);
    }
    int query(node* v, int cL, int cR, int l, int r) {
        if (r<cL||cR<l||!v)
            return 0;
        if (l<=cL&&cR<=r)
            return v->val;
        return query(v->l,cL,(cL+cR)>>1,l,r) + query(v->r,(cL+cR+2)>>1,cR,l,r);
    }
    int query(int l, int r) {
        return query(root,0,n,l,r);
    }
};
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int h,w,n;
    cin>>h>>w>>n;
    implicit s1(1e9), s2(1e9);
    int a[n][2];
    for (int i=0;i<n;++i)
    {
        cin>>a[i][0]>>a[i][1];
        if (s1.query(a[i][0],a[i][0])==0)
            s1.update(a[i][0],1);
        if (s2.query(a[i][1],a[i][1])==0)
            s2.update(a[i][1],1);
    }
    for (int i=0;i<n;++i)
    {
        a[i][0]-=(a[i][0]-s1.query(0,a[i][0]));
        a[i][1]-=(a[i][1]-s2.query(0,a[i][1]));
        cout<<a[i][0]<<" "<<a[i][1]<<"\n";
    }
    return 0;
}