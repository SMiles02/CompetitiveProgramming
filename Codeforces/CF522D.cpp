#include <bits/stdc++.h>
using namespace std;

const int INF = 1<<20;

struct pst
{
    struct node
    {
        int x;
        node *l, *r;
        node(int y) : x(y) {}
    };
    deque<node> buffer;
    node *newnode(int x = INF)
    {
        buffer.emplace_back(x);
        return &buffer.back();
    }
    node *merge(node *l, node *r)
    {
        auto x = newnode(min(l->x, r->x));
        x->l = l;
        x->r = r;
        return x;
    }
    int n, k = 0;
    node *root[500005];
    pst(int n) : n(n) {root[0]=build(1,n);}
    node *build(int l, int r)
    {
        if (l==r)
            return newnode();
        return merge(build(l, l+(r-l)/2), build(l+(r-l)/2+1, r));
    }
    void clone()
    {
        root[k+1] = merge(root[k]->l, root[k]->r);
        ++k;
    }
    node *update(node *v, int l, int r, int i, int x)
    {
        if (r<i||i<l)
            return v;
        if (l==r)
            return newnode(x);
        return merge(update(v->l, l, l+(r-l)/2, i, x), update(v-> r, l+(r-l)/2+1, r, i, x));
    }
    void update(int i, int x)
    {
        root[k] = update(root[k], 1, n, i, x);
    }
    int query(node *v, int l, int r, int qL, int qR)
    {
        if (qR<l||r<qL)
            return INF;
        if (qL<=l&&r<=qR)
            return v->x;
        return min(query(v->l, l, l+(r-l)/2, qL, qR), query(v->r, l+(r-l)/2+1, r, qL, qR));
    }
    int query(int l, int r)
    {
        return query(root[r], 1, n, l, r);
    }
};

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,q,x,y,k;
    cin>>n>>q;
    if (n==1)
    {
        while (q--)
            cout<<"-1\n";
        return 0;
    }
    map<int,int> m;
    vector<array<int,2>> v = {{0,0}};
    for (int i=1;i<=n;++i)
    {
        cin>>k;
        if (m[k])
            v.push_back({i,m[k]});
        m[k]=i;
    }
    pst seg(n);
    sort(v.begin(), v.end());
    for (int i=1;i<(int)v.size();++i)
    {
        for (int j=v[i-1][0]+1;j<=v[i][0];++j)
            seg.clone();
        seg.update(v[i][1], v[i][0] - v[i][1]);
    }
    for (int i=v.back()[0]+1;i<=n;++i)
        seg.clone();
    while (q--)
    {
        cin>>x>>y;
        k=seg.query(x,y);
        if (k==INF)
            k=-1;
        cout<<k<<"\n";
    }
    return 0;
}