#include <bits/stdc++.h>
#define ll long long
using namespace std;

struct node
{
    int val;
    node *l,*r;
    node(node *L, node *R)
    {
        l=L;
        r=R;
        val = l->val + r->val;
    }
    node(int x)
    {
        l=r=0;
        val = x;
    }
};

node* build(int l, int r)
{
    if (l==r)
        return new node(0);
    return new node(build(l,l+((r-l)>>1)),build(l+((r-l)>>1)+1,r));
}

node* update(node* nd, int l, int r, int i)
{
    if (i<l||r<i)
        return nd;
    if (l==r)
        return new node(nd->val+1);
    return new node(update(nd->l,l,l+((r-l)>>1),i),update(nd->r,l+((r-l)>>1)+1,r,i));
}

int query(node* nd, int cL, int cR, int i)
{
    if (cR<=i)
        return 0;
    if (i<cL)
        return nd->val;
    return query(nd->l,cL,cL+((cR-cL)>>1),i) + query(nd->r,cL+((cR-cL)>>1)+1,cR,i);
}

const int mn = 1e5+1;
int a[mn],x,tin[mn],tout[mn],t;
node* roots[mn];
vector<int> edges[mn];

void dfs(int c)
{
    tin[c]=++t;
    roots[t]=update(roots[t-1],0,x,a[c]);
    for (int i : edges[c])
        dfs(i);
    tout[c]=t;
}

int main()
{
	ios_base::sync_with_stdio(0); cin.tie(0);
	freopen("promote.in", "r", stdin);
    freopen("promote.out", "w", stdout);
    int n;
    cin>>n;
    set<int> s;
    map<int,int> m;
    for (int i=1;i<=n;++i)
    {
        cin>>a[i];
        s.insert(a[i]);
    }
    for (int i=2;i<=n;++i)
    {
        cin>>x;
        edges[x].push_back(i);
    }
    x=0;
    for (int i : s)
        m[i]=x++;
    for (int i=1;i<=n;++i)
        a[i]=m[a[i]];
    roots[0]=build(0,x);
    dfs(1);
    for (int i=1;i<=n;++i)
        cout<<query(roots[tout[i]],0,x,a[i])-query(roots[tin[i]-1],0,x,a[i])<<"\n";
	return 0;
}