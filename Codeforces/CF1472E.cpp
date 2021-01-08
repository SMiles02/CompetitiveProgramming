#include <bits/stdc++.h>
#define ll long long
#define sz(x) (int)(x).size()
using namespace std;
 
const int INF = 1e9+7;
ll g,h;

struct node
{
    node *l, *r;
    int val;
    node(int k) : l(nullptr), r(nullptr), val(k) {}
    node(node *l1, node *r1) : l(l1), r(r1)
    {
        val=min(l->val,r->val);
    }
};
 
node* build(int cL, int cR)
{
    if (cL==cR)
        return new node(INF);
    int cM = cL + ((cR-cL)>>1);
    return new node(build(cL,cM),build(cM+1,cR));
}
 
/**node* update(node* nd, int cL, int cR, int x1, int x2, int y1, int a, int b, int y2)
{
    if (cR<=x1)
        return new node(nd->a,nd->b+y1,nd->l,nd->r);
    if (x2<cL)
        return new node(nd->a,nd->b+y2,nd->l,nd->r);
    if (x1<cL&&cR<=x2)
        return new node(nd->a+a,nd->b+b,nd->l,nd->r);
    int cM = cL + ((cR-cL)>>1);
    return new node(nd->a,nd->b,update(nd->l,cL,cM,x1,x2,y1,a,b,y2),update(nd->r,cM+1,cR,x1,x2,y1,a,b,y2));
}**/

void updateNotP(node* nd, int cL, int cR, int tg, int x)
{
    if (tg<cL||cR<tg)
        return;
    if (cL==cR)
    {
        nd->val=min(nd->val,x);
        return;
    }
    int cM = cL + ((cR-cL)>>1);
    updateNotP(nd->l,cL,cM,tg,x);
    updateNotP(nd->r,cM+1,cR,tg,x);
    nd->val=min(nd->l->val,nd->r->val);
}
 
int query(node* nd, int cL, int cR, int tg)
{
    if (tg<=cL)
        return INF;
    if (cR<tg)
        return nd->val;
    int cM = cL + ((cR - cL)>>1);
    return min(query(nd->l,cL,cM,tg),query(nd->r,cM+1,cR,tg));
}
 
node* roots[75001];

void solve()
{
    int n,t=0;
    cin>>n;
    array<int,3> a[n];
    int ans[n+1];
    set<int> s;
    map<int,int> m;
    for (int i=0;i<n;++i)
    {
        cin>>a[i][0]>>a[i][1];
        a[i][2]=i+1;
        ans[i+1]=INF;
        s.insert(a[i][0]);
        s.insert(a[i][1]);
    }
    for (int i : s)
    {
        m[i]=++t;
        cout<<i<<": "<<t<<"\n";
    }
    cout<<"\n";
    t=sz(s)+5;
    roots[0]=build(0,t);
    node* regular = build(0,t);
    sort(a,a+n);
    for (int i=0;i<n;++i)
    {
        cout<<a[i][0]<<" "<<a[i][1]<<"\n";
        ans[a[i][2]]=min(ans[a[i][2]],query(regular,0,t,m[a[i][1]]));
        updateNotP(regular,0,t,m[a[i][1]],a[i][2]);
    }
    for (int i=1;i<=n;++i)
        cout<<i<<": "<<ans[i]<<"\n";
}
 
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int tc;
    cin>>tc;
    while (tc--)
        solve();
    return 0;
}