#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
#define int ll
using namespace std;

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

struct implicit {
    struct node {
        ll val = 0;
        node *l, *r;
    };
    deque<node> buffer;
    node *newnode() {
        buffer.emplace_back();
        return &buffer.back();
    }
    ll n;
    node *root;
    implicit(ll n) : n(n) {root = newnode();}
    void update(node *&v, ll l, ll r, ll i, int x) {
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
    void update(ll i, int x) {
        update(root, 0, n, i, x);
    }
    int query(node* v, ll cL, ll cR, ll l, ll r) {
        if (r<cL||cR<l||!v)
            return 0;
        if (l<=cL&&cR<=r)
            return v->val;
        return query(v->l,cL,(cL+cR)>>1,l,r) + query(v->r,(cL+cR+2)>>1,cR,l,r);
    }
    int query(ll l, ll r) {
        return query(root,0,n,l,r);
    }
};

signed main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,t,L,R,X;
    ll l,r,m;
    cin>>n>>q;
    int a[n];
    for (int i=0;i<n;++i)
        cin>>a[i];
    ll s = 3*binpow(10,14);
    implicit seg(s);
    while (q--)
    {
        cin>>t;
        if (t==1)
        {
            cin>>L>>R;
            --L;
            --R;
            l=L;r=s;
            while (l<r)
            {
                m=l+(r-l)/2;
                if (m-seg.query(0,m)<L)
                    l=m+1;
                else
                    r=m;
            }
            //cout<<"update "<<l<<" with "<<R-L+1<<"\n";
            seg.update(l,R-L+1);
        }
        else
        {
            cin>>X;
            --X;
            l=X;r=s;
            while (l<r)
            {
                m=l+(r-l)/2;
                if (m-seg.query(0,m)<X)
                    l=m+1;
                else
                    r=m;
            }
            //cout<<l<<": ";
            //cout<<seg.query(0,l)<<"\n";
            cout<<a[l%n]<<"\n";
        }
    }
    return 0;
}