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

struct DSU
{
    vector<int> pt,rk,sc;
    DSU(int n) : pt(n*2+1), rk(n*2+1, 1), sc(n*2+1,0) {
        for (int i = 1; i <= n; ++i)
        {
            pt[i] = i;
            pt[i+n] = i+n;
            sc[i+n] = 1;
        }
    }
    int find(int i) {
        return i == pt[i] ? i : pt[i] = find(pt[i]);
    }
    void unite(int i, int j) {
        i = find(i);
        j = find(j);
        if (i != j) {
            if (rk[i] < rk[j])
                swap(i, j);
            pt[j] = i;
            rk[i] += rk[j];
            sc[i] += sc[j];
        }
    }
};

void solve()
{
    int n,q,x,y,ans=0;
    string s;
    cin>>n>>q;
    DSU dsu(n);
    while (q--)
    {
        cin>>x>>y>>s;
        if (s[0]=='c')
        {
            dsu.unite(x,y);
            dsu.unite(x+n,y+n);
        }
        else
        {
            dsu.unite(x,y+n);
            dsu.unite(x+n,y);
        }
    }
    for (int i=1;i<=n;++i)
        if (dsu.find(i)==dsu.find(i+n))
        {
            cout<<"-1\n";
            return;
        }
    for (int i=1;i<=n;++i)
        if (dsu.find(i)==i)
            ans+=max(dsu.sc[dsu.find(i)],dsu.sc[dsu.find(i+n)]);
    cout<<ans<<"\n";
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