#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;

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
        update(root, 1, n, i, x);
    }
    int find(node* v, int l, int r, int x) {
        if (r<x||!v||v->val==0)
            return 0;
        if (l==r)
        {
            if (l<=x)
                return l;
            return 0;
        }
        k=find(v->l,l,l+(r-l)/2,x);
        if (k==0)
            k=find(v->r,l+(r-l)/2+1,r,x); 
        return k;
    }
    int find(int l) {
        return find(root,1,n,l);
    }
};

void solve()
{
    int n,m;
    cin>>n>>m;
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