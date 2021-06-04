#include <bits/stdc++.h>
using namespace std;

const int N = 35001, K = 101, INF = 1e9;
int dp[K][N], f[N], best, j, cur, layer;

struct pst
{
    struct node
    {
        node *l, *r;
        int val;
        node(int x) : val(x) {}
    };
    deque<node> buffer;
    node *newnode(int x = 0)
    {
        buffer.emplace_back(x);
        return &buffer.back();
    }
    node *merge(node *l, node *r)
    {
        auto x = newnode(l->val+r->val);
        x->l=l;
        x->r=r;
        return x;
    }
    int n, k = 0;
    node* root[N];
    pst(int n) : n(n) {root[0] = build(1,n);}
    node* build(int l, int r)
    {
        if (l==r)
            return newnode();
        return merge(build(l,l+(r-l)/2),build(l+(r-l)/2+1,r));
    }
    void clone()
    {
        root[k+1] = merge(root[k]->l, root[k]->r);
        ++k;
    }
    node *update(node *v, int l, int r, int x, int y)
    {
        if (x<l||r<x)
            return v;
        if (l==r)
            return newnode(y);
        return merge(update(v->l,l,l+(r-l)/2,x,y),update(v->r,l+(r-l)/2+1,r,x,y));
    }
    void update(int x, int y)
    {
        root[k]=update(root[k],1,n,x,y);
    }
    int query(node *v, int l, int r, int qL, int qR)
    {
        if (r<qL||qR<l)
            return 0;
        if (qL<=l&&r<=qR)
            return v->val;
        return query(v->l,l,l+(r-l)/2,qL,qR) + query(v->r,l+(r-l)/2+1,r,qL,qR);
    }
    int query(int l, int r)
    {
        return query(root[r],1,n,l,r);
    }
    void walk(node *v, int l, int r, int l1, int l2, int qR)
    {
        if (qR<l||r<l1)
            return;
        if (l2<l&&r<=qR)
        {
            cur+=v->val;
            return;
        }
        if (l==r)
        {
            cur+=v->val;
            if (dp[layer-1][l-1]+cur<=best)
            {
                best=dp[layer-1][l-1]+cur;
                j=l;
            }
            return;
        }
        walk(v->r,l+(r-l)/2+1,r,l1,l2,qR);
        walk(v->l,l,l+(r-l)/2,l1,l2,qR);
    }
    void walk(int l1, int l2, int r)
    {
        walk(root[r],1,n,l1,l2,r);
    }
};

pst seg(N);

void solve(int l, int r, int optL, int optR)
{
    if (l>r)
        return;
    int m=l+(r-l)/2, split;
    best = INF;
    j=-1;
    cur=0;
    seg.walk(optL,min(optR,m),m);
    split=j;
    dp[layer][m]=best;
    solve(l,m-1,optL,split);
    solve(m+1,r,split,optR);
}

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,k;
    cin>>n>>k;
    int a[n+1];
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        seg.clone();
        if (f[a[i]])
            seg.update(f[a[i]],i-f[a[i]]);
        f[a[i]]=i;
    }
    for (int i=1;i<=n;++i)
        dp[1][i]=seg.query(1,i);
    for (layer=2;layer<=k;++layer)
        solve(1,n,1,n);
    cout<<dp[k][n];
    return 0;
}