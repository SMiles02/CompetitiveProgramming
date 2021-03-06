#include <bits/stdc++.h>
#define ll long long
using namespace std;
 
const ll INF = 1e18;

ll f(ll a, ll b, ll x)
{
    return a*x+b;
}
 
struct LiChao
{
    struct node
    {
        ll a = 0, b = INF;
        node *l, *r;
    };
    ll n;
    node *root;
    deque<node> buffer;
    node *newnode()
    {
        buffer.emplace_back();
        return &buffer.back();
    }
    LiChao(ll n) : n(n)
    {
        root = newnode();
    }
    void update(node *&v, ll l, ll r, ll a, ll b)
    {
        if (!v)
        {
            v = newnode();
            swap(a,v->a);
            swap(b,v->b);
            return;
        }
        ll m=l+(r-l)/2;
        if (f(a,b,m)<f(v->a,v->b,m))
        {
            swap(a,v->a);
            swap(b,v->b);
        }
        if (l==r)
            return;
        if (f(a,b,l)<f(v->a,v->b,l))
            update(v->l,l,m,a,b);
        else if (f(a,b,r)<f(v->a,v->b,r))
            update(v->r,m+1,r,a,b);
    }
    void update(ll a, ll b)
    {
        update(root,0,n,a,b);
    }
    ll query(node *v, ll l, ll r, ll x)
    {
        if (!v)
            return INF;
        if (l==r)
            return f(v->a,v->b,x);
        ll m=l+(r-l)/2;
        if (x<=m)
            return min(f(v->a,v->b,x),query(v->l,l,m,x));
        return min(f(v->a,v->b,x),query(v->r,m+1,r,x));
    }
    ll query(ll x)
    {
        return min(query(root,0,n,x),0LL);
    }
};

ll dp[1<<20];

int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n;
    ll C, k;
    cin>>n>>C;
    LiChao lct(1e6);
    cin>>k;
    lct.update(-2*k, k*k);
    for (int i=2;i<=n;++i)
    {
        cin>>k;
        dp[i]=C+k*k+lct.query(k);
        lct.update(-2*k, k*k + dp[i]);
    }
    cout<<dp[n];
    return 0;
}