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

struct BIT {
    int n,rtn;
    vector<int> bit;
    BIT(int n) : n(n), bit(n+1,0) {}
    void update(int x, int d) { for (int i=x;i<=n;i+=i&-i) bit[i]+=d; }
    int query(int x) {
        rtn=0;
        for (int i=x;i;i-=i&-i) rtn+=bit[i];
        return rtn;
    }
    int query(int x, int y) { return query(y) - query(x-1); }
};

const int N = 1e6;
string s[N];
int ct[N];
  
int main()
{
    ios_base::sync_with_stdio(0); cin.tie(0);
    int n,m,q,x,y;
    cin>>n>>m;
    for (int i=0;i<n;++i)
        cin>>s[i];
    BIT bit(m);
    for (int i=0;i+1<n;++i)
        for (int j=1;j<m;++j)
            if (s[i][j]=='X')
                if (s[i+1][j-1]=='X')
                    bit.update(j,1);
    cin>>q;
    while (q--)
    {
        cin>>x>>y;
        if ((x==y)||n==1)
            cout<<"YES\n";
        else if (bit.query(x,y-1))
            cout<<"NO\n";
        else
            cout<<"YES\n";
    }
    return 0;
}