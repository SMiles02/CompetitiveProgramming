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

const int N = 2e5+7;
vector<int> e[N];
int col[N], ct[3], dn[N], ans[N], val[N];
vector<int> v[20], g[3];

void dfs(int c, int p, int x)
{
    col[c]=x;
    ++ct[x];
    for (int i : e[c])
        if (i!=p)
            dfs(i,c,3-x);
}

int calc(int x)
{
    for (int i=20;;--i)
        if ((1<<i)&x)
            return i;
    return -1;
}

void solve()
{
    int n,x,mx=1,cur,m,A,B;
    cin>>n;
    m=n;
    ct[1]=ct[2]=0;
    g[1].clear();
    g[2].clear();
    for (int i=0;i<20;++i)
        v[i].clear();
    for (int i=1;i<=n;++i)
    {
        e[i].clear();
        col[i]=0;
        ans[i]=0;
        dn[i]=0;
        cur=val[i];
        v[cur].push_back(i);
        mx=max(mx,cur);
    }
    for (int i=1;i<n;++i)
    {
        cin>>A>>B;
        e[A].push_back(B);
        e[B].push_back(A);
    }
    dfs(1,0,1);
    if (ct[1]>ct[2])
        x=1;
    else
        x=2;
    if (__builtin_popcount(n+1)!=1)
    {
        for (int i=1;i<=n&&__builtin_popcount(m+1)!=1;++i)
            if (col[i]==x)
            {
                ans[i]=m--;
                dn[i]=1;
                ct[x]--;
            }
        mx--;
    }
    // cerr<<ct[1]<<"!\n";
    for (int i=0;i<=mx;++i)
    {
        if ((1<<i)&ct[1])
            for (int j : v[i])
                g[1].push_back(j);
        else
            for (int j : v[i])
                g[2].push_back(j);
    }
    for (int i=1;i<=n;++i)
        if (!dn[i])
        {
            ans[i]=g[col[i]].back();
            g[col[i]].pop_back();
        }
    for (int i=1;i<=n;++i)
        cout<<ans[i]<<" ";
    cout<<"\n";
    // for (int i=1;i<3;++i)
    // {
    //     cout<<i<<": ";
    //     for (int j : g[i])
    //         cout<<j<<" ";
    //     cout<<"\n";
    // }
}
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    for (int i=1;i<N;++i)
        val[i]=calc(i);
    int t;
    cin>>t;
    while (t--)
        solve();
    return 0;
}