#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const int N = 1e5+4;
const ll INF = 1e18;
int s[N], v[N];
ll dp[N];
vector<array<int,2>> e[N];
 
ll f(int a, ll b, int x)
{
    return 1LL*a*x+b;
}
 
struct LiChao
{
    struct node
    {
        int a = 0;
        ll b = 0;
        node *l, *r;
    };
    int n;
    node *root;
    deque<node> buffer;
    vector<int> prvSz;
    vector<node*> stk1;
    vector<array<ll,2>> stk2;
    node *newnode()
    {
        buffer.emplace_back();
        return &buffer.back();
    }
    LiChao(int n) : n(n)
    {
        root = newnode();
        prvSz.push_back(0);
    }
    void update(node *&v, int l, int r, int a, ll b)
    {
        if (a==0&&b==0)
            return;
        if (!v)
            v=newnode();
        int m=l+(r-l)/2;
        if (f(a,b,m)<f(v->a,v->b,m))
        {
            swap(a,v->a);
            swap(b,v->b);
            stk1.push_back(v);
            stk2.push_back({a,b});
        }
        if (l==r)
            return;
        if (f(a,b,l)<f(v->a,v->b,l))
            update(v->l,l,m,a,b);
        else if (f(a,b,r)<f(v->a,v->b,r))
            update(v->r,m+1,r,a,b);
    }
    void update(int a, ll b)
    {
        update(root,0,n,a,b);
        prvSz.push_back(stk1.size());
    }
    ll query(node *v, int l, int r, int x)
    {
        if (!v)
            return INF;
        if (l==r)
            return f(v->a,v->b,x);
        int m=l+(r-l)/2;
        if (x<=m)
            return min(f(v->a,v->b,x),query(v->l,l,m,x));
        return min(f(v->a,v->b,x),query(v->r,m+1,r,x));
    }
    ll query(int x)
    {
        return min(query(root,0,n,x),0LL);
    }
    void rollback()
    {
        prvSz.pop_back();
        while ((int)stk1.size()>prvSz.back())
        {
            stk1.back()->a = stk2.back()[0];
            stk1.back()->b = stk2.back()[1];
            stk1.pop_back();
            stk2.pop_back();
        }
    }
};
 
LiChao lct(1e9);
 
void dfs(int c, int p, int h)
{
    dp[c]=1LL*v[c]*h+s[c]+lct.query(v[c]);
    lct.update(-h,dp[c]);
    for (auto i : e[c])
        if (i[0]!=p)
            dfs(i[0],c,h+i[1]);
    lct.rollback();
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,x,y,z;
    cin>>n;
    for (int i=1;i<n;++i)
    {
        cin>>x>>y>>z;
        e[x].push_back({y,z});
        e[y].push_back({x,z});
    }
    for (int i=2;i<=n;++i)
        cin>>s[i]>>v[i];
    dfs(1,0,0);
    for (int i=2;i<=n;++i)
        cout<<dp[i]<<" ";
    return 0;
}